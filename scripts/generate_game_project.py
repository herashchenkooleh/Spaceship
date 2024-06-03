import os
import subprocess
import platform
import tempfile
import shutil

def get_freetype_path(file_path, pattern):
    with open(file_path,'r') as file:
        for line in file:
            if line.startswith(pattern):
                return line.replace(pattern, '')
    return ''

def replace(file_path, pattern, subst):
    fh, abs_path = tempfile.mkstemp()
    with os.fdopen(fh,'w') as new_file:
        with open(file_path) as old_file:
            for line in old_file:
                if line.startswith(pattern):
                    new_file.write(pattern + subst)
                else:
                    new_file.write(line)

    shutil.copymode(file_path, abs_path)
    os.remove(file_path)
    shutil.move(abs_path, file_path)

current_path = os.path.abspath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
build_dir_path = os.path.abspath(os.path.join(current_path, '..', 'builds/SpaceShip'))
games_dir_path = os.path.abspath(os.path.join(current_path, '..', 'games/SpaceShip'))

current_platform = platform.system()

if current_platform == "Darwin":
    subprocess.call(['cmake', '-B' + build_dir_path, '-S' + games_dir_path, '-G', 'Unix Makefiles', '--fresh'])
else:
    subprocess.call(['cmake', '-B' + build_dir_path, '-S' + games_dir_path, '--fresh'])

cache_file = os.path.join(build_dir_path, 'CMakeCache.txt')
ft2build_pattern = 'FREETYPE_INCLUDE_DIR_ft2build:PATH='
freetype_pattern = 'FREETYPE_INCLUDE_DIR_freetype2:PATH='
replace(cache_file, ft2build_pattern, get_freetype_path(cache_file, freetype_pattern))
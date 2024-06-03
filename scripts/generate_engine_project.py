import os
import subprocess
import platform

current_path = os.path.abspath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
build_dir_path = os.path.abspath(os.path.join(current_path, '..', 'builds/engine'))
engine_dir_path = os.path.abspath(os.path.join(current_path, '..', 'engine'))

current_platform = platform.system()

if current_platform == "Darwin":
    subprocess.call(['cmake', '-B' + build_dir_path, '-S' + engine_dir_path, '-G', 'Unix Makefiles', '--fresh'])
else:
    subprocess.call(['cmake', '-B' + build_dir_path, '-S' + engine_dir_path, '--fresh'])
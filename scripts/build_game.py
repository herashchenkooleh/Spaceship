import os
import subprocess

current_path = os.path.abspath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
build_dir_path = os.path.abspath(os.path.join(current_path, '..', 'build'))
binaries_dir_path = os.path.abspath(os.path.join(current_path, '..', 'bin'))

subprocess.call(['cmake', '--build', build_dir_path, '--config', 'Release'])
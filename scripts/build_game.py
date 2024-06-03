import os
import subprocess

current_path = os.path.abspath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
build_dir_path = os.path.abspath(os.path.join(current_path, '..', 'builds/games/SpaceShip'))
binaries_dir_path = os.path.abspath(os.path.join(current_path, '..', 'bin'))

subprocess.call(['cmake', '--build', build_dir_path, '--config', 'Release'])
subprocess.call(['cmake', '--install', build_dir_path, '--prefix', binaries_dir_path])
from setuptools import setup, find_packages

def read_file(fpath):
  with open(fpath) as fp:
    data = fp.read()
  return data

setup(
  name = 'ag',
  version = '0.0.1',
  author = 'Radhamadahb Dalai',
  author_email = 'dalai115@gmail.com',
  maintainer = 'RMD',
  url = 'https://github.com/rocky115/DeepBlueSea',
  python_requires = '3.7',
  install_requires = read_file('requirements.txt').split('\n'),
  description = 'A deep learning framework created from scratch with Python and NumPy',
  license = 'GPL-3.0',
  keywords = 'automatic-differentiation  autograd neural-networks  pytorch-api',
  packages = find_packages(),
  long_description = read_file('README.md'),
  long_description_content_type='text/markdown'
)

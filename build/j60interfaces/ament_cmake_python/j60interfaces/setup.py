from setuptools import find_packages
from setuptools import setup

setup(
    name='j60interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('j60interfaces', 'j60interfaces.*')),
)

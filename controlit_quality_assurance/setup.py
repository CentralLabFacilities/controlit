from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
     packages=['controlit_quality_assurance'],
     scripts=[],
     package_dir={'': 'src'}
)

setup(**d)


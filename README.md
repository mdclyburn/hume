# Hume
Hume is an object-oriented wrapper for a lot of facilities that SDL2 provides.
It is designed to be easy to learn and simple to use.

[![Build Status](https://build.mardev.net/buildStatus/icon?job=Hume)](https://build.mardev.net/job/Hume/)

# Building the Library

## Requirements
You'll need the following:

* SDL2
* SDL2_image
* SDL2_mixer
* SDL2_ttf

## CMake
This method requires CMake to be installed.
Run the following commands:

1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`

# Documentation

Documentation for Hume is maintained within the repository. Up-to-date documentation
may be found in the `docs` branch. To generate the documentation, you will need:

* `doxygen`
* `pdflatex`

Doxygen is needed to extract documentation from the source, and `pdflatex` is needed
to output the LaTeX that Doxygen generates into a PDF file. Of course, Doxygen can
also be directed to output different formats as well.

# License
The source code for this project is licensed under the LGPL v2.1.
See the license file, entitled 'LICENSE', for the full text.

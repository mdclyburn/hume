# Project Hume

[![Build Status](http://ci.mardev.net/buildStatus/icon?job=Hume)](http://ci.mardev.net/job/Hume/)

This project is an endeavor into creating a useful C++ interface for SDL2.
This includes the mixer, image, and TTF libraries as well.

# Building the Library
There is a makefile included for the project.
A successful make should result in an archive dubbed `libhume.a` in the top level of the repository.
Some things you might want to consider:

# Building With the Library
It will still be necessary to link with the SDL libraries:
* libSDL2
* libSDL2_image
* libSDL2_mixer
* libSDL2_ttf

Beside that, ensure that the `libhume.a` archive is being compiled in as well.

If one were to compile a program using Hume, one would execute the following command:

`g++ myHumeApplication.cpp libhume.a -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer`

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

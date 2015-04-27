Project Hume
============

[![Build Status](http://ci.mardev.net/buildStatus/icon?job=Hume)](http://ci.mardev.net/job/Hume/)

This project is an endeavor into creating a useful C++ interface for SDL2.
This includes the mixer, image, and TTF extensions as well.

Building
--------
You should have no problem building the project.
A successful make should result in a static library dubbed `libhume.a` in the top level of the repository.
Some things you might want to consider:

* you'll need to use the C++11 standard
* getting SDL2 if you don't already (you'll need to link with it at link-time)

License
-------
This project is closed-source for the time being.

ghost_lisp
==========

A home-made lisp dialect.

philosophy
=====
This is more about making transparent primitives (heh, 'ghost' 'tranparent'...get it?...I'll just see myself out now.) than trying to make a better lisp.  sbcl or scheme are already in existence.  This is just a project for lisp hackers and people who want to poke stuff to learn.

requirements
=====
The released version works with only standard C headers.  I would suggest running it as an inferior-lisp in emacs, but that's up to you.

also, you'll need mpc.c and mpc.h from https://github.com/orangeduck/mpc.  I've added the needed files into this repo for the sake of simplicity, but all credit for the mpc files are Daniel Holden's (c). BSD 2013

license
=====
Due to the inspiration and guidance from buildyourownlisp.com, this is released under a Simplified BSD license. Copyright (c) 2014, Joe Brock.

how to build
=====
Clone files, cd to dir, use 'make all', run binary, profit.  If you'd like to help with expanding the functionality of ghostlisp, then review the comments at the top of unstable.c and use 'make debug' to compile with unstable.c.  As unstable is found to work correctly and has been tested, then changes will be merged into the stable file, and new problems are to be tackled in unstable.

ghost_lisp
==========

A home-made lisp dialect.

philosophy
=====
This is more about making transparent primitives (heh, 'ghost' 'tranparent'...get it?...I'll just see myself out now.) than trying to make a better lisp.  sbcl or scheme are already in existence.  This is just a project for lisp hackers and people who want to poke stuff to learn.

requirements
=====
During development, I'm using Debian's editline from libedit-dev...the released version works with only standard C headers.  I would suggest running it as an inferior-lisp in emacs, but that's up to you.

also, you'll need mpc.c and mpc.h from https://github.com/orangeduck/mpc.  Nice libs there, holmes!  I've added the needed files into this repo for the sake of simplicity, but all credit for the mpc files are Daniel Holden's (c). BSD 2013

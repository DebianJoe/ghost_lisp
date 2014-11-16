all:
	cc -std=c99 -Wall ghostlisp.c mpc.c -lm -o ghostlisp

debug:
	cc -std=c99 -Wall unstable.c mpc.c -lm -o ghostlisp

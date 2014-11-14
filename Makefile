all:
	cc -std=c99 -Wall ghostlisp.c mpc.c -lm -o ghostlisp

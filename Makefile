all:
	cc -std=c99 -Wall ghostlisp.c mpc.c -ledit -lm -o ghostlisp

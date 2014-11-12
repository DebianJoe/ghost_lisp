#include <stdio.h>
#include <stdlib.h>
#include "mpc.h" /* link to mpc parser */

/* If we are compiling on Windows compile these functions */
/* allow the preprocessor to do it's thing */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else

/* these do not perfectly suit my needs. */
/* so, let's make new editline headers later. */
#include <editline/readline.h>
#include <editline/history.h>
#endif

/* Use operatory string to see which operation to do */
long eval_op(long x, char* op, long y) {
    if (strcmp(op, "+") == 0) { return x + y; }
    if (strcmp(op, "-") == 0) { return x - y; }
    if (strcmp(op, "*") == 0) { return x * y; }
    if (strcmp(op, "/") == 0) { return x / y; }
    if (strcmp(op, "%") == 0) { return x % y; }
    return 0;
}

long eval(mpc_ast_t* t) {
    /* if tagged as number, return it directly */
    if(strstr(t->tag, "number")) {
	return atoi(t->contents);
    }

    /* the operator is always the second child */
    char* op = t->children[1]->contents;

    /* We store the third child in 'x' */
    long x = eval(t->children[2]);

    /* Iterate the remaining children and combining */
    int i = 3;
    while (strstr(t->children[i]->tag, "expr")) {
	x = eval_op(x, op, eval(t->children[i]));
	i++;
    }

    return x;
}

int main(int argc, char** argv) {

    /* Create Some Parsers */
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr =mpc_new("expr");
    mpc_parser_t* Lispy =mpc_new("lispy");

    /* Define them with the following */
    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                     \
      number   : /-?[0-9]+/ ;                             \
      operator : '+' | '-' | '*' | '/' | '%' ;            \
      expr     : <number> | '(' <operator> <expr>+ ')' ;  \
      lispy    : /^/ <operator> <expr>+ /$/ ;             \
    ",
    Number, Operator, Expr, Lispy);

/* Print Version and Exit Information */
    puts("\n\nGhost Lisp v. 0.0.0.0.1  .-.");
    puts("...hold me, I'm scared  (o o)");
    puts("                        | O \\ ");
    puts("                        \\    \\ ");
    puts("Press C^c to exit        `~~~'\n");

    /* Infinity loops! */
    while (1) {

	/* Our Prompt */
	char* input = readline("sp00ky> ");

	/* Add input to history */
	add_history(input);

	/* Attempt to parse user input */
	mpc_result_t r;
	if (mpc_parse("<stdin>", input, Lispy, &r)) {
	    /* On success print and delete the AST */
	    long result = eval(r.output);
	    printf("%li\n", result);
	    mpc_ast_delete(r.output);
	} else {
	    /*Otherwise, bitch at user */
	    mpc_err_print(r.error);
	    mpc_err_delete(r.error);
	}
	
	/* Free memory used in input */
	free(input);
	
    }

    mpc_cleanup(4, Number, Operator, Expr, Lispy);

    return 0;
}

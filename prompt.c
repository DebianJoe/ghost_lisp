#include <stdio.h>
#include <stdlib.h>

/* these do not perfectly suit my needs. */
/* so, let's make new editline headers later. */

#include <editline/readline.h>
#include <editline/history.h>

/* Declare a buffer for user input of size 2048 chars */
/* static char input[2048]; Deprecated by readline */

int main(int argc, char** argv) {

    /* Print Version and Exit Information */
    puts("Ghost Lisp v. 0.0.0.0.1");
    puts("Press C^c to exit\n");

    /* Infinity loops! */
    while (1) {

	/* Our Prompt */
	char* input = readline("sp00ky> ");

	/* Add input to history */
	add_history(input);
	
	/* Echo user input back */
	printf("No, you're a %s\n", input);

	/* Free memory used in input */
	free(input);
	
    }

    return 0;
}

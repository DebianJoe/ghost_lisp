#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char** argv) {

    /* Print Version and Exit Information */
    puts("Ghost Lisp v. 0.0.0.0.1");
    puts("...hold me, I'm scared\n");
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

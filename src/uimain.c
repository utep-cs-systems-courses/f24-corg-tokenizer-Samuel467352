#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
int main()
{
  while(1){
    fputs("$", stdout);
    char input[100];
    fgets(input, sizeof(input), stdin);
    /*put if statement testing for null if neccessary*/
    char *endCheck = input;
    if (*endCheck == '!') {
      if (*(endCheck+1) == '8') {
	if (*(endCheck+2) == '9') {
	  goto cease;
	}
      }
    }
    char *histCheck = input;
    if (*histCheck == 'h') {
      if (*(histCheck+1) == 'i') {
	if(*(histCheck+2) == 's') {
	  if (*(histCheck+3) == 't') {
	  print_history();
	}
      }
      }
    }
    char **tokens = tokenize(input);
    print_tokens(tokens);
    add_history(input);
    //free_tokens(tokens);
    //printf("%s", get_history(5));    
  }

 cease:
  printf("bye\n");
  free_history();
  return 0;
}

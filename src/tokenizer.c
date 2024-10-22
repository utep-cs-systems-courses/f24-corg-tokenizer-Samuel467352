#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/*Return non-zero if c is a whitespace character ('\t' or ' ').
  Zero terminators are not printable*/
int space_char(char c){
  if (c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

/* Return non-zero if c is a non-whitespace character.
   Zero terminators are not printable (therfore false) */
int non_space_char(char c){
  if (space_char(c) == 0){
      return 1;
    }
  return 0;
}

/*Returns a pointer to the first character of the next non-space
 character in zero terminated str. Return a zero if str does not
  contain any tokens. */
char *token_start(char *str){
  char *p = str;
  if(*p == '\0'){
    return '\0';
  }
  while(space_char(*p) == 1){
    p++;
  }
  return p;
}

char *token_terminator(char *token){
  char *p = token;
  if(*p == '\0'){
    return '\0';
  }
  while(non_space_char(*p) == 1 && *p != '\0'){
    p++;
  }
  return p;
}

int count_tokens(char *str){
  int count = 0;
  char *s = token_start(str);
  char *e = token_terminator(s);
  while(*e != '\0'){
    count++;
    s = token_start(e);
    e = token_terminator(s);
  }
  return count+1;
}

char *copy_str(char *inStr, short len){
  char *p = malloc(sizeof(char)*(len+1));
  char *b;
  b = p;
  while (*(b++) = *(inStr++))
    ;
  return p;
}

char **tokenize(char* str){
  char ** tokVec; //pointer to a pointer to char (reference to where typ is in memory)
  char **typ; //pointer to a pointer to char (meant for recording tokens into array)
  int numTokens = count_tokens(str);
  typ = tokVec = calloc(numTokens, sizeof(char*));
  char *start = token_start(str);
  while(start){
    char *end = token_terminator(start);
    char *tokCopy = copy_str(start, end - start);
    *typ = tokCopy;
    typ++;
    start = token_start(end);
  }
  *typ = 0; //vector terminator
  return tokVec;
}

void print_tokens(char **tokens){
  for(int i = 0; tokens[i] != NULL; i++){
    printf("%s ", tokens[i]);
  }
  printf("\n");
    
}

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}

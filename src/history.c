#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


Item *hist = 0;
static short count = 0;

void add_history(char *str){
  Item *newItem = malloc(sizeof(Item));
  short len = 0;
  char *tempStr = str;
  while (*tempStr != '\0') {	/* measure length of str */
    tempStr++;
    len++;
  }
  
  char *scopy = copy_str(str, len);
  if (newItem) {
    newItem -> id = count ++;
    newItem -> str = scopy;
    newItem -> next = hist;
    hist = newItem;
  }
}

char
 *get_history(int id){
  Item *itemP = hist;
  if (id >= count)
    return 0;
  while(itemP->id != id){
    itemP = itemP->next;
  }
  return itemP->str;
}

void print_history(){
  Item *itemP = hist;
  while (itemP) {
    printf("%d   %s", itemP -> id, itemP -> str);
    itemP = itemP->next;
  }
}

void free_history()
{
  Item *itemP = hist;
  Item *nextItem;
  while (itemP) {
    free(itemP->str);
    nextItem = itemP->next;
    free(itemP);
    itemP = nextItem;
  }
  hist = 0;
}


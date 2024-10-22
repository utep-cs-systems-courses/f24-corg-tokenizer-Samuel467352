#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;


Item *root;


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(char *str);

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */


char *get_history(int id);

/*Print the entire contents of the list. */
void print_history();

/*Free the history list and the strings it references. */
void free_history();

#endif

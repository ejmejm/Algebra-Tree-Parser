
#include "LinkedList.h"

typedef struct Element {
	int is_terminal;
	void *data;
} Element;

extern Element *Element_new(int isTerminal, void *data);
extern inline void Element_free(Element e);

extern int Parser_parse(char *input);
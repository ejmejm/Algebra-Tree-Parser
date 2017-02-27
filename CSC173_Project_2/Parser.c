
#include "Parser.h"

Element *Element_new(int isTerminal, void *data) {
	Element *e = (Element *) malloc(sizeof(Element));
	e->is_terminal = isTerminal;
	e->data = data;
	return e;
}

inline void Element_free(Element e) {
	free(e);
}

int Parser_parse(char *input) {
	LinkedList *stack = LinkedList_new();

	LinkedList_add_at_front(stack, Element_new(0, 'E'));
	int lookahead = 0;

	while (lookahead < strlen(input)) {
		Element *sfront = (Element *) LinkedList_pop(stack);
		if (sfront->data == input[lookahead]) {
			lookahead++;
		}
		else {
			if (sfront->data == 'E') {
				LinkedList_add_at_front(stack, Element_new(0, 'J')); //J == TT
				LinkedList_add_at_front(stack, Element_new(0, 'T'));
			} else if (sfront->data == 'J') {
				if (input[lookahead] == '+') {
					LinkedList_add_at_front(stack, Element_new(1, '+'));
					LinkedList_add_at_front(stack, Element_new(1, '-'));
					LinkedList_add_at_front(stack, Element_new(0, 'T'));
					LinkedList_add_at_front(stack, Element_new(0, 'J'));
				} //Else add nothing because of epsilon
			} else if (sfront->data == 'T') {
				LinkedList_add_at_front(stack, Element_new(0, 'F'));
				LinkedList_add_at_front(stack, Element_new(0, 'T'));
			}
			else {
				printf("Error, %s was not parsable", input);
				return 0;
			}
		}
	}

	return 1;
}
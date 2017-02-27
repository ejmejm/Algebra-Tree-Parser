
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
		if()
		printf("%c\n", sfront->data);
		if (sfront->data == input[lookahead]) {
			lookahead++;
		}
		else {
			if (sfront->data == 'E') {
				LinkedList_add_at_front(stack, Element_new(0, 'J')); //J == TT
				LinkedList_add_at_front(stack, Element_new(0, 'T'));
			} else if (sfront->data == 'J') {
				if (input[lookahead] == '+') {
					LinkedList_add_at_front(stack, Element_new(0, 'J'));
					LinkedList_add_at_front(stack, Element_new(0, 'T'));
					LinkedList_add_at_front(stack, Element_new(1, '+'));
				} else if (input[lookahead] == '-') {
					LinkedList_add_at_front(stack, Element_new(0, 'J'));
					LinkedList_add_at_front(stack, Element_new(0, 'T'));
					LinkedList_add_at_front(stack, Element_new(1, '-'));
				} //Else add nothing because of epsilon
			} else if (sfront->data == 'T') {
				LinkedList_add_at_front(stack, Element_new(0, 'G')); //G == FT
				LinkedList_add_at_front(stack, Element_new(0, 'F'));
			}
			else if (sfront->data == 'G') {
				if (input[lookahead] == '*') {
					LinkedList_add_at_front(stack, Element_new(0, 'G'));
					LinkedList_add_at_front(stack, Element_new(0, 'F'));
					LinkedList_add_at_front(stack, Element_new(1, '*'));
				}
				else if (input[lookahead] == '/') {
					LinkedList_add_at_front(stack, Element_new(0, 'G'));
					LinkedList_add_at_front(stack, Element_new(0, 'F'));
					LinkedList_add_at_front(stack, Element_new(1, '/'));
				} //Else add nothing because of epsilon
			}
			else if (sfront->data == 'F') {
				if (input[lookahead] == '(') {
					LinkedList_add_at_front(stack, Element_new(1, ')'));
					LinkedList_add_at_front(stack, Element_new(0, 'E'));
					LinkedList_add_at_front(stack, Element_new(1, '('));
				}
				else
					LinkedList_add_at_front(stack, Element_new(0, 'N'));
			}
			else if (sfront->data == 'N') {
				LinkedList_add_at_front(stack, Element_new(0, 'H')); //H == NT
				LinkedList_add_at_front(stack, Element_new(0, 'D'));
			}
			else if (sfront->data == 'H') {
				if (input[lookahead] == '0' || input[lookahead] == '1' || input[lookahead] == '2' ||
					input[lookahead] == '3' || input[lookahead] == '4' || input[lookahead] == '5' ||
					input[lookahead] == '6' || input[lookahead] == '7' || input[lookahead] == '8' ||
					input[lookahead] == '9') {
					LinkedList_add_at_front(stack, Element_new(0, 'N'));
				} //Else add nothing because of epsilon
			}
			else if (sfront->data == 'D') {
				if (input[lookahead] == '0' || input[lookahead] == '1' || input[lookahead] == '2' ||
					input[lookahead] == '3' || input[lookahead] == '4' || input[lookahead] == '5' ||
					input[lookahead] == '6' || input[lookahead] == '7' || input[lookahead] == '8' ||
					input[lookahead] == '9') {
				}
				else {
					return 0;
					printf("Error, %s was not parsable", input);
				}
			} else {
				printf("Error, %s was not parsable", input);
				return 0;
			}
		}
	}

	return 1;
}
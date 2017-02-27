#include <stdio.h>
#include "Parser.h"

int main() {

	printf("Hello World\n");

	Element *e = Element_new(0, "S");

	printf("%d, %s", e->is_terminal, e->data);

	getchar();
	return 0;
}
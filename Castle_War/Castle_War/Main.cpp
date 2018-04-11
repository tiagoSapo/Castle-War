#include "Castle.h"

int main() {

	Castle *c = new Castle();
	c->start();

	delete c;
	return 0;
}
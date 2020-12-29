#include "Utilities.h"
#include <stdlib.h>
#include <iostream>
//========================================================================
/* The function print the received error message and close the program
 * with -1 return value.
 * input: string
 * output: none.
*/
void terminate(const std::string errorMessage) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}
//========================================================================
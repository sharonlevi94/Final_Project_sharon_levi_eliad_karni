//============================= include section ==============================
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
//============================ functions section ==============================

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
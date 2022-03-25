#ifndef _SANSTDHEADERS_H_
#define _SANSTDHEADERS_H_

/*
** assert(x) if x=0:
** print to stderr the text of x, the filename calling it and the
** line number.
** if NDEBUG is defined it do anything
*/
//#define NDEBUG
#include <cassert>

#include <cstdio> // in/out fonctions
#include <cstdlib> // standart fonctions( memory allocation, random generator... )
#include <cmath> // mathematical fonctions, specially trigonometric fonctions
#include <vector> // template and fonctions for vector management
#include <string> // template and functions to manipulate string type
#include <stack>
#include <iostream> // same as cstdio but object oriented( more easy to use )
#include <fstream> // file input/output class

#endif

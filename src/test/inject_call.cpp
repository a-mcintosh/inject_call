//  --------------------------------------------------------------
//  --  Build a procedure call.
//  --------------------------------------------------------------

#include "inject_call.h"
#include <stdio.h>
#include <iostream>     // std::cout, std::ios
#include <sstream>      // std::ostringstream

using namespace std;


int main(int argc, char* argv[]) {
	printf("\nFixed after analysis by RandomReader in freenode ##c++");
	printf("\nInject_call: start.\nList of argv[]\n");
	for (int i=0; i<argc; i++) {printf("\t%i  %s\n", i, argv[i]);}
//  --------------------------------------------------------------

  	int argc_local = 4;
	int nHeight = 1000;

	std::ostringstream strs;
	strs << nHeight;
	static std::string stable_string = strs.str();
	static const char *cstr[9] = { stable_string.c_str() };
	printf("\nnHeight is %s\n", *cstr);
	const char *argv_local[] = { \
		"bitcoind", \
		"getblockhash", \
		*cstr, \
		"debug-sentinal-disregard" \
	}; 
	for (int i=0; i<argc_local; i++) \
		{printf("\t%i  %s\n", i, argv_local[i]);}
//  --------------------------------------------------------------

	printf("\nContinue preparation as in bitcoinrpc.cpp\n");
	printf("Re-print the argc array.  This should be unchanged.\n");
	for (int i=0; i<argc_local; i++) \
		{printf("\t%i  %s\n", i, argv_local[i]);}
        string strMethod = argv_local[1];
        std::vector<std::string> \
		strParams(&argv_local[2], &argv_local[argc_local]);
	printf("\nItem Nr. 0 should be %i.  This code now works.\n", nHeight);
	for (int i=0; i<argc_local-2; i++) \
		{printf("\t%i  %s\n", i, strParams[i].c_str());}
	printf("\nRe-print the argc array.  This should be unchanged.\n");
	for (int i=0; i<argc_local; i++) \
		{printf("\t%i  %s\n", i, argv_local[i]);}
//  --------------------------------------------------------------

	printf("Inject_call: end.\n\n");
	return true;
}



//  --------------------------------------------------------------
//  --  Build a procedure call.
//  --------------------------------------------------------------

#include "inject_call.h"
#include <stdio.h>
#include <iostream>     // std::cout, std::ios
#include <sstream>      // std::ostringstream

using namespace std;


int main(int argc, char* argv[]) {
	printf("\nInject_call: start.\nList of argv[]\n");
	for (int i=0; i<argc; i++) {printf("\t%i  %s\n", i, argv[i]);}
//  --------------------------------------------------------------

  	int argc_local = 4;
	int nHeight = 1000;

	std::ostringstream strs;
	strs << nHeight;
	static const char *cstr[9] = { strs.str().c_str() };
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
	printf("\nItem Nr. 0 should be %i.  This code fails.\n", nHeight);
	for (int i=0; i<argc_local-2; i++) \
		{printf("\t%i  %s\n", i, strParams[i].c_str());}
	printf("\nRe-print the argc array.  This should be unchanged.  How did this happen?\n");
	for (int i=0; i<argc_local; i++) \
		{printf("\t%i  %s\n", i, argv_local[i]);}
//  --------------------------------------------------------------

	printf("Inject_call: end.\n\n");
	return true;
}



//  --------------------------------------------------------------
//  --  Build a procedure call.
//  --------------------------------------------------------------

#include "inject_call.h"
#include <stdio.h>
#include <iostream>     // std::cout, std::ios
#include <sstream>      // std::ostringstream

using namespace std;


int main(int argc, char* argv[]) {
	printf("\nInject_call: start.\n\tlist of argv[]\n");
	for (int i=0; i<argc; i++) {printf("\t%i  %s\n", i, argv[i]);}
//  --------------------------------------------------------------

  	int argc_local = 4;
	int nHeight = 1000;

	std::ostringstream strs;
	strs << nHeight;
	static const char *cstr[9] = { strs.str().c_str() };
	printf("The string encoded nHeight is %s\n", *cstr);
	const char *argv_local[] = { \
		"bitcoind", \
		"getblockhash", \
		*cstr, \
		"30" \
	};
	for (int i=0; i<argc_local; i++) \
		{printf("\t%i  %s\n", i, argv_local[i]);}
//  --------------------------------------------------------------

	printf("Continue preparation as in bitcoinrpc.cpp\n");
        string strMethod = argv_local[1];
        std::vector<std::string> \
		strParams(&argv_local[1], &argv_local[argc_local]);
	for (int i=0; i<argc_local; i++) \
		{printf("\t%i  %s\n", i, argv_local[i]);}
//  --------------------------------------------------------------

	printf("Inject_call: end.\n\n");
	return true;
}



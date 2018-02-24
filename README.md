# inject_call
Setup argc, argv to make test call to program.

I had trouble setting up a debugging call to a program.  I traced the trouble back to the statement
*         std::vector<std::string> strParams(&argv_local[1], &argv_local[argc_local]);

I don't yet know why this behaves this way.


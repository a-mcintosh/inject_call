# Behavior when building a call environment to a program.

I am building the argc, argv environment to call a program with test parameters.
For some reason, I get what I expect with a quoted number for a parameter, but when I create a const char * for the same parameter my argv[] list is off by 1 counter.



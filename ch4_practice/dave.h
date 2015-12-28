#pragma once
#include <iostream>
#include <string>

// __cplusplus is defined in Visual Studio 2015
// if in this environment, wait for a keypress before returning, closing the command window
#define MacroWaitReturn return 0;
#ifdef __cplusplus
#if __cplusplus == 199711
#undef MacroWaitReturn
#define MacroWaitReturn string wait = ""; \
                 cout << "Please press any key to exit from main" << endl; \
                 getline(cin, wait, '\n'); \
                 return 0;
#endif
#endif

using namespace std;

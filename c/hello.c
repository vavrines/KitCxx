// Hello World Program for Library Load & Usage
// Compilation: g++ hello.cpp -l kit -L .

#include <stdio.h>
#include "libkit.h"

int main() {
    //std::cout << "Hello World!" << std::endl;    
    hello(); // from libkit
    
    return 0;
}
/*
DEBUGING WITH GDB AND G++
    1. Compile the program with debug support: 
        g++ main.cpp -o stepfun -g
    2. Open the GDB debugger session console:
        gdb a.out
    3. To insert a breakpoint: 
        (gdb) break filename:lineNumber 
        You may also tell GDB to break on a certain function name: 
            (gdb) break main
    4. Either way, you can now execute your program: 
        (gdb) run
    5. use the step command to follow each line of the program, including steps into functions. 
    6. press enter to repeat the last command. 
    7. to step back out of a function invocation, you use the finish command: 
        (gdb) finish 
    8. to execute an instruction without stepping int9o a function call, you use the next 
        command: 
        (gdb) next <--- this is normally what I use. 
    9. To inspect the value of variables, you use the info locals command: 
        (gdb) info locals 
        IMPORTANT: variables that have not been initialized yet will not have sensible values. 
    10. To continue execution until the next breakpoint (or until the program completes) use the 
        continue command: 
        (gdb) continue
*/

#include <cstdio>
#include <iostream> 
using namespace std; 

int main() {
    int myInt = 256; 
    string myString = "asd;fasdfasdf"; 
    std::cout<< "About to change variables: "; 
    myInt = 512; 
    myString = "changed the string."; 
    for(int i = 0; i < 10; i++) {
        myString += 'j'; 
    }
    return 0; 
} 
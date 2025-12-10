/*
FORMAT SPECIFIERS
specifier	Output	                                                                    Example
d or i	    Signed decimal integer	                                                    392
u	        Unsigned decimal integer	                                                7235
o	        Unsigned octal	                                                            610
x	        Unsigned hexadecimal integer	                                            7fa
X	        Unsigned hexadecimal integer (uppercase)	                                7FA
f	        Decimal floating point, lowercase	                                        392.65
F	        Decimal floating point, uppercase	                                        392.65
e	        Scientific notation (mantissa/exponent), lowercase	                        3.9265e+2
E	        Scientific notation (mantissa/exponent), uppercase	                        3.9265E+2
g	        Use the shortest representation: %e or %f	                                392.65
G	        Use the shortest representation: %E or %F	                                392.65
a	        Hexadecimal floating point, lowercase	                                    -0xc.90fep-2
A	        Hexadecimal floating point, uppercase	                                    -0XC.90FEP-2
c	        Character	                                                                a
s	        String of characters	                                                    sample
p	        Pointer address	                                                            b8000000
n	        Nothing printed.
            The corresponding argument must be a pointer to a signed int.
            The number of characters written so far is stored in the pointed location.
%	        A % followed by another % character will write a single % to the stream.	%

*/
#include <cstdio>
#include <iostream> 
#include <climits> // for CHAR_BIT  
#include <iomanip> // for std::setw (which sets the width of the subsequent outp0ut)
using namespace std; 
int main()
{
    std::cout << "A byte is " <<CHAR_BIT << " bits \n\n"; 
    
    std::cout << std::left; // left justify output. 

    std::cout << std::setw(16) << "Bool: " << sizeof(bool) << " bytes\n"; 
    std::cout<<std::setw(16) << "Char: " << sizeof(char) << " bytes\n"; 
    std::cout<<std::setw(16)<< "Short: " << sizeof(short) << " bytes\n"; 
    std::cout<<std::setw(16)<<"Int: " << sizeof(int) << " bytes\n"; 
    std::cout<<std::setw(16) << "Long: " << sizeof(long) << " bytes\n"; 
    std::cout<<std::setw(16) << "Long long: " << sizeof(long long) << " bytes\n"; 
    std::cout<<std::setw(16) << "Float: " << sizeof(float) << " bytes\n"; 
    std::cout<<std::setw(16) << "Double: " << sizeof(double) << " bytes\n"; 
    std::cout<<std::setw(16) << "Long double: " << sizeof(long double) << " bytes\n"; 

    return 0; 
    
}
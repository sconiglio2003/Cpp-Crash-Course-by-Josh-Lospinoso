#include <cstdio>
#include <iostream> 
#include <string> 
#include <thread> // for timed delays. 

using namespace std; 
/*
IMPLICIT NARROWING CONVERSION
    happens when you divide two numbers of precision greater than the stored answer

*/
string menuMessage = "-------------------------------------------------------\nN A R R O W I N G  C O N V E R S I O N  E X A M P L E S\n-------------------------------------------------------\n                       by:                       \n>                    Guy Coniglio                    <\n\n"; 

int main() {
    for(int i = 0; i < menuMessage.length(); i++) {
        std::cout<<menuMessage[i]; 
        this_thread::sleep_for(chrono::milliseconds(80));
    }
    std::cout<<"Narrowing conversion happens when you divide two numbers and store the answer in \na number that cannot hold the answer to full precision.\n"; 
    float a = 1; 
    float b = 2; 
    int answer = a / b; 
    std::cout<<"Even though we divide 2 floats " << std::to_string(a) << " and " << std::to_string(b) << " , the issue is that we'ere storing the result in a " << typeid(answer).name()<<"\n"; 
    std::cout<<std::to_string(a) << " / " << std::to_string(b) << " = " << std::to_string(answer)<<"\n"; 
    std::cout<<"Unfortunately, this produces no compiler error. The way to get a warning for this narrowing conversion\n"; 
    std::cout<<"Is to simply use braced initializers for your answer when you declare it.\n"; 
    
    std::cout<<"Instead of saying this: \n  int answer = a / b;\nSay this instead:\n    int answer = {a / b};\nIn this case, the compiler will generate an error.\n"; 
    std::cout<<"Of course, this example is silly; the answer\'s type should be float.\n\n"; 
    
    int c = 1; 
    float d = 2; 
    double answer1 = {c / d}; 
    std::cout<<"The proper way to store answers to math and get narrowing conversion errors when necessary is to \n"; 
    std::cout<<"use this syntax: " << typeid(answer1).name() << " answer1 = {c / d};\n";
    std::cout<<typeid(c).name() << " " << std::to_string(c) << " / ";
    std::cout<< typeid(d).name() << " " << std::to_string(d); 
    std::cout<< " = " << typeid(answer1).name() << " " << std::to_string(answer1) << "\n\n"; 

    double e = 1; 
    double f = 2; 
    float g = e / f; 
    std::cout<<"Consider this example, which takes a " << typeid(e).name() << " and a " << typeid(f).name() << " and wrongly forces it into a " << typeid(g).name()<< " \n"; 
    std::cout<<"Had the developer used " << typeid(g).name() << " g = {e / f}; he would have gotten a compiler error\n"; 
    std::cout<<typeid(e).name() << " " << std::to_string(e) << " / "; 
    std::cout<<typeid(f).name() << " " << std::to_string(f) << " = "; 
    std::cout<<typeid(g).name() << " " << std::to_string(g) << "\n\n"; 


    int h = 1; 
    int i = 2; 
    double j = h / i; 
    std::cout<<"Consider this example, which divides a " << typeid(h).name() << " by a " << typeid(i).name() << " and is wrongly forced into a " << typeid(j).name() << "\n"; 
    std::cout<<"Had the designer used double j = {h / i}; syntax, he would have gotten a narrowing conversion error.\n"; 
    std::cout<<typeid(h).name() << " " << std::to_string(h) << " / "; 
    std::cout<<typeid(i).name() << " " << std::to_string(i) << " = "; 
    std::cout<<typeid(j).name() << " " << std::to_string(j) << "\n"; 
    
     
    return 0; 
}
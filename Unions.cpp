#include <cstdio>
#include <string>
#include <iostream> 


/*
UNIONS 
    unions are cousins of plain old data classes (PODs) 
    From https://learn.microsoft.com/en-us/cpp/cpp/unions?view=msvc-170
    "This definition means that at any given time, a union can contain 
    no more than one object from its list of members. It also means that 
    no matter how many members a union has, it always uses only enough 
    memory to store the largest member."

    All of a union's members are stored in exactly the same location in memory. 

    Members are accessed with the instanceName.member syntax. 
    SkidLoader.engineType; 

    unions can only contain basic data types - PODs
        int, char, bool 
        NOT string or Excavator - too much memory management. 
    
    */
union unionExcavator {
    int weight;             // In tons
    int engineDisplacement; // in cubic inches.
    int horsePower;         // in horse power.
    // This data type is too complex to put into a union; it must be a POD: string oilType;         // Example: SAE10-w30
    // This data type is too complex to put into a union; it must be a POD: string model;           // Example: CAT-336F
    // This data type is too complex to put into a union; it must be a POD: string engineModel;     // Example: CAT-C9
}; 

using namespace std; 
int main() {


    // create an excavator instance, but as a union
    unionExcavator myExcavator;
    myExcavator.weight = 88400;
    myExcavator.engineDisplacement = 568;
    myExcavator.horsePower = 303;
    std::cout<<"This sentence will be strange. It is supposed to demonstrate the the excavator union stores all its attributes/members in the same exact memory location.\nNotice that whatever attribute/member we last modified in the union, is the value that is given for every member!\n"; 
    std::cout<<"The excavator is a union instance. It weighs " << std::to_string(myExcavator.weight) << "lbs, and has a " << std::to_string(myExcavator.engineDisplacement) << " cu/in engine with " << std::to_string(myExcavator.horsePower) << "hp. \n"; 
    std::cout<<"Unions are utilized to keep memory to a minimum.\n";
    std::cout<<"You should avoid using unions in all but the rarest of cases, and you won't see\n";
    std::cout<<"Them in this book. (Cpp Crash Course, Josh Lospinoso, page 54)\n";   
    return 0; 
}
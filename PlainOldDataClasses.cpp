#include <cstdio>
#include <iostream>
#include <string>
// Plain old data classes
// Classes are user defined types.
// classes contain functions and data
// the simplest classes contain only data, no functions - POD "plain old data"
// each element of a class is called a memeber.
// every POD begins with the keyword struct
// Structs are C compatible!
// Structs can efficiently represented in memory.
// C++ gaurantees that members will be sequential in memory; however, some implementations require members to be aligned
//  along word boundaries. This depends on CPU register length.
//  A general rule: order members from largest to smallest in POD definitions.
// Even though the book does not show this, I added a method getDescription() which returns a string.
// Unlike unions, a struct has room for all its members in memory. this means that sizeof(structName) will be bigger than
//  sizeof(myUnion). 
/*

From Google AI about this Code specifically:
Non-POD Members: The std::string members (model, oilType, etc.) prevent it from being a POD.
A true POD can only contain fundamental types (like int, char, float) or other POD types.
Member Functions: While having a member function alone does not always disqualify a struct
from being a POD (in modern C++ standards, simple member functions are allowed if other
criteria are met), the std::string members are the primary disqualifier here.
C Compatibility: Because it uses C++ features like std::string and methods, this
specific struct is not strictly C-compatible, unlike a true POD that uses only fundamental types.

*/
using namespace std;
struct Excavator
{
    // all these data points are called members.
    int weight;             // In tons
    int engineDisplacement; // in cubic inches.
    int horsePower;         // in horse power.
    string oilType;         // Example: SAE10-w30
    string model;           // Example: CAT-336F
    string engineModel;     // Example: CAT-C9
    
    string getDescription()
    {
        string description;
        description += "This is a " + this->model;
        description += ", and it weighs " + std::to_string(this->weight) + " tons.";
        description += " It has a " + this->engineModel + " engine, with " + std::to_string(this->horsePower) + "hp, having " + std::to_string(this->engineDisplacement) + " cu/in of displacement. ";
        description += "If you need to fill the oil, you need " + this->oilType + " or SAE equivalent.";
        return description;
    }
};
int main()
{
    // create an excavator
    Excavator myExcavator;
    myExcavator.model = "CAT-336F";
    myExcavator.weight = 88400;
    myExcavator.oilType = "10W-40";
    myExcavator.engineModel = "CAT-C9";
    myExcavator.engineDisplacement = 568;
    myExcavator.horsePower = 303;
    std::cout << myExcavator.getDescription();
    return 0;
}
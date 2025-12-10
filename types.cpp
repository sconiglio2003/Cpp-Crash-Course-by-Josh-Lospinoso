#include <iostream>
#include <cstdio>
#include <cstddef> // allows work with the byte type
                   // std::byte doesn't have a type.
                   // permits bitwise logic operations.
                   // Whiel you can perform arithmetic on a char and unsigned char
                   // you cannot perform arithmatic on an std::byte.
                   // One interesting thing ot use is the size_t type.
                   // the size_t gaurantees that any object can fit in it.
                   // it could be 2 bytes or 200 bytes in size.
                   // sizeof() returns a size_t.

using namespace std;
int main()
{
    // integers
    //  short int
    //  int
    //  long int
    //  long long int
    //  single precision floating types
    //  > can be signed or unsigned.
    //  Signed can be positive, negative, or 0.
    //  Unsigned variables must be non negative. (this doesnt produce an error by the way)
    //  Integer types are signed and int by default.
    //      this means You use the follwing short hand instead:
    //      short, long, long long              <---- correct
    //          not
    //      short int, long int, long long int <----- incorrect.
    std::cout << "Integers: \n";
    int thing = 0b11111111;
    unsigned int myShortInt = 0;
    // If you absolutely have to have ints of the correct size, refer to page
    // 32 of the book
    // Use the <cstdint> library.
    // It lets you have integers of 8, 16, 32, 64 bits.
    // int8_t, int16_t, int32_t, int64_t
    // if you need signle point precision, use the f or F suffix:
    // the biggest possible number:
    unsigned int biggestNumPossible = 9999999999999999999;
    int singlePrecision = 1.0f;
    int alsoWorks = 1.0F;
    // if you want extended precision, use the suffix l or L:
    int extendedPrecision = 1.0l;
    int thisWorksToo = 1.0L;
    // scientific notation:
    double specialNum = 6.4234543e-34;
    // declare an array .
    std::cout << "Arrays: \n";
    int myArray[] = {1, 2, 3, 4, 5};

    // simple trick to obtain the total size in bytes of an array
    //  fun fact: this calculation happens at compile time, so there's no
    //      performance hit during execution.
    double bigArray[100987679];
    size_t arraySize = sizeof(bigArray);
    size_t numElements = sizeof(bigArray) / sizeof(double);
    std::cout << "The array has " << numElements << " items, and it is " << arraySize / 1000 << " kilobytes. ";

    // C STYLE STRINGS
    // continuous blocks of characters.
    // also called a null terminated string, since it has a zero byte at the end.
    // The null byte indicates the end of the string.
    // Because array elements are continous, you can store strings in arrays
    //  of chracter types.
    char myChars[100];
    // add character 'c' to an array of chars.
    // notice how this array may change size, but the
    // for loop will always go through the entire array!
    for (int i = 0; i < sizeof(myChars) / sizeof(char); i++)
    {
        myChars[i] = 'c';
    }
    // print it out
    for (char c : myChars)
    {
        std::cout << c;
    }
    // ENUMS
    // cpp uses scoped enums, but has support for unscoped enums (which shouldn't be used), they were
    //  implemented for compatibility purposes.
    // Just because unscoped enums can be used doesn't mean you should.
    // use class enums.
    // unscoped enums are not type safe. It would let you make two enums of different types
    // and then compare themn as if they were the same types! Two enums fruit and color could be
    // compared in an if() statement with no compiler error.
    // Enums declare a list of unchangeable values (constants)
    // scoped enums don't implicitly convert to integers.
    // enumerators are only placed into the scoe region of the enumerator.
    // A scoped enum is type safe; if you try to compare two enums that are different, you'll
    // instead get a compiler error.
    // even though we use the "class" keyword here, enums are not of the class type.
    // Enum structs can work identically to scoped enums; however, it is non idiomatic, so avoid its use.
    //  (non idiomatic means "the literal, straightforward sense of words in a phrase, rather than figurative or culturaly specific meaning")
    // Enums are designed to be flat; not relational or hierarchial. use classes instead.
    //  For example, I wouldn't add to the computerPart enum a new enum that lsts possible GPUs.
    //  I could make a GPU enum, but it would not be  integrated into computerPart enum. it would be seperate.
    //  the purpose of an enum is to provide human readable lists where you select a single option.
    std::cout << "\nEnums: \n";
    // declare an enum
    // enum class typeName { listing of values it can take }
    // your values should be alphanumeric strings.
    // Your listing of values can be any catagories.
    // allows for more expressive code.
    // the below enum class can take any of the listings inside its {}
    enum class computerPart
    {
        // items defined here are aprt of computerPart's scope region.
        GPU,
        PSU,
        MONITOR,
        MOTHERBOARD,
        KEYBOARD,
        MOUSE,
        SOUND_SYSTEM,
        RAM,
        SSD,
        CASE
    };
    // To initialize an enumeration variable to a value, use the anme of the type
    // followed by two colons :: and the desired value.
    // below, I've made a comp0uter part called an RTX4070.
    computerPart RTX4070{computerPart::GPU};
    std::cout << "created a " << typeid(RTX4070).name() << "\n";
    // Notice this: scoped enums do not implicity convert to integers, which is why the line
    // below is commented out. The compiler doesn't know how to print the enum, since it's not
    // convertable to an integer:
    // std::cout<<"The enum's value is " << computerPart::GPU;
    // if you absolutey have to have a value read from an enum, use this method below
    // an array of parts for our loop so we can see how easy enum code is to read.
    computerPart myParts[] = {
        computerPart::CASE,
        computerPart::GPU,
        computerPart::KEYBOARD,
        computerPart::MONITOR,
        computerPart::MOTHERBOARD,
        computerPart::MOUSE,
        computerPart::PSU,
        computerPart::RAM,
        computerPart::SOUND_SYSTEM,
        computerPart::SSD};
    // loop through my list of computer parts, and for each part use enum phrase to say if I have it.
    for (computerPart part : myParts)
    {
        switch (part)
        {
        case computerPart::GPU:
            std::cout << "You have a GPU\n";
            break;
        case computerPart::PSU:
            std::cout << "You have a PSU\n";
            break;
        case computerPart::MONITOR:
            std::cout << "You have a MONITOR\n";
            break;
        case computerPart::MOTHERBOARD:
            std::cout << "You have a MOTHERBOARD\n";
            break;
        case computerPart::KEYBOARD:
            std::cout << "You have a KEYBOARD\n";
            break;
        case computerPart::MOUSE:
            std::cout << "You have a MOUSE\n";
            break;
        case computerPart::SOUND_SYSTEM:
            std::cout << "You have a SOUND SYSTEM\n";
            break;
        case computerPart::RAM:
            std::cout << "You have a stick of RAM\n";
            break;
        case computerPart::SSD:
            std::cout << "You have an SSD \n";
            break;
        case computerPart::CASE:
            std::cout << "You have a CASE \n";
            break;
        }
    }
    // enums are great for making code more readable!
    computerPart myPart{computerPart::GPU};
    if (myPart == computerPart::CASE)
    {
        std::cout << "Your part is a computer case.";
    }
    else if (myPart == computerPart::GPU)
    {
        std::cout << "Your part is a GPU";
    }
    
    return 0;
}
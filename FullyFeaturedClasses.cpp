#include <cstdio>
#include <iostream>

using namespace std;
/*
ENCAPSULATION
    combining data with functions that manipulate it

    there is
    only a class can access its private members.
FULLY FEATURED CLASSES
    classes and structs are exactly the same besides default access control.
    all struct members are public by default, while class members are private by default.
    A method is a member function of a class
    The class below is a data class designed to showcase access controls. 
    the member 'data' is private, so the line below will produce an error: 
    std::cout<<myData.data; 
    
    Instead, we access it through a public function that requires the proper key
    this public function is called 'getData(int key)' 
    it returns false if you provide the wrong key
    if you give the right key, then it will return the data. 
    a constructor is important, because it ensures that an object instance never has 
    unitialized members. 
    you may have as many constructors in a class definition as you like, but their 
    argument list must be different. 
    
*/
class SecretData
{
private: 
    int key{};
    string data{};

public:
    SecretData(string d, int k)
    {
        this->data = d;
        this->key = k;
    }
    string getData(int key)
    {
        string theData;
        if (key == this->key)
        {
            return this->data;
        }
        else
        {
            return "incorrect key";
        }
    }
};

int main()
{
    string myData = "3585FFAC67654BBH";
    int myKey = 10;
    SecretData mySecretData(myData, myKey);
    std::cout<<mySecretData.getData(11); 
    std::cout<<mySecretData.getData(myKey); 

}
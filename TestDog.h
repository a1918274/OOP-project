#include <iostream>
#include "Dog.h"
#include "Item.h"

using namespace std;

class UnitTest{
    public:
    void runTests(){
        testDisplay();
    }
    public:
    void testDisplay(){
        {
            Dog dog("dog", 9);
            dog.display();
            cout<<"Test 1 passed!"<<endl;
        }
    }
};

int main(){
    UnitTest unitTest;
    unitTest.runTests();
    return 0;
}
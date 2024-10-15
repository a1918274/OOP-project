#ifndef TESTPLANT_H
#define TESTPLANT_H
#include <iostream>
#include <fstream>

#include "Item.h"
#include "Plant.h"

using namespace std;

class TestPlant {
public:
    void runTests(){
        cout << "\n Running tests for Seed: \n\n";
        testConstructor();
        testDisplay();
        testGetSellType();
        testSerializeDeserialize();
    }

private:
void testConstructor(){
    cout << "Testing constructor:\n";
    {
     Plant plant("Potato", 7, 23);
     assert((plant.getName() == "Potato") && (plant.getPrice() == 7) && (plant.getSellPrice() == 23));
    }

    {
     Plant plant("Leek", 89, 2);
     assert((plant.getName() == "Leek") && (plant.getPrice() == 89) && (plant.getSellPrice() == 2));
    }

     {
     Plant plant("Tulip", 34, 35);
     assert((plant.getName() == "Tulip") && (plant.getPrice() == 34) && (plant.getSellPrice() == 35));
     }

     cout << "Test 1 passed" << endl;
}

void testDisplay(){
    Plant plant("Corn", 6, 9);
    plant.display();
    cout << "Test 2 passed" << endl;
}

void testGetSellType(){
    {
    Plant plant("Corn", 6, 11);
    if (plant.getSellPrice() != 11) {
        cout << "Test 3.1 failed" << endl;
        }
    }

    {
    Plant plant("Corn", 6, 0);
    if (plant.getSellPrice() != 0); {
        cout << "Test 3.2 failed" << endl;
        } 
    }

    {
    Plant plant("Corn", 6, 29);
    if (plant.getSellPrice() != 29); {
        cout << "Test 3.3 failed" << endl;
        }
    }

}
};

void testSerializeDeserialize() {
    // The serialize and deserialize functions are grouped together for testing, as retrieving
    // the information from the file containing the serialized data is equivalent to deserialization



}



#endif //TESTPLANT_H
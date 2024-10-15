#ifndef TESTITEM_H
#define TESTITEM_H

//Testing for item
#include "Item.h"
#include<iostream>

using namespace std;

// As Item is an abstract class (due to pure virtual functions), an item
// cannot be created, and thus the functions cannot be tested. Proof of testing
// for this class can thus be found in child/inhered classes (please refer to 
// GrownAnimal, YoungAnimal, Plant and Seed classes for relevant testing).

#endif //TESTITEM_H
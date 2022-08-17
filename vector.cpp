#include <iostream>
#include "vector.h"



int main()
{
    Vector<int> obj;
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);
    obj.push_back(6);
    obj.push_back(8);
    obj.insert(3,12);
}


//
//  Header.h
//  lab2
//
//  Created by jason on 17/06/2022.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
using namespace std;
#define SEARCH_AMOUNT 3

struct Array
{
    int* arr;
    int size;

    Array()
    {
        arr = nullptr;
        size = 0;
    }

    Array(int newSize)
    {
        size = newSize;
        arr = new int[size];
    }

    int& operator[](const int& index)
    {
        return arr[index];
    }
    
    void pushBack(const int& position){
        size++;
        arr[size-1] = position;
    }
    
    ~Array()
    {
        if (arr)
            delete[] arr;
    }
};
bool linearSearchArray(Array &a, int checking, Array &allPosOfChecking);
bool binarySearch(Array& a, int checking, Array &allPosOfChecking);
bool sentinelLinearSearchArray(Array& a, int checking, Array &allPosOfChecking);
void timKiem(Array &a, string inputSearchAlgorithm, int searchKey, const string &outputPath);
void Input(string inputSearchAlgorithm, const string &inputPath, int searchKey, const string &outputPath);
//ostream& operator<<(ostream& dev, Array& a);

#endif /* Header_h */

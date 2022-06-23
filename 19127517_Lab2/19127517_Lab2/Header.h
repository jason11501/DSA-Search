//
//  Header.h
//  lab2
//
//  Created by jason on 17/06/2022.
//

#ifndef Header_h
#define Header_h
//2.1
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
bool binarySearchArray(Array& a, int checking, Array &allPosOfChecking);
bool sentinelLinearSearchArray(Array& a, int checking, Array &allPosOfChecking);
void searchThenWriteFile(Array &a, string inputSearchAlgorithm, int searchKey, const string &outputPath);
void Input(string inputSearchAlgorithm, const string &inputPath, int searchKey, const string &outputPath);

//2.2
#define MAX 124649
struct stringArray
{
    string* arr;
    int size;

    stringArray()
    {
        arr = nullptr;
        size = 0;
    }

    stringArray(int newSize)
    {
        size = newSize;
        arr = new string[size];
    }

    string& operator[](const int& index)
    {
        return arr[index];
    }
    
    void pushBack(const string &line){
        size++;
        arr[size - 1] = line;
    }
    
    ~stringArray()
    {
        if (arr)
            delete[] arr;
    }
};
struct Word{
    string name;
    string definition;
};
struct ArrayOfWords
{
    Word* arr;
    int size;

    ArrayOfWords()
    {
        arr = nullptr;
        size = 0;
    }

    ArrayOfWords(int newSize)
    {
        size = newSize;
        arr = new Word [size];
    }

    Word& operator[](const int& index)
    {
        return arr[index];
    }

    void pushBack(const Word& position)
    {
        size++;
        arr[size-1] = position;
    }

    ~ArrayOfWords()
    {
        if (arr)
            delete []arr;
    }
};
bool binarySearchStringArray(stringArray& a, string checking, Array &posInStringArray);
void storeInStruct(fstream &in, ArrayOfWords &dictionary);
void merge(stringArray& a, const int& start, const int& end);
void binarySearchStringArray(stringArray& a, string checking, string outputPath);
void linearSearchStringArray(stringArray &a, string checking, Array &allPosOfChecking, string outputPath);
void sentinelLinearSearchStringArray(stringArray &a, string checking, Array &allPosOfChecking, string outputPath);

#endif /* Header_h */

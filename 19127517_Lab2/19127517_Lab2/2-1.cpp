//
//  2-1.cpp
//  19127517_Lab2
//
//  Created by jason on 23/06/2022.
//

#include "Header.h"

std::string searching[]{ "1", "2", "3" };

bool linearSearchArray(Array &a, int checking, Array &allPosOfChecking)
{
    bool flag = false;
    for (int i=0; i<a.size; i++){
        if (a[i] == checking){
            allPosOfChecking.pushBack(i);
            flag = true;
        }
    }
    return flag;
}

bool binarySearchArray(Array& a, int checking, Array &allPosOfChecking)
{
    bool flag = false;
    int i=0, left=i, right=a.size-1, mid;
    while(left<right){
        mid = (left+right)/2;
        if(checking < a[mid])
            right = mid-1;
        else if (checking > a[mid])
            left = mid+1;
        else {//found searchKey/checking
            allPosOfChecking.pushBack(i);
            flag = true;
        }
        i++;
    }
    return flag;
}

bool sentinelLinearSearchArray(Array& a, int checking, Array &allPosOfChecking)
{
    a.pushBack(checking);
    bool flag = false;
    int i = 0;

    while(i <= a.size){
        if (i == a.size - 1){// sentinel
            if (!flag)// no checking in array
                return false;
            return true; // checking already in array
        }
        else if (i < a.size){
            if (a[i] == checking) {
                allPosOfChecking.pushBack(i);
                flag = true;
            }
            i++;
        }
    }
    return flag;
}

bool ValidSearch(const string& search)
{
    for (int i = 0; i < SEARCH_AMOUNT; i++)
        if (searching[i] == search)
            return true;
    return false;
}

void searchThenWriteFile(Array &a, string inputSearchAlgorithm, int searchKey, const string &outputPath)
{
    bool(*search)(Array&, int, Array&) = nullptr;
    if (inputSearchAlgorithm == searching[0])//1
        search = linearSearchArray;
    else if (inputSearchAlgorithm == searching[1])//2
        search = sentinelLinearSearchArray;
    else if (inputSearchAlgorithm == searching[2])//3
        search = binarySearchArray;

    Array posOfChecking(0);
    bool res;
    if (search){
        res = search(a, searchKey, posOfChecking);

        //Write file
        fstream out(outputPath);
        if (res){
            for (int i = 0; i < posOfChecking.size; i++){
                if (i < posOfChecking.size - 1)
                    out << posOfChecking[i] << " ";
                else if(i == posOfChecking.size - 1){
                    out << posOfChecking[i];
                }
            }
        }
        else{// cannot find searchKey
            out<< -1;
            return;
        }
        out.close();
    }
}

void Input(string inputSearchAlgorithm, const string &inputPath, int searchKey, const string &outputPath)
{
    //Get and validate input
    bool valid;
    do
    {
        valid = ValidSearch(inputSearchAlgorithm);
        if (!valid)
            cout << "Not a valid search. Please input again\n";
    } while (!valid);

    //File to struct Array
    ifstream in(inputPath);
    int size;
    in >> size;
    Array arr(size + 1);

    if (in)
    {
        for (int i = 0; i <= size; i++)
            in >> arr[i];
    }
    in.close();

    //Choose search algorithms and write the answer to File
    searchThenWriteFile(arr, inputSearchAlgorithm, searchKey, outputPath);
}

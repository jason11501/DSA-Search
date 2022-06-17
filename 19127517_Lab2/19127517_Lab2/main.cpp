//
//  main.cpp
//  lab2
//
//  Created by jason on 17/06/2022.
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

bool binarySearch(Array& a, int checking, Array &allPosOfChecking)
{
    bool flag = false;
    int i=0, l=i, r=a.size-1;
    while(l<r){
        int mid=(l+r)/2;
        if(checking<a[mid]) r=mid-1;
        else if (checking>a[mid]) l=mid+1;
        else {
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

void timKiem(Array &a, string inputSearchAlgorithm, int searchKey, const string &outputPath)
{
    bool(*search)(Array&, int, Array&) = nullptr;
    if (inputSearchAlgorithm == searching[0])//1
        search = linearSearchArray;
    else if (inputSearchAlgorithm == searching[1])//2
        search = sentinelLinearSearchArray;
    else if (inputSearchAlgorithm == searching[2])//3
        search = binarySearch;
    
    Array posOfChecking(0);
    bool res;
    if (search){
        res = search(a, searchKey, posOfChecking);
        
        //ghi file
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
        else{
            out<< -1;
        }
        out.close();
    }
}

void Input(string inputSearchAlgorithm, const string &inputPath, int searchKey, const string &outputPath)
{
    
    bool valid;
    //Get and validate input
    do
    {
        valid = ValidSearch(inputSearchAlgorithm);
        if (!valid)
            cout << "Not a valid search. Please input again\n";
    } while (!valid);

    //Get from file
    ifstream in(inputPath);//"/Users/jason/Downloads/19127517_Lab2/19127517_Lab2/Input.txt"
    int size;
    in >> size;
    Array arr(size + 1);

    if (in)
    {
        for (int i = 0; i <= size; i++)
            in >> arr[i];
    }
    in.close();
    
    timKiem(arr, inputSearchAlgorithm, searchKey, outputPath);
}

int main(int argc, char * argv[]) {
    //tham số dòng lệnh
    string inputSearchAlgorithm = argv[1];
    string inputPath = argv[3];
    int searchKey = atoi(argv[2]);
    string outputPath = argv[4];
    
//    string inputSearchAlgorithm = "1";
//    string inputPath = "/Users/jason/Downloads/19127517_Lab2/19127517_Lab2/Input.txt";
//    int searchKey = 8;
//    string outputPath = "/Users/jason/Downloads/19127517_Lab2/19127517_Lab2/Output.txt";
    
    Input(inputSearchAlgorithm, inputPath, searchKey, outputPath);
    
    return 0;
}

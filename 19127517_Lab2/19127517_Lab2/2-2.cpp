//
//  2-2.cpp
//  19127517_Lab2
//
//  Created by jason on 23/06/2022.
//

#include "Header.h"

//TASK 2.2
void Merge(stringArray& a, const int& start, const int& mid, const int& end)
{
    stringArray left(mid - start + 1);
    stringArray right(end - mid);
    for (int i = 0; i < left.size; i++)
        left[i] = a[start + i];
    for (int i = 0; i < right.size; i++)
        right[i] = a[start + i + left.size];

    int indexL = 0, indexR = 0, index = start;
    while (indexL < left.size && indexR < right.size)
    {
        if (left[indexL] < right[indexR])
            a[index] = left[indexL++];
        else
            a[index] = right[indexR++];
        index++;
    }

    //Left still remains
    while (indexL < left.size)
        a[index++] = left[indexL++];

    //Right still remains
    while (indexR < right.size)
        a[index++] = right[indexR++];
}

void merge(stringArray& a, const int& start, const int& end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        //chia đôi mảng
        merge(a, start, mid);
        merge(a, mid + 1, end);
        Merge(a, start, mid, end);// nhập các sub array đã tách theo thứ tự
    }
}

void binarySearchStringArray(stringArray& a, string checking, string outputPath)
{
    int i=0, left=i, right=a.size-1, mid;
    ofstream out(outputPath, std::ios_base::app);// append
    bool flag = false;
    while(left<right){
        mid = (left+right)/2;
        string wordAMid = a[mid].substr(0,a[mid].find(':'));
        if(checking < wordAMid)
            right = mid-1;
        else if (checking > wordAMid)
            left = mid+1;
        else {//found searchKey/checking
            flag = true;
            out << a[mid].substr(wordAMid.length()+1, a[mid].find('\n')) << endl;
            break;
        }
        i++;
    }
    if (flag == false)
        out << "-1";
    out.close();
}

void linearSearchStringArray(stringArray &a, string checking, Array &allPosOfChecking, string outputPath)
{
    bool flag = false;
    ofstream out(outputPath, std::ios_base::app);// append
    string wordTraversal;
    for (int i=0; i<a.size; i++){
        wordTraversal = a[i].substr(0, a[i].find(':'));
        if (wordTraversal == checking){
            flag = true;
            out << a[i].substr(wordTraversal.length()+1, a[i].find('\n')) << endl;
        }
    }
    
    if (flag == false)
        out << "-1";
    out.close();
}

void sentinelLinearSearchStringArray(stringArray &a, string checking, Array &allPosOfChecking, string outputPath)
{
    a[a.size] = checking;
    bool flag = false;
    ofstream out(outputPath, std::ios_base::app);// append
    int i = 0;
    string wordTraversal;
    while(i <= a.size){
        wordTraversal = a[i].substr(0, a[i].find(':'));
        if (i == a.size - 1) // sentinel
        {
            if (flag == false)
            {
                out << "-1";
                return;
            }
            else
                break;
        }
        else if (i < a.size)
        {
            if (wordTraversal == checking)
            {
                flag = true;
                out << a[i].substr(wordTraversal.length()+1, a[i].find('\n')) << endl;
            }
            i++;
        }
    }
    out.close();
}

void storeInStruct(fstream &in, ArrayOfWords &dictionary)
{
    //store in struct
    int i = 0;
    
    if (in){
        while (!in.eof()) {
            getline(in, dictionary[i].name,':');
            getline(in, dictionary[i].definition,'\n');
            i++;
            if (i == MAX) break;
        }
    }
}

//
//  main.cpp
//  lab2
//
//  Created by jason on 17/06/2022.
//

#include "Header.h"

int main(int argc, char * argv[])
{
//    // TASK 2-1
//    string inputSearchAlgorithm = argv[1];
//    string inputPath = argv[3];
//    int searchKey = atoi(argv[2]);
//    string outputPath1 = argv[4];
//
////    DEBUG
////    string inputSearchAlgorithm = "1";
////    string inputPath = "/Users/jason/Downloads/19127517_Lab2/19127517_Lab2/Input.txt";
////    int searchKey = 8;
////    string outputPath = "/Users/jason/Downloads/19127517_Lab2/19127517_Lab2/Output2-1.txt";
//
//    Input(inputSearchAlgorithm, inputPath, searchKey, outputPath1);

    //TASK 2-2
    int numOfWord = argc - 2;
    string outputPath = argv[argc - 1];
    
    //DEBUG
//    argc = 4;
//    int numOfWord = argc - 2;
//    argv[1] = "embittered";
//    argv[2] = "yearly";
//    string outputPath = "/Users/jason/Downloads/19127517_Lab2/19127517_Lab2/output2-2.txt";
    
    //Read file
    fstream inForStringArray("/Users/jason/Downloads/English-Vietnamese Dictionary.txt");
    stringArray arrayOfLine(MAX);
    int i = 0;
    
    if (inForStringArray){
        while (!inForStringArray.eof()) {
            getline(inForStringArray, arrayOfLine[i],'\n');
            i++;
            if (i == MAX) break;
        }
    }
    inForStringArray.close();
    
    //sort
    merge(arrayOfLine, 0, arrayOfLine.size - 1);
    
    //store in struct
    fstream inForStructArray("/Users/jason/Downloads/English-Vietnamese Dictionary.txt");
    ArrayOfWords dictionary(MAX);
    storeInStruct(inForStructArray, dictionary);
    
    //search definition and write file
    Array allPosOfChecking;
    for (int i=1; i<= numOfWord; i++)
    {
        binarySearchStringArray(arrayOfLine, argv[i], outputPath);
        linearSearchStringArray(arrayOfLine, argv[i], allPosOfChecking, outputPath);
        sentinelLinearSearchStringArray(arrayOfLine, argv[i], allPosOfChecking, outputPath);
    }
    return -4;
}

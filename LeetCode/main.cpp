//
//  main.cpp
//  LeetCode
//
//  Created by Shantanu Das on 22/10/15.
//  Copyright (c) 2015 Zakoi. All rights reserved.
//

#include <iostream>
#include "Third.h"
#include "StringOperation.h"
using namespace std;




int main(int argc, const char * argv[]) {
    
    int a[5] = {1,2,37,21,25};
    int b[5] = {21,22,23,28,29};

    int d[] = {21,22,23,28,29,54,55};
    int c[] = {1,2,7,21,25,48,49};

    vector<int> num,num1,num2,num3;
    for(int i=0;i<5;i++){
        num.push_back(a[i]);
        num1.push_back(b[i]);
    }
    
    for(int i=0;i<7;i++){
        num2.push_back(c[i]);
        num3.push_back(d[i]);
    }
    //cout<<findMedianSortedArrays(num, num1);
    findMedianSortedArrays(num3, num2);
    return 0;
}



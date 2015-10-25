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
    
    int a[5] = {3,2,37,21,25};
    int b[6] = {1,2,4,23,28,29};

    vector<int> num,num1;
    for(int i=0;i<1;i++){
        num.push_back(a[i]);
        
    }
    for(int i=0;i<3;i++){
        num1.push_back(b[i]);
    }
    //findMedianSortedArrays(num, num1);
    double median = findMedianSortedArrays(num, num1);
    cout<<"The median is "<<median;
    return 0;
}



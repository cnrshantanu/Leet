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
    
    int a[5] = {0,0,0,2,25};
    int b[6] = {1,3,4,6,28,29}; // 0 , 1, 3, 4, 6 , 28

    vector<int> num,num1;
    for(int i=0;i<1;i++){
        num.push_back(a[i]);
        
    }
    for(int i=0;i<5;i++){
        num1.push_back(b[i]);
    }
    //findMedianSortedArrays(num, num1);
    double median = findMedianSortedArrays(num, num1);
    cout<<"The median is "<<median;
    return 0;
}



//
//  Third.cpp
//  LeetCode
//
//  Created by Shantanu Das on 24/10/15.
//  Copyright (c) 2015 Zakoi. All rights reserved.
//

#include "Third.h"
#include <iostream>
using namespace std;

double getMedian(vector<int>& num) {
    if(num.size()%2 != 0)
        return (double) num.at(((num.size()+1)/2)-1);
    else
        return (num.at(num.size()/2)+num.at(((num.size())/2)-1))/(double)2;
}

void printVector(vector<int> vec){
    cout<<"\n";
    for(int i = 0; i < vec.size();i++)
        cout<<vec.at(i)<<" ";
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 1 ,4,5,8,9,12    //3,6,7,82
    int medianIndex1 = 0,medianIndex2 = 0;
    vector<int> *n1,*n2;
    if(getMedian(nums1)>getMedian(nums2)){
        if(nums1.size()%2 != 0){
            nums1.resize((nums1.size()+1)/2);
            nums2.erase(nums2.begin(),nums2.begin()+((nums2.size()+1)/2)-1);
        } else {
            int median1 = (int)getMedian(nums1);
            int median2 = (int)getMedian(nums2);
            nums1.resize(((nums1.size()+1)/2)-1);
            nums1.push_back(median1);
            nums2.erase(nums2.begin(),nums2.begin()+((nums2.size()+1)/2));
            nums2.at(0) = median2;
        }
    }
    return -1;
}






//
//  Third.cpp
//  LeetCode
//
//  Created by Shantanu Das on 24/10/15.
//  Copyright (c) 2015 Zakoi. All rights reserved.
//

#include "Third.h"
#include <tgmath.h>
#include <iostream>
using namespace std;

int length = -1;

double getMedian(vector<int>& num) {
    if(num.size()%2 != 0)
        return (double) num.at(((num.size()+1)/2)-1);
    else
        return (num.at(num.size()/2)+num.at(((num.size())/2)-1))/(double)2;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> *n1,*n2;
    if(length == -1){
        length = nums1.size()+nums2.size();
    }
    double median = returnFinalMedain(nums1,nums2);
    if (median!=-1) {
        return median;
    }
    if(nums1.size() != 1 && nums2.size() != 1) {
        n1 = (getMedian(nums1)>getMedian(nums2)) ? &nums1 : &nums2;
        n2 = (getMedian(nums1)>getMedian(nums2)) ? &nums2 : &nums1;
    } else if (nums1.size() == 1) {
        n1 = &nums2;
        n2 = &nums1;
    } else if (nums2.size() == 1) {
        n1 = &nums1;
        n2 = &nums2;
    }
    if(n1->size()%2 != 0){
        if(n1->size()>2)
            n1->resize((n1->size()+1)/2);
        if(n2->size()>2)
            n2->erase(n2->begin(),n2->begin()+((n2->size()+1)/2)-1);
    } else {
        int median1 = (int)getMedian(*n1);
        int median2 = (int)getMedian(*n2);
        if(n1->size()>2) {
            n1->resize(((n1->size()+1)/2));
            n1->push_back(median1);
        }
        if(n2->size()>2) {
            n2->erase(n2->begin(),n2->begin()+((n2->size()+1)/2)-1);
            n2->at(0) = median2;
        }
    }
    printVector(nums1);
    printVector(nums2);
    return findMedianSortedArrays(nums1,nums2);
}

double returnFinalMedain(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0) {
        if(nums2.size() == 0)
            return 0;
        else
            return getMedian(nums2);
    } else if(nums2.size() == 0) {
        return getMedian(nums1);
    } else if(nums1.size() == 1 && nums2.size() == 1) {
        return (double)(nums1.at(0)+nums2.at(0))/(double)2;
    } else if(nums1.size() < 3 && nums2.size() < 3) {
        int m1,m2;
        if(nums1.size() == 1){
            if(length%2!= 0) {
                m1 = max(nums2.at(1),max(nums1.at(0),nums2.at(0)));
                m2 = min(nums2.at(1),min(nums1.at(0),nums2.at(0)));
                return nums2.at(0)+nums2.at(1)+nums1.at(0) -m1 -m2;
            } else {
                m1 = max(nums1.at(0),nums2.at(0));
                m2 = nums2.at(1);
            }
        } else if(nums2.size() == 1){
            if(length%2!= 0) {
                m1 = max(nums1.at(1),max(nums1.at(0),nums2.at(0)));
                m2 = min(nums1.at(1),min(nums1.at(0),nums2.at(0)));
                return nums1.at(0)+nums1.at(1)+nums2.at(0) -m1 -m2;
            } else {
                m1 = max(nums1.at(0),nums2.at(0));
                m2 = nums1.at(1);
            }
        } else {
            m1 = max(nums1.at(0),nums2.at(0));
            m2 = min(nums1.at(1),nums2.at(1));
        }
        if(length%2 == 0)
            return (double)(m1+m2)/(double)2;
        else
            return max(m1,m2);
    }
    return -1;
}


void printVector(vector<int> vec){
    cout<<"\n";
    for(int i = 0; i < vec.size();i++)
        cout<<vec.at(i)<<" ";
}






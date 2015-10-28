//
//  Third.cpp
//  LeetCode
//
//  Created by Shantanu Das on 24/10/15.
//  Copyright (c) 2015 Zakoi. All rights reserved.
//
// 1 || 2 3 4 || 1 2 3
// 4 || 1 2 3 || 2 3 4
// 3 || 1 2 4 || 2 4 3
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
/*
double getNextMedian(vector<int>& num) {
    if(num.size()%2 != 0)
        return (double) num.at(((num.size()+1)/2)-1);
    else
        return (num.at(num.size()/2)+num.at(((num.size())/2)-1))/(double)2;
}*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> *n1,*n2;
    if(length == -1){
        length = (int)(nums1.size()+nums2.size());
    }
    double median = returnFinalMedain(nums1,nums2);
    if (median!=-1) {
        return median;
    }
    n1 = (getMedian(nums1)>getMedian(nums2)) ? &nums1 : &nums2;
    n2 = (getMedian(nums1)>getMedian(nums2)) ? &nums2 : &nums1;
    
    if(n1->size()%2 != 0){
        if(n1->size()>2)
            n1->resize((n1->size()+1)/2);
        if(n2->size()>2)
            n2->erase(n2->begin(),n2->begin()+((n2->size()+1)/2)-1);
    } else {
//        int median1 = (int)getMedian(*n1);
//        int median2 = (int)getMedian(*n2);
        if(n1->size()>2) {
            n1->resize(((n1->size()+1)/2)+1);
            //n1->push_back(median1);
        }
        if(n2->size()>2) {
            n2->erase(n2->begin(),n2->begin()+((n2->size()+1)/2)-1);
            //n2->at(0) = median2;
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
    } else if(nums1.size()+ nums2.size() <= 4) {
        int m1,m2;
        if(nums1.size() == 1){
            if(length%2!= 0) {
                if(nums2.size() == 3)
                    return -1;
                m1 = max(nums2.at(1),max(nums1.at(0),nums2.at(0)));
                m2 = min(nums2.at(1),min(nums1.at(0),nums2.at(0)));
                return nums2.at(0)+nums2.at(1)+nums1.at(0) -m1 -m2;
            } else {
                m1 = max(max(nums1.at(0),max(nums2.at(0),nums2.at(1))),nums2.at(2));
                m2 = min(min(nums1.at(0),min(nums2.at(0),nums2.at(1))),nums2.at(2));
                return (double)(nums2.at(0)+nums2.at(1)+nums2.at(2) + nums1.at(0) -m2 -m1)/(double)2;
            }
        } else if(nums2.size() == 1){
            if(length%2!= 0) {
                if(nums1.size() == 3)
                    return -1;
                m1 = max(nums1.at(1),max(nums1.at(0),nums2.at(0)));
                m2 = min(nums1.at(1),min(nums1.at(0),nums2.at(0)));
                return nums1.at(0)+nums1.at(1)+nums2.at(0) -m1 -m2;
            } else {
                m1 = max(max(nums2.at(0),max(nums1.at(0),nums1.at(1))),nums1.at(2));
                m2 = min(min(nums2.at(0),min(nums1.at(0),nums1.at(1))),nums1.at(2));
                return (double)(nums1.at(0)+nums1.at(1)+nums1.at(2) + nums2.at(0) -m1 -m2)/(double)2;
            }
        }
        
        m1 = max(nums1.at(0),nums2.at(0));
        m2 = min(nums1.at(1),nums2.at(1));
        if(length%2 == 0)
            return (double)(m1+m2)/(double)2;
        else
            return max(m1,m2);
    }else if (nums1.size() == 1 || nums2.size() == 1) {
        vector<int> *nLow,*nHigh;
        if(nums1.size() == 1) {
            nLow = &nums1;
            nHigh = &nums2;
        } else {
            nLow = &nums2;
            nHigh =  &nums1;
        }
        
        if(length%2!= 0) {
            if(nLow->at(0) < nHigh->at(((nHigh->size())/2)-1))
                return nHigh->at(((nHigh->size())/2)-1);
            else if (nLow->at(0) > nHigh->at(((nHigh->size())/2)))
                return nHigh->at(((nHigh->size())/2));
            else
                return nLow->at(0);
        } else {
            if (nLow->at(0) < nHigh->at(((nHigh->size()+1)/2)-2))
                return (double)(nHigh->at(((nHigh->size()+1)/2)-2)+nHigh->at(((nHigh->size()+1)/2)-1))/(double)2;
            else if (nLow->at(0) > nHigh->at(((nHigh->size()+1)/2)))
                return (double)(nHigh->at(((nHigh->size()+1)/2))+nHigh->at(((nHigh->size()+1)/2)-1))/(double)2;
            else
                return (double)(nLow->at(0)+nHigh->at(((nHigh->size()+1)/2)-1))/(double)2;
        }
    }
    return -1;
}


void printVector(vector<int> vec){
    cout<<"\n";
    for(int i = 0; i < vec.size();i++)
        cout<<vec.at(i)<<" ";
}





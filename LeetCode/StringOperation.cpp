//
//  StringOperation.cpp
//  LeetCode
//
//  Created by Shantanu Das on 22/10/15.
//  Copyright (c) 2015 Zakoi. All rights reserved.
//

#include "StringOperation.h"
#include <ext/hash_map>
#include <list>
using namespace std;

int lengthOfLongestSubstring(std::string s){
    int maxLength = 0,length = 0,index = 1,lastIndex = 0;
    int alpha[128] = {};
    for(int i = 0; i < s.length(); i++){
        if(alpha[(int)s[i]] != index){
            alpha[(int)s[i]] = index;
            length++;
        } else {
            for(int j = lastIndex ; j < i ; j++){
                if(s[j] == s[i]){
                    i = j;
                    lastIndex = i+1;
                }
            }
            index += 1;
            maxLength = (maxLength<length) ? (int)length : maxLength;
            length = 0;
        }
    }
    
    maxLength = (maxLength<length) ? (int)length : maxLength;
    return maxLength;
}


std::string longestPalindrome(std::string s) {
    if(s.length() == 1)
        return s;
    
    int low = 0,high =2;
    std::string final;
    for(int i = 0; i < s.length();i++){
        low = i-1;
        high = i+1;
        if(s[low] == s[high]){
            std::string temp = palindrome(low, high, s);
            if(temp.length() > final.length()){
                final = temp;
            }
        } else if(s[i]== s[high]){
            while(s[i]==s[high] && high < s.length()){
                high += 1;
            }
            i = high - 1;
            std::string temp = palindrome(low+1, high-1, s);
            if(temp.length() > final.length()){
                final = temp;
            }
            if(final.length() > (s.length() - (i+1)) * 2)
                return final;
        }
    }
    return final;
}

std::string palindrome(int low,int high, std::string &s){
    low--;
    high++;
    
    if(low < 0){
        low = -1;
        //cout<<s[0];
    }
    if(low<0 || high >= s.length()){
        return s.substr(low+1,high - low - 1);
    } else if(s[low] != s[high]) {
        return s.substr(low+1,high - low - 1);
    } else {
        return palindrome(low, high, s);
    }
    return "\0";
}/*
std::string convert(std::string s, int numRows) {
    std::string
    for(int i = 0; i < s.length();i++){
        if((i+1)%4 == 1) {
            
        }
    }
    return "ciw";
}*/
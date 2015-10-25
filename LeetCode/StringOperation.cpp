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
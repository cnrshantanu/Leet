//
//  StringOperation.h
//  LeetCode
//
//  Created by Shantanu Das on 22/10/15.
//  Copyright (c) 2015 Zakoi. All rights reserved.
//

#ifndef __LeetCode__StringOperation__
#define __LeetCode__StringOperation__

#include <stdio.h>
#include <iostream>

int lengthOfLongestSubstring(std::string s);
std::string palindrome(int low,int high, std::string &s);
std::string longestPalindrome(std::string s);
std::string longestPalindrome(std::string s,bool _val);

#endif /* defined(__LeetCode__StringOperation__) */

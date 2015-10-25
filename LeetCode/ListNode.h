//
//  ListNode.h
//  LeetCode
//
//  Created by Shantanu Das on 22/10/15.
//  Copyright (c) 2015 Zakoi. All rights reserved.
//

#ifndef __LeetCode__ListNode__
#define __LeetCode__ListNode__

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *list);
ListNode* addTwoNumbers(ListNode* l1,ListNode* l2);
ListNode* populate(int a[],int size);

#endif /* defined(__LeetCode__ListNode__) */

//
//  ListNode.cpp
//  LeetCode
//
//  Created by Shantanu Das on 22/10/15.
//  Copyright (c) 2015 Zakoi. All rights reserved.
//

#include "ListNode.h"
#include <iostream>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
    ListNode *temp = NULL,*start = NULL;
    int carry = 0;
    
    temp = new ListNode(l1->val+l2->val);
    start = temp;
    l1 = l1->next;
    l2 = l2->next;
    carry = temp->val / 10;
    temp->val = temp->val % 10;
    
    while(l1 != NULL || l2!= NULL){
        if(l1 == NULL){
            
            temp->next = new ListNode(l2->val+carry);
            l2 = l2->next;
            if(temp->next->val <10){
                temp->next->next = l2;
                return start;
            }
            
        } else if(l2 == NULL){
            temp->next = new ListNode(l1->val+carry);
            l1 = l1->next;
            if(temp->next->val <10){
                temp->next->next = l1;
                return start;
            }
        } else {
            temp->next = new ListNode(l1->val+l2->val+carry);
            l1 = l1->next;
            l2 = l2->next;
        }
        
        temp = temp->next;
        carry = temp->val / 10;
        temp->val = temp->val % 10;
        
    }
    if(carry > 0){
        temp->next = new ListNode(carry);
    }
    return start;
}

ListNode* populate(int a[],int size){
    ListNode *temp = nullptr,*start;
    temp = new ListNode(a[0]);
    start = temp;
    for(int i = 1;i<size;i++){
        temp->next = new ListNode(a[i]);
        temp = temp->next;
    }
    return start;
}

void printList(ListNode *list){
    cout<<"List starts \n";
    while (list!= NULL) {
        cout<<list->val<<"\n";
        list = list->next;
    }
    cout<<"List ends \n";
}
//
//  main.cpp
//  LeetCode
//
//  Created by Shantanu Das on 22/10/15.
//  Copyright (c) 2015 Zakoi. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode *list);
ListNode* addTwoNumbers(ListNode* l1,ListNode* l2);
ListNode* populate(int a[],int size);

int main(int argc, const char * argv[]) {
    
    int number1[] = {2,6,6,3};
    int number2[] = {5,6,4};
    ListNode* l1 = populate(number1,4);
    ListNode* l2 = populate(number2,3);
    printList(addTwoNumbers(l1, l2));
    return 0;
}

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
        int val1,val2;
        val1 = (l1 == NULL) ? 0 : l1->val;
        val2 = (l2 == NULL) ? 0 : l2->val;
        temp->next = new ListNode(val1+val2+carry);
        l1 = (l1 == NULL) ? NULL : l1->next;
        l2 = (l2 == NULL) ? NULL : l2->next;
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

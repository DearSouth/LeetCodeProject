#include<iostream>
#include <vector>

using namespace std;
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

    }
};
//int main()
//{
//    //vector<int> value = { 1, 3, 2, 8, 4, 9 };2.00000
//
//    Solution so;
//
//    ListNode p1(1);
//    ListNode p2(2, &p1);
//    ListNode p3(3, &p2);
//    ListNode p4(4, &p3);
//    ListNode p5(5, &p4);
//    ListNode p6(6, &p5);
//    ListNode p7(7, &p6);
//    ListNode p8(8, &p7);
//    ListNode head(0, &p8);
//    ListNode* temp = &head;
//    while (temp != nullptr)
//    {
//        cout << temp->val << endl;
//        temp = temp->next;
//    }
//   // ListNode* result = so.reverseKGroup(&head, 3);
//   
//    return 0;
//}
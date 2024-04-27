/*该题难点在于如何找到两个链表的交点，可以通过计算两个链表的长度，
然后让长的链表先走两个链表长度的差值，然后两个链表同时走，若有相同节点则返回*/
#include <array>
class Solution{
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr){} 
    };

    ListNode *getIntetsectionNode(ListNode *headA,ListNode * headB){
        //获取两个链表的长度
        int lenA = 0;
        int lenB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while(curA){
            lenA++;
            curA=curA->next;
        }
        while(curB){
            lenB++;
            curB=curB->next;
        }
        //其中长的链表定义为curA，短的链表定义为curB
        #include <algorithm> // Include the <algorithm> header for std::swap

        curA = headA;
        curB = headB;

        if (lenA < lenB) {
            std::swap(curA, curB); // Use std::swap instead of swap
            std::swap(lenA, lenB); // Use std::swap instead of swap
        }

        //获取长度差
        int gap = lenA - lenB;

        //长链表先走gap步
        while (gap--) {
            curA = curA->next;
        }

        //遍历两个链表，若有相同节点则返回
        while(curA){
            if(curA==curB){
                return curA;
            }
            curA=curA->next;
            curB=curB->next;
        }
    return nullptr;
    }
};


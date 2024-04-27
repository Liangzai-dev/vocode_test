using namespace std;
#include<iostream>
class Solution{
public:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr){};
    };
    ListNode* deleteNthFromEnd(ListNode *Head ,int n){//函数要有返回值，
        //否则如果删除的第一个结点，返回值为空，会报错
        ListNode * dummyHead=new ListNode(0);
        dummyHead->next=Head;
        //让fast走n+1步，这样当fast走到链表末尾时，slow指向待删除节点的前一个节点
        ListNode * fast=Head;
        ListNode * slow=Head;
        while(n-- && fast !=nullptr){
            fast=fast->next;
        }

        fast=fast->next;

        //fast和slow同时移动
        while(fast!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *tmp=slow->next;
        slow->next=slow->next->next;

        delete tmp;

        return dummyHead->next;
    }

    void printList(ListNode* Head){
        ListNode *cur=Head;
        while(cur!=nullptr){
            cout<<cur->val<<"->";
            cur=cur->next;
        }
    }
};

int main(){
    Solution::ListNode *Head=new Solution::ListNode(1);
    Solution::ListNode *node1=new Solution::ListNode(2);
    Solution::ListNode *node2=new Solution::ListNode(3);
    Solution::ListNode *node3=new Solution::ListNode(4);
    Solution::ListNode *node4=new Solution::ListNode(5);
    
    Head->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;

    Solution s;
    s.printList(Head);
    cout<<endl;

    s.deleteNthFromEnd(Head,2);
    s.printList(Head);
}


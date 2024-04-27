#include <iostream>
using namespace std;
class Solution{
    public:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr){};
    };
    ListNode * reveseList(ListNode * Head){
        //定义一个cur指针，指向头结点，定义一个pre指针，初始化为NULL
        ListNode *cur=Head;
        ListNode * pre=nullptr;
        //定义一个tmp指针，用于保存cur的下一个节点
        ListNode * tmp=nullptr;
        while (cur){
            //然后让cur的next指向pre
            tmp=cur->next;
            cur->next=pre;
            //pre和cur节点都前进一步
            pre=cur;
            cur=tmp;
        }
        return pre;        
    }
    
    //打印链表
    void printList(ListNode* Head){
        ListNode * cur=Head;
        while(cur){
            cout<<cur->val<<"->";
            cur=cur->next;
        }
    }

};

int main(){
    Solution s;

    Solution::ListNode * Head=new Solution::ListNode(1);
    Solution::ListNode * node1=new Solution::ListNode(2);
    Solution::ListNode * node2=new Solution::ListNode(3);
    Solution::ListNode * node3=new Solution::ListNode(4);
    
    Head->next=node1;
    node1->next=node2;
    node2->next=node3;

    s.printList(Head);
    cout<<endl;
    Solution::ListNode * newHead=new Solution::ListNode(0);
    newHead=s.reveseList(Head);
    s.printList(newHead);
}
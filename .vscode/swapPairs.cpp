#include<iostream>
using namespace std;

class Solution{
    public:
    struct ListNode{
        int val;
        ListNode * next;
        ListNode(int x):val(x),next(nullptr){};
    };
    ListNode *swapPairs(ListNode* Head){
        //设置一个虚拟头结点，cur指向虚拟头结点
            ListNode *dummyHead=new ListNode(0);
            dummyHead->next=Head;
            ListNode * cur=dummyHead;

        while (cur->next !=nullptr && cur->next->next!=nullptr) {                
            ListNode *tmp =nullptr;
            ListNode * tmp1=nullptr;
            tmp=cur->next;
            tmp1=cur->next->next->next;

            cur->next=cur->next->next;//cur->next指向第二个节点,步骤一
            cur->next->next=tmp;//第二个节点指向第一个节点，步骤二
            cur->next->next->next=tmp1;//第一个节点指向第三个节点，步骤三

            cur=cur->next->next;
        }
        return dummyHead->next;
        delete dummyHead;
        
    }

    void printList(ListNode* Head){
        ListNode * cur=Head;
        while(cur!=nullptr){//这里不能用cur->next!=nullptr,因为最后一个节点的next是nullptr
        //条件判断也不能使用while(cur)
            cout<<cur->val<<"->";
            cur=cur->next;
        }

    }
};
int main(){
    Solution::ListNode*Head=new Solution::ListNode(0);
    Solution::ListNode*node1=new Solution::ListNode(1);
    Solution::ListNode*node2=new Solution::ListNode(2);
    Solution::ListNode*node3=new Solution::ListNode(3);

    Head->next=node1;
    node1->next=node2;
    node2->next=node3;

    Solution s;
    s.printList(Head);
    cout<<endl;

    Solution::ListNode*newHead=new Solution::ListNode(0);
    newHead=s.swapPairs(Head);
    s.printList(newHead);
}






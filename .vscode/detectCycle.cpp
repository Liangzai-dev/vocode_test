class Solution{
public:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr){}
    };
    
    ListNode *  detectCycle(ListNode * head){
        //定义两个快慢指针，每次快指针走两步，慢指针走一步
        ListNode *fast=head;
        ListNode *slow=head;
        //1、判断是否有环
        //若有环，则快慢指针一定会相遇
        while(fast!=nullptr&&fast->next!=nullptr){
        /*注意这里的判断条件:
        *例如当没有环时，fast遍历到倒数第二个节点时，进入while循环，此时fast->next->next为nullptr,不会进入下一次
        *当fast遍历到最后一个节点时，进入while循环，此时fast->next为nullptr,不会进入下一次循环*/
            fast=fast->next->next;
            slow=slow->next;
            /*记录下快慢指针相遇的点，然后让一个指针从头开始走，另一个指针从相遇点开始走，
            每次走一步，再次相遇的点就是环的入口*/
            if(fast==slow){
                ListNode *index1=head;
                ListNode *index2=fast;
                while(index1!=index2){
                    index1=index1->next;
                    index2=index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
#include <cstddef>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};


// class Solution{
//     public:
//     ListNode *removeElements(ListNode* head,int val){
//         //删除头结点
//         while(head!=NULL && head->val==val){
//             ListNode *tmp=head;//保存头结点,用于删除
//             head->next=head;
//             delete tmp;
//         }

//         //删除非头结点
//         ListNode *cur=head;
//         while(cur!=NULL && cur ->next!=NULL){
//             if(cur->next->val==val){
//                 ListNode * tmp =cur->next;
//                 cur->next=cur->next->next;
//                 delete tmp;
//             }else{
//                 cur=cur->next;
//             }
//         }
//     }
// };

class Solution{
    public:
    ListNode *removeElements(ListNode *head,int val){

        //定义一个虚拟头结点
        ListNode*dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode * cur=dummyHead;
        while(cur!=NULL && cur->next!=NULL){
            if(cur->next->val==val){
                ListNode *tmp=cur->next;
                cur->next=cur->next->next;
                delete tmp;
            }else{
                cur=cur->next;
            }
        }
    }
};
#include<iostream>
using namespace std;

class MyLinkedList{
    public:
    //定义链表节点结构体
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x):val(x),next(nullptr){};
    };
    //初始化链表
    MyLinkedList(){
        _dummyHead=new ListNode(0);
        _size=0;
    }

    //获取链表中第index个节点的值
    int get(int index){
        if(index<0||index>=_size){
            return -1;
        }
        ListNode* cur=_dummyHead->next;
        while(index--){
            cur=cur->next;
        }
        return cur->val;
    }

    //在链表头部插入一个新节点，插入完成后，新插入的结点为链表新的头结点
    void addAtHead(int val){
        ListNode *newNode=new ListNode(val);
        newNode->next=_dummyHead->next;
        _dummyHead->next=newNode;
        _size++;        
    }

    //在链表最后面添加一个结点
    //如何判断链表的最后一个结点？链表的最后一个结点的next指针指向NULL
    void addAtTail(int val){
        ListNode *cur=_dummyHead;
        ListNode *newNode=new ListNode(val);
        while(cur->next!=nullptr){
            cur=cur->next;
        }
        cur->next=newNode;
        _size++;
    }

    //在链表的第index个节点之前添加一个新节点，插入完成后，新插入的结点为第index个结点
    
    //如果index等于链表的长度，则直接在链表的最后面添加一个节点
    
    //如果index等于0，则在头结点插入一个新节点
    void addAtIndex(int index,int val){
        if(index>_size){//如果index大于链表的长度，则直接返回
            return;
        }
        if(index<0){//如果index小于0，则在头结点插入一个新节点
            index=0;
        }
        ListNode * cur=_dummyHead;
        ListNode * newNode=new ListNode(val);
        while(index--){
            cur=cur->next;
        }
        cur->next=newNode;
        _size++;
    }

    //删除链表中的第index个节点，如果index大于等于链表的长度，则直接返回
    void deleteAtindex(int index){
        if(index<0||index>=_size){
            return;
        }

        ListNode * cur=_dummyHead;
        while(index--){
            cur=cur->next;
        }
        ListNode* tmp=cur->next;
        cur->next=cur->next->next;

        delete tmp;  
        tmp=nullptr;
        //delete命令指示释放了tmp指针原本所指的那部分内存
        //被delete后的指针tmp的值并非就是NULL，而是一个随机值
        //也就是如果delete后，如果不再加上一句tmp=NULL，那么tmp指针就会变成一个野指针
        ////如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        _size--; 
    }
    //打印链表
    void print(){
        ListNode* cur=_dummyHead->next;
        while(cur->next!=nullptr){
            cout<<cur->val<<"->";
            cur=cur->next;
        }
    }

    

    private:
    ListNode* _dummyHead;
    int _size;
};
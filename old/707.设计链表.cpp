/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
// @lc code=start
class MyLinkedList {
    struct ListNode{
        int val;
        ListNode* nxt;
        ListNode(int x):val(x),nxt(nullptr){}
    };
    
    ListNode* dummyHead;
    int size;
    
public:
    MyLinkedList() {
        dummyHead=new ListNode(0);
        size=0;
    }
    
    int get(int index) {
        if(index>=size) return -1;
        ListNode* cur=dummyHead->nxt;
        for(int i=0;i<index;i++){
            cur=cur->nxt;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>size||index<0) return ;
        ListNode* pre=dummyHead;
        for(int i=0;i<index;i++){
            pre=pre->nxt;
        }
        
        ListNode* newNode= new ListNode(val);
        newNode->nxt=pre->nxt;
        pre->nxt=newNode;
        size++;
        return ;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size) return ;
        ListNode* pre=dummyHead;
        for(int i=0;i<index;i++){
            pre=pre->nxt;
        }
        auto cur=pre->nxt;
        pre->nxt=pre->nxt->nxt;
        delete cur;
        size--;
        return ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end


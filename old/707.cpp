/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr){} 
    };
    MyLinkedList() {
        _dummyHead=new ListNode(0);
        _size=0;
    }
    
    int get(int index) {
        if(index<0||index>=_size){
            return -1;
        }
        ListNode* curPtr=_dummyHead->next;
        for (int i=0;i<index;i++){
            curPtr=curPtr->next;
        }
        return curPtr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode=new ListNode(val);
        newNode->next=_dummyHead->next;
        _dummyHead->next=newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode=new ListNode(val);
        ListNode* curPtr=_dummyHead;
        while (curPtr->next!=nullptr){
            curPtr=curPtr->next;
        }
        curPtr->next=newNode;
        newNode->next=nullptr;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index>_size){
            return;
        }
        ListNode* newNode=new ListNode(val);
        ListNode* curPtr=_dummyHead;
        for (int i=0;i<index;i++){
            curPtr=curPtr->next;
        }
        newNode->next=curPtr->next;
        curPtr->next=newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index<0||index>=_size){
            return;
        }
        ListNode* curPtr=_dummyHead;
        for (int i=0;i<index;i++){
            curPtr=curPtr->next;
        }
        curPtr->next=curPtr->next->next;
        _size--;
    }
private:
    int _size;
    ListNode* _dummyHead;
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
int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->get(1);
    obj->deleteAtIndex(1);
    obj->get(1);
    return 0;
}

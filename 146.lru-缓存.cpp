/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include "0.cpp"
// @lc code=start
class Node{
public:
    int key;
    int val;
    Node* pre;
    Node* nxt;
    Node(int k=0,int v=0): key(k),val(v) {}
};
class LRUCache {
private:
    int capacity;
    Node* dummyHead=nullptr;
    unordered_map<int,Node*> key_to_Node;
    void remove(Node* x){
        x->pre->nxt=x->nxt;
        x->nxt->pre=x->pre;
    }
    void push_front(Node* x){
        x->pre=dummyHead;
        x->nxt=dummyHead->nxt;
        x->pre->nxt=x;
        x->nxt->pre=x;
    }
    Node* get_node(int key){
        auto it =key_to_Node.find(key);
        if(it==key_to_Node.end())
            return nullptr;
        Node* node=it->second;
        remove(node);
        push_front(node);
        return node;
    }
public:
    LRUCache(int capacity) : capacity(capacity), dummyHead(new Node()) {
        dummyHead->pre=dummyHead;
        dummyHead->nxt=dummyHead;
    }
    
    int get(int key) {
        Node* node=get_node(key);
        return node?node->val:-1;
    }
    
    void put(int key, int value) {
        Node* node =get_node(key);
        if(node){
            node->val=value;
            return ;
        }
        key_to_Node[key]=node=new Node(key,value);
        push_front(node);
        if (key_to_Node.size() > capacity) { // 书太多了
            Node* back_node = dummyHead->pre;
            key_to_Node.erase(back_node->key);
            remove(back_node); // 去掉最后一本书
            delete back_node; // 释放内存
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


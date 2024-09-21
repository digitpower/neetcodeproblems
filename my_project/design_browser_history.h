#pragma once
#include <string>
#include <sstream>
using namespace std;
class BrowserHistory {
private:
    struct ListNode
    {
        ListNode(string _val = "") : val(_val) {}
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        string val;
    };
    ListNode* m_dummyHead;
    ListNode* m_dummyTail;
    ListNode* m_curr = nullptr;
    void insertBetweenNodes(ListNode* node, ListNode* leftNode, ListNode* rightNode)
    {
        node->prev = leftNode;
        node->next = rightNode;
        leftNode->next = node;
        rightNode->prev = node;
    }
public:
    BrowserHistory(string homepage) {
        //Init and link dummy nodes
        m_dummyHead = new ListNode();
        m_dummyTail = new ListNode();
        m_dummyHead->next = m_dummyTail;

        //Create first element
        ListNode* newNode = new ListNode(homepage);
        insertBetweenNodes(newNode, m_dummyHead, m_dummyTail);

        m_curr = newNode;
    }
    
    void visit(string url) {
        ListNode* newNode = new ListNode(url);
        insertBetweenNodes(newNode, m_curr, m_dummyTail);
        m_curr = newNode;
    }
    
    string back(int steps) {
        
    }
    
    string forward(int steps) {
        
    }

    std::string ToStrReverse()
    {
        ListNode* p = m_dummyTail->prev;
        std::ostringstream out;
        while(p != m_dummyHead)
        {
            out << p->val;
            if(p->prev != m_dummyHead)
                out << " ";
            p = p->prev;
        }
        return out.str();
    }

    std::string ToStr()
    {
        ListNode* p = m_dummyHead->next;
        std::ostringstream out;
        while(p != m_dummyTail)
        {
            out << p->val;
            if(p->next != m_dummyTail)
                out << " ";
            p = p->next;
        }
        return out.str();
    }

};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
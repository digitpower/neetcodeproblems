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


        ListNode* nextNode = m_curr->next;
        while(nextNode != m_dummyTail)
        {
            ListNode* forDeletion = nextNode;
            nextNode = nextNode->next;
            delete forDeletion;
        }



        insertBetweenNodes(newNode, m_curr, m_dummyTail);
        m_curr = newNode;
    }
    
    string back(int steps) {
        int counter = 0;
        while(counter < steps && m_curr->prev != m_dummyHead)
        {
            m_curr = m_curr->prev;
            counter++;
        }
        return m_curr->val;
    }
    
    string forward(int steps) {
        int counter = 0;
        while(m_curr->next != m_dummyTail && counter < steps)
        {
            counter++;
            m_curr = m_curr->next;
        }
        return m_curr->val;
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
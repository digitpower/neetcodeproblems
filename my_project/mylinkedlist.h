#include <sstream>
class MyLinkedList {
private:
    struct ListNode {
        ListNode(int _val) : val(_val)
        {}
        ListNode* next;
        ListNode* prev;
        int val;
    };
    ListNode* m_head = nullptr; 
    ListNode* m_tail = nullptr;
public:
    MyLinkedList() {

    }

    int get(int index) {
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        if(m_head == nullptr)
            m_head = m_tail = newNode;
        else
        {
            newNode->next = m_head;
            m_head = newNode;
        }
    }

    void addAtTail(int val) {
    }

    void addAtIndex(int index, int val) {

    }

    void deleteAtIndex(int index) {
    }

    std::string ToStr()
    {
        ListNode* p = m_head;
        std::ostringstream out;
        while(p != nullptr)
        {
            out << p->val;
            if(p->next != nullptr)
                out << " ";
            p = p->next;
        }
        return out.str();
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
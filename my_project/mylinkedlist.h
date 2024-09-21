#include <sstream>
class MyLinkedList {
private:
    struct ListNode {
        ListNode(int _val) : val(_val)
        {}
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        int val;
    };
    ListNode* m_head = nullptr; 
    ListNode* m_tail = nullptr;
public:
    MyLinkedList() {

    }

    int get(int index) {
        int counter = 0;
        ListNode* tmp = m_head;
        for (; tmp != nullptr && counter < index; counter++)
            tmp = tmp->next;
        if(tmp == nullptr)
            return -1;
        return tmp->val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        if(m_head == nullptr)
            m_head = m_tail = newNode;
        else
        {
            newNode->next = m_head;
            m_head->prev = newNode;
            m_head = newNode;
        }
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(m_tail == nullptr)
            m_head = m_tail = newNode;
        else
        {
            m_tail->next = newNode;
            newNode->prev = m_tail;
            m_tail = newNode;
        }
    }

    void addAtIndex(int index, int val) {
        if(index < 0)
            return;
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* tmp = m_head;
        int indexCounter = 0;
        while(indexCounter < index && tmp != nullptr)
        {
            tmp = tmp->next;
            indexCounter++;
        }

        if(tmp == nullptr)
        {
            //Index at the end
            if(indexCounter == index)
            {
                addAtTail(val);
            }
            //Index too large
            return;
        }

        ListNode* nextNode = tmp;
        ListNode* prevNode = tmp->prev;

        newNode->next = nextNode;
        newNode->prev = prevNode;

        prevNode->next = newNode;
        nextNode->prev = newNode;

    }

    void deleteAtIndex(int index) {
        if(index < 0)
            return;
        int indexCounter = 0;
        ListNode* tmp = m_head;
        while(indexCounter < index && tmp != nullptr)
        {
            tmp = tmp->next;
            indexCounter++;
        }
        if(tmp == nullptr)
            return;

        ListNode* prev = tmp->prev;
        ListNode* next = tmp->next;

        if(prev != nullptr && next != nullptr)
        {
            prev->next = next;
            next->prev = prev;
        }
        else if(prev == nullptr)
        {
            if(next != nullptr)
            {
                next->prev = nullptr;
                m_head = next;
            }
            else
                m_head = m_tail = nullptr;
        }
        else
        {
            if(prev != nullptr)
            {
                prev->next = nullptr;
                m_tail = prev;
            }
            else
                m_head = m_tail = nullptr;
        }

        delete tmp;
    }

    std::string ToStrReverse()
    {
        ListNode* p = m_tail;
        std::ostringstream out;
        while(p != nullptr)
        {
            out << p->val;
            if(p->prev != nullptr)
                out << " ";
            p = p->prev;
        }
        return out.str();
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
#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

class ListQueue
{
public:
    ListQueue():size(0)
    {
        this->pHead = nullptr;
        this->pTail = nullptr;
    }

    bool enqueue(int item)
    {
        ListNode* pNode = new ListNode();
        pNode->m_nValue = item;
        if (this->pHead == nullptr && this->pTail == nullptr)
        {
            this->pHead = pNode;
            this->pTail = pNode;
        }
        else
        {
            this->pTail->m_pNext = pNode;
            this->pTail = this->pTail->m_pNext;
        }
        size++;

        return true;
    }

    int dequeue()
    {
        int retValue = this->pHead->m_nValue;
        this->pHead = this->pHead->m_pNext;
        size--;

        return retValue;
    }

    int getSize()
    {
        return size;
    }
protected:
private:
    ListNode* pHead;
    ListNode* pTail;
    int size;
};

void test1()
{
    int array[5] = { 1, 2, 3, 4, 5 };
    int size = sizeof(array) / sizeof(int);
    ListQueue listQueue;
    for (int i = 0; i < size; i++)
    {
        listQueue.enqueue(array[i]);
    }

    cout << "queue data is: "<< endl;
    size = listQueue.getSize();
    for (int i = 0; i < size; i++)
    {
        int retValue = listQueue.dequeue();
        cout << retValue << " ";
    }
    
}

int main(int argc, char** argv)
{
    test1();
    while (1)
    {
    }
    return 0;
}
#include <iostream>
#include "LinkStack.hpp"

using namespace std;

int main(int argc, char** argv)
{
    LinkStack<int> linkStack;
    cout << "push data into stack:" << endl;
    for (int i = 1; i < 10; i++)
    {
        linkStack.push(i);
        cout << i << " ";
    }
    cout << endl;
    cout << "pop data out to stack:" << endl;
    size_t size = linkStack.getSize();
    for (int i = 0; i < size; i++)
    {
        int retValue = linkStack.top();
        linkStack.pop();
        cout << retValue << " ";
    }
    
    getchar();
    return 0;
}
#include <iostream>

using namespace std;

class ArrayQueue
{
public:
	ArrayQueue()
	{

	}

	ArrayQueue(int size):head(0),tail(0), capacity(0)
	{
		arrayQueue = new int[size];
		capacity = size;
	}

	bool enqueue(int item)
	{
		if (tail == capacity)
		{
			if (head == 0)
			{
                cout << "the queue is full, can not enqueue!!!" << endl;
				return false;
			}
				
			cout << "the queue is at the end position, start move data......"<< endl;
			for (int i = head; i < tail; i++)
			{
				arrayQueue[i - head] = arrayQueue[i];
			}

			tail -= head;
			head = 0;
		}
			
		arrayQueue[tail] = item;
		tail++;
		return true;
	}

	int dequeue()
	{
		if (tail == head)
			return -1;
		int retValue = arrayQueue[head];
		head++;
		return retValue;
	}

    int getSize()
    {
        return tail - head;
    }
protected:
private:
	int head;
	int tail;
	int capacity;
	int *arrayQueue;
};

void test1()
{
	cout << endl << "test1 running......"<< endl;
	int array[5] = { 1, 2, 3, 4, 5 };
	int size = sizeof(array) / sizeof(int);
	ArrayQueue queue(size);
	for (int i = 0; i < size; i++)
	{
		queue.enqueue(array[i]);
	}

	cout << "queue data is: " << endl;
	for (int i = 0; i < 5; i++)
	{
		int retValue = queue.dequeue();
		cout << retValue << " ";
	}
}

void test2()
{
	cout << endl << "test2 running......"<< endl;
	int array[5] = { 1, 2, 3, 4, 5 };
	int size = sizeof(array) / sizeof(int);
	ArrayQueue queue(size);
	for (int i = 0; i < size; i++)
	{
		queue.enqueue(array[i]);
	}

	int num = queue.dequeue();
	cout << "get data1 is:"<< num << endl;
	num = queue.dequeue();
	cout << "get data2 is:" << num << endl;

	queue.enqueue(6);
    queue.enqueue(7);

    cout << "queue data is: " << endl;
    size = queue.getSize();
    for (int i = 0; i < size; i++)
    {
        int retValue = queue.dequeue();
        cout << retValue << " ";
    }
}

int main(int argc, char** argv)
{
	test1();
    test2();
	while (1)
	{
	}
	return 0;
}
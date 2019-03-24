#include <iostream>
#include <string>

using namespace std;

//ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(1)
class Solution
{
public:
	bool palindromeDetect(char* string, int length)
	{
		if (string == nullptr || length <= 0)
		{
			cout << "input format invalid!!!"<< endl;
			return false;
		}
		char* front = string;
		char* back = string + length - 1;
		while (front < back)
		{
			if (*front != *back)
			{
				return false;
			}
			++front;
			--back;
		}

		return true;
	}
protected:
private:
};

void test(char* string, int length, bool expectedValue)
{
	Solution solution;
	bool returnValue = solution.palindromeDetect(string, length);
	if (returnValue == expectedValue)
	{
		cout << "Passed......"<< endl;
	}
	else
	{
		cout << "Failed!!!!!!"<< endl;
	}
}

//����Ϊ�����Ļ����ַ���
void test1()
{
	cout << "test1 running......"<< endl;
	char* string = "madam";
	test(string, strlen(string), true);
}

//����Ϊż���Ļ����ַ���
void test2()
{
	cout << "test2 running......" << endl;
	char* string = "maddam";
	test(string, strlen(string), true);
}

//���ǻ����ַ���
void test3()
{
	cout << "test3 running......" << endl;
	char* string = "madamaadd";
	test(string, strlen(string), false);
}

//��ָ�����
void test4()
{
	cout << "test4 running......" << endl;
	char* string = "madamaadd";
	test(nullptr, 0, false);
}

int main(int argc, char** argv)
{
	test1();
	test2();
	test3();
	test4();
	while (1)
	{
	}
	return 0;
}
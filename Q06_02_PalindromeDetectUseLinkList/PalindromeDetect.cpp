#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
	char m_cValue;
	ListNode* m_pNext;
};

void addDataToTail(ListNode** pHead, char value)
{
	ListNode* pNew = new ListNode();
	pNew->m_cValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

void releaseList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void printList(ListNode* pHead)
{
	cout << endl << "link list in order:" << endl;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->m_cValue;
		pNode = pNode->m_pNext;
		if (pNode != nullptr)
		{
			cout << " -> ";
		}
		else
		{
			cout << " -> null" << endl;
		}
	}
}

ListNode* createSingleList(char* string, int length)
{
	ListNode* pNode = nullptr;
	char* getChar = string;
	for (int i = 0; i < length; i++)
	{
		addDataToTail(&pNode, *getChar);
		++getChar;
	}

	return pNode;
}

class Solution
{
public:
	ListNode * getRight(ListNode* pHead)
	{
		int len = 1;
		ListNode * right = NULL;
		ListNode * cur = pHead;
		while (pHead->m_pNext != NULL)
		{
			++len;
			pHead = pHead->m_pNext;
		}

		if (0 == len % 2) //偶数节点
		{
			len /= 2;
			--len;
			while (len--)
			{
				cur = cur->m_pNext;
			}
			right = cur->m_pNext; //保存右半链表的起始节点指针
			cur->m_pNext = NULL;  //这里断开
		}
		else //奇数节点
		{
			len /= 2;
			--len;
			while (len--)
			{
				cur = cur->m_pNext;
			}
			right = cur->m_pNext->m_pNext; //奇数节点要跳过中间节点
			cur->m_pNext->m_pNext = NULL;
			cur->m_pNext = NULL; //这里断开
		}

		return right;
	}

	ListNode * reverseList(ListNode* pHead)
	{
		ListNode* pre = NULL;
		ListNode* temp = pHead;
		ListNode* cur = pHead;

		while (cur != NULL)
		{
			cur = cur->m_pNext;
			temp->m_pNext = pre;
			pre = temp;
			temp = cur;
		}

		return pre;
	}

	bool isPalindrome(ListNode* pHead) 
	{
		if (NULL == pHead) 
			return false;
		if (NULL == pHead->m_pNext) 
			return false;

		ListNode* left = pHead;
		ListNode* right = getRight(pHead); //对链表进行拆分，分成左右两端
		right = reverseList(right); //对右半部分链表进行逆序

									//判断是否是回文
		while (left)
		{
			if (left->m_cValue != right->m_cValue)
			{
				return false;
			}
			left = left->m_pNext;
			right = right->m_pNext;
		}

		return true;
	}
protected:
private:
};

void test(ListNode* pHead, int length, bool expectedValue)
{
	Solution solution;
	/*ListNode* pNodeRight = solution.getRight(pHead);
	cout << "the rightside list is:"<< endl;
	printList(pNodeRight);

	cout << "the leftside list is:" << endl;
	printList(pHead);

	ListNode* pReverseRight = solution.reverseList(pNodeRight);
	cout << "the rightside list after reverse is:" << endl;
	printList(pReverseRight);*/
	bool returnValue = solution.isPalindrome(pHead);
	if (returnValue == expectedValue)
	{
		cout << "Passed..."<< endl;
	}
	else
	{
		cout << "Failed!!!"<< endl;
	}
}

//长度为奇数的回文字符串
void test1()
{
	cout << "test1 running......" << endl;
	//char* string = "madam";
	//test(string, strlen(string), true);

	char* string = "abcdcba";
	int length = strlen(string);
	ListNode* pHead = createSingleList(string, length);
	printList(pHead);
	test(pHead, length, true);
}

//长度为偶数的回文字符串
void test2()
{
	cout << "test2 running......" << endl;
	//char* string = "madam";
	//test(string, strlen(string), true);

	char* string = "abccba";
	int length = strlen(string);
	ListNode* pHead = createSingleList(string, length);
	printList(pHead);
	test(pHead, length, true);
}

//不是回文字符串
void test3()
{
	cout << "test3 running......" << endl;
	//char* string = "madamaadd";
	//test(string, strlen(string), false);
	char* string = "abcdefg";
	int length = strlen(string);
	ListNode* pHead = createSingleList(string, length);
	printList(pHead);
	test(pHead, length, false);
}

//空指针测试
void test4()
{
	cout << "test4 running......" << endl;
	//char* string = "madamaadd";
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
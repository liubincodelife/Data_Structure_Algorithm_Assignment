#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
	bool isValidBrackets(string bracketString)
	{
		bool isValid = false;
		stack<char> leftBracketStack;
		if (bracketString.empty())
		{
			cout << "the string is empty!!!"<< endl;
			return false;
		}
		for (int i = 0; i < bracketString.size(); i++)
		{
			char currentChar = bracketString.at(i);
			if (currentChar == '(' || currentChar == '[' || currentChar == '{')
			{
				leftBracketStack.push(currentChar);
			}
			else
			{
				if (currentChar == ')' || currentChar == ']' || currentChar == '}')
				{
					if (leftBracketStack.empty())
						return false;
					char tmpChar = leftBracketStack.top();
					if (currentChar == '}' && tmpChar == '{' \
						|| currentChar == ']' && tmpChar == '[' \
						|| currentChar == ')' && tmpChar == '(')
					{
						leftBracketStack.pop();
					}
					else
					{
						break;
					}
				}
			}
		}
		if (leftBracketStack.empty())
			isValid = true;
		return isValid;
	}
protected:
private:
};

void test(string bracketString, bool expectValue)
{
	Solution solution;
	bool retValue = solution.isValidBrackets(bracketString);
	if (retValue == expectValue)
		cout << "Passed..." << endl;
	else
		cout << "Failed!!!"<< endl;
}
//À¨ºÅÆ¥Åä
void test1()
{
	cout << "test1 running......"<< endl;
	string testString = "{[([({})])]}";
	test(testString, true);
}

//À¨ºÅ²»Æ¥Åä
void test2()
{
	cout << "test2 running......" << endl;
	string testString = "{[([({)})])]}";
	test(testString, false);
}

//µÚÒ»¸ö×Ö·ûÎªÓÒÀ¨ºÅ
void test3()
{
	cout << "test3 running......" << endl;
	string testString = "){[([({)})])]}";
	test(testString, false);
}

//×Ö·û´®Îª¿Õ
void test4()
{
	cout << "test4 running......" << endl;
	string testString = "";
	test(testString, false);
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
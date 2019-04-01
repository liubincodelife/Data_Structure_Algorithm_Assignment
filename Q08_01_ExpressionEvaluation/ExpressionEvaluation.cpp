#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
	Solution()
	{
		initPriority();
	}

	int calculate(string inputExpression)
	{
		stack<int> num_stack;
		stack<char> op_stack;
		int retValue = 0;;
		for (int i = 0; i < inputExpression.size(); i++)
		{
			char currentChar = inputExpression.at(i);
			if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/')
			{
				if(op_stack.empty())
					op_stack.push(currentChar);
				else
				{
					char opStr = op_stack.top();
					int tmp = optPriorityCompare(currentChar, opStr);
					if (tmp > 0)
					{
						op_stack.push(currentChar);
					}
					else
					{
						int numa = num_stack.top();
						num_stack.pop();
						int numb = num_stack.top();
						num_stack.pop();
						char opTmp = op_stack.top();
						op_stack.pop();
						int value = calculateValue(numa, numb, opTmp);
						num_stack.push(value);
						op_stack.push(currentChar);
					}
				}
				
			}
			else if (currentChar == '=')
			{
				break;
			}
			else
			{
				num_stack.push(atoi(&currentChar));
			}
			
		}
		while (!op_stack.empty())
		{
			int numa = num_stack.top();
			num_stack.pop();
			int numb = num_stack.top();
			num_stack.pop();
			char opTmp = op_stack.top();
			op_stack.pop();
			int value = calculateValue(numa, numb, opTmp);
			num_stack.push(value);
		}
		retValue = num_stack.top();

		return retValue;
	}
protected:
private:
	char optPriority[128];
	void initPriority()
	{
		optPriority['+'] = 4;
		optPriority['-'] = 4;
		optPriority['*'] = 3;
		optPriority['/'] = 3;
		optPriority['('] = 1;
		optPriority[')'] = 1;
	}

	int optPriorityCompare(char opt1, char opt2)
	{
		return optPriority[opt2] - optPriority[opt1];
	}

	int calculateValue(int num1, int num2, char op)
	{
		int retValue = 0;
		switch (op)
		{
		case '+':
			retValue = num1 + num2;
			break;
		case '-':
			retValue = num2 - num1;
			break;
		case '*':
			retValue = num1 * num2;
			break;
		case '/':
			retValue = num2 / num1;
			break;
		}
		return retValue;
	}
};

void test(string inputExpression, int expectedValue)
{
	Solution solution;
	int returnValue = solution.calculate(inputExpression);

	if (returnValue == expectedValue)
	{
		cout << "Passed..." << endl;
	}
	else
	{
		cout << "Failed!!!" << endl;
	}
}

void test1()
{
	cout << "test1 starting......"<< endl;
	string str = "1+2+3+6-5=";
	test(str, 7);
}

void test2()
{
	cout << "test2 starting......" << endl;
	string str = "1+2*3+6-5=";
	test(str, 8);
}

int main(int argc, char** argv)
{
	/*string str;
	cin >> str;
	cout << "input expression equals:" << str << endl;*/
	
	test1();
	test2();
	while (1)
	{
	}
	return 0;
}
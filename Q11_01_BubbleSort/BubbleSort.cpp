#include <iostream>

using namespace std;

void BubbleSort(int* array, int length)
{
    if (length <= 1)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        bool flag = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

void test()
{
    int array[10] = { 3, 2, 4, 1, 5, 9, 6, 7, 0, 8 };
    int length = sizeof(array) / sizeof(int);
    BubbleSort(array, length);
    cout << "array after sorted is: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}
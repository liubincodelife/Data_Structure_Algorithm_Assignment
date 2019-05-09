#include <iostream>

using namespace std;

void Merge(int a[], int left, int mid, int right)
{
    //��������ĳ���
    int length1 = mid - left + 1;
    int length2 = right - mid;

    //���������µ��ڴ�ռ�洢ԭ����
    int *l1 = new int[length1];
    int *l2 = new int[length2];

    for (int i = 0; i < length1; ++i)
    {
        l1[i] = a[left + i];
    }
    for (int j = 0; j < length2; ++j)
    {
        l2[j] = a[j + mid + 1];
    }

    //����ԭ����֮�󣬱Ƚ���������
    int i = 0, j = 0;
    int k = length1;
    //�Ƚ��������е��غϲ��֣���������
    while (i < length1 && j < length2)
    {
        if (l1[i] < l2[j])
        {
            a[left++] = l1[i++];
        }
        else
        {
            a[left++] = l2[j++];
        }
    }
    //�����е�ʣ�ಿ�ֱַ���ڽ�β
    while (i < length1)
    {
        a[left++] = l1[i++];
    }

    while (j < length2)
    {
        a[left++] = l2[j++];
    }

    //������ڴ���Ҫ�ͷŵ�
    delete[]l1;
    delete[]l2;
}

void Merge_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;//���Ƚ��з�����Ȼ��ݹ����
        Merge_sort(a, left, mid);
        Merge_sort(a, mid + 1, right);//��һ�ν����Ϊ�������䣬���кϲ�����
        Merge(a, left, mid, right);
    }
}

int main(int argc, char** argv)
{
    //int a[10] = { 23,56,78,6,59,15,49,81,15,56 };
    int a[7] = { 38, 27, 43, 3, 9, 82, 10 };

    Merge_sort(a, 0, 6);
    for (size_t i = 0; i < 7; ++i)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    getchar();
    return 0;
}
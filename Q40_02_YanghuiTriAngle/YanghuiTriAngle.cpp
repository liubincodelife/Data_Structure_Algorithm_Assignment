#include <iostream>
#include <algorithm>

using namespace std;

int path[5][5] = {
    {5, 0, 0, 0, 0},
    {7, 8, 0, 0, 0},
    {2, 3, 4, 0, 0},
    {4, 9, 6, 1, 0},
    {2, 7, 9, 4, 5},
};

int num = 5;

int yanghuiTriAngle(int matrix[5][5], int n)
{
    int states[5][5] = { 0 };
    states[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                states[i][j] = matrix[i][j] + states[i - 1][j];
            }
            else if (j == i)
            {
                states[i][j] = matrix[i][j] + states[i - 1][j - 1];
            }
            else
            {
                int top1 = states[i - 1][j - 1]; //左上角元素
                int top2 = states[i - 1][j];  //右上角元素
                states[i][j] = matrix[i][j] + min(top1, top2);
            }
        }
    }

    int minDistance = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        int distance = states[n - 1][j];
        if (distance < minDistance)
        {
            minDistance = distance;
        }
    }

    return minDistance;
}

void test1()
{
    int minimumDistance = yanghuiTriAngle(path, num);
    cout << "the minimum distance is:" << minimumDistance << endl;
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}
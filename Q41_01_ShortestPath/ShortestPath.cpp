#include <iostream>
#include <algorithm>

using namespace std;

int path[][4] = {
    {1, 3, 5, 9},
    {2, 1, 3, 4},
    {5, 2, 6, 7},
    {6, 8, 4, 3}
};

int states[][4] = { 0 };

int num = 4;

int shortestPath(int matrix[][4], int n)
{
    int sum = 0;
    for (int j = 0; j < n; j++)  //初始化状态矩阵第一行
    {
        sum += matrix[0][j];
        states[0][j] = sum;
    }
    sum = 0;
    for (int i = 0; i < n; i++) //初始化状态矩阵第一列
    {
        sum += matrix[i][0];
        states[i][0] = sum;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            states[i][j] = matrix[i][j] + min(states[i][j-1], states[i-1][j]);
        }
    }

    return states[n - 1][n - 1];
}

void test1()
{
    int minimumDist = shortestPath(path, num);
    cout << "the minimum distance is: " << minimumDist << endl;
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}
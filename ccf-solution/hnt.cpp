#include <bits/stdc++.h>

using namespace std;

void hannoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << "移动圆圈" << n << "从盘" << A << "盘" << C << endl;
    }
    else
    {
        hannoi(n - 1, A, C, B);
        cout << "移动圆圈" << n << "从盘" << A << "盘" << C << endl;
        hannoi(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    cin >> n;
    hannoi(n, 'A', 'B', 'C');
    return 0;
}
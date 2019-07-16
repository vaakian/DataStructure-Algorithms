#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, L, t;
    int i, j;
    int temp;
    cin >> n >> L >> t;
    vector<int> flag(n, 1);
    vector<int> a;
    for (i = 0; i < n; ++i)
    {
        cin >> temp;
        a.push_back(temp);
    }
    while (t)
    {
        for (i = 0; i < n - 1; ++i)
            for (j = i + 1; j < n; ++j)
            {
                if (a[i] == a[j])
                {
                    // 碰撞就往反方向走
                    flag[i] *= -1;
                    flag[j] *= -1;
                    break;
                }
            }
        for (i = 0; i < n; ++i)
        {
            a[i] += flag[i]; // 移动
            // 如果移动后，到达边界，下次就往反方向走
            if (a[i] == 0 || a[i] == L)
                flag[i] *= -1;
        }
        --t;
    }
    for (auto ai : a)
    {
        cout << ai << " ";
    }
    return 0;
}
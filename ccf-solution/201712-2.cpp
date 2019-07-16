#include <iostream>
#include <vector>
using namespace std;
int main()
{
    unsigned int n, k;
    unsigned int i = 0, count = 0, fail = 0;
    cin >> n >> k;
    vector<bool> kids(n, true);
    while (n!=1) // 1个就直接赢了
    {
        for (i = 0; i < n; i++)
        {
            if (kids[i]) // 未淘汰 true
            {
                ++count;
                if (count % k == 0 || count%10 == k) // 如果符合条件，淘汰掉
                {
                    kids[i] = false;
                    if (++fail == n - 1) // 如果还剩下一个人直接退出
                        goto RESULT;
                }
            }
        }
    }
RESULT:
    for (i = 0; i < n; i++)
    {
        if (kids[i]) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}

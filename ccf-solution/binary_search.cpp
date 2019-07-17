// 已知sqrt(2)保留两位小数1.41, 手动求保留后6位
#include <bits/stdc++.h>
#define END 0.000001
using namespace std;

int main()
{
    double high, mid, low;
    high = 1.45;
    low = 1.4;
    while (high - low > END)
    {
        mid = (high + low) / 2;
        /*  low---- mid ----high
            mid*mid大，就从low~mid找
            否则从mid~high找
        */
        if (mid * mid > 2)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    cout << mid << endl;
    return 0;
}
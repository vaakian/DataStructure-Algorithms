#include <bits/stdc++.h>
using namespace std;
// 计算顺序不要反
int calc(int x, char p, int y)
{
    int result;
    switch (p)
    {
    case '+':
        result = x + y;
        break;
    case '-':
        result = x - y;
        break;
    case 'x':
        result = x * y;
        break;
    case '/':
        result = x / y;
        break;

    default:
        break;
    }
    return result;
}

int calc_exp(string exp)
{
    vector<int> NUM;
    vector<char> OPT;
    int a, b, temp;
    // 先把乘除法计算
    for (auto c : exp)
    {
        if (isdigit(c) && (!NUM.empty() && !OPT.empty()) && (OPT.back() == 'x' || OPT.back() == '/'))
        {
            b = NUM.back();
            NUM.pop_back();
            temp = calc(b, OPT.back(), c - 0x30);
            OPT.pop_back();
            NUM.push_back(temp);
        }
        else
            OPT.push_back(c);
    }
    for (int i = 1; i < NUM.size(); i++)
    {
        NUM[0] += (OPT[i - 1] == '-' ? -NUM[i] : NUM[i]);
    }
    return NUM[0];
}

int main()
{
    string exp = "1+2x5/6x8";
    cout<<to_string(125)<<endl;
    calc_exp2(exp);
    // vector<int> res;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> exp;
    //     res.push_back(calc_exp(exp));
    // }
    // for (auto num : res)
    // {
    //     cout << (num == 24 ? "Yes" : "No") << endl;
    // }
    return 0;
}
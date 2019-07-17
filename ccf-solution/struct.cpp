#include <bits/stdc++.h>
using namespace std;
struct PERSON
{
    PERSON(int _age)
    {
        age = _age;
        left = right = NULL;
    };
    int age;
    PERSON *left;
    PERSON *right;
};
int main()
{

    /* 全排列，
        next_使用前 先排升序, 排列完成后会变成升序
        prev_使用前 先排降序，排序完成后会变成降序
    */ 
    vector<int> number = {4, 3, 2, 1};
    while (prev_permutation(number.begin(), number.end()))
    {
        for (auto n : number)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << "end: \n";
    for (auto n : number)
    {
        cout << n << " ";
    }
    return 0;
}
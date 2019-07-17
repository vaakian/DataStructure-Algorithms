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
void vector_test()
{
    vector<int> number = {4, 3, 2, 1};
    /* 全排列，
        next_使用前 先排升序, 排列完成后会变成升序
        prev_使用前 先排降序，排序完成后会变成降序
    */
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
}
void map_test()
{
    // map每一项本质上是pair
    // 所以得到迭代器，可以使用指针访问first(key)，second(value)
    map<string, int> data;
    // 插入可以传入一个pair
    data.insert(pair<string, int>("acb", 2));
    data.insert(make_pair("bcd", 1));
    data["aew"] = 7;
    map<string, int>::iterator finded;
    finded = data.find("acb");
    cout << finded->second << endl;

    // map<string, int>::iterator it;
    for (auto it = data.begin(); it != data.end(); ++it)
        printf("%s => %d\n", it->first.c_str(), it->second);
}
int main()
{
    // vector_test();
    map_test();
    return 0;
}
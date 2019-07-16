#include <bits/stdc++.h>
using namespace std;
int main()
{
    // array<type, size> name = {1,2,3}
    array<int, 5> arr = {1, 2, 3};
    cout << binary_search(arr.begin(), arr.end(), 2) << endl;
    cout << find(arr.begin(), arr.end(), 99) << endl;
    // c数组
    int arr2[5] = {1, 2, 3};
    cout << binary_search(arr2, arr2 + 2, 2) << endl;
    // 数组填充, pos1~pos2  value
    fill(arr2, arr2 + 2, 1);
    fill(arr.begin(), arr.end() - 1, 1);

    vector<int> arr3 = {5, 5, 5, 5, 5, 6, 6, 6, 6};
    // 返回最新的end
    auto new_end = unique(arr3.begin(), arr3.end());
    // 按范围，或pos删除
    arr3.erase(new_end, arr3.end());
    // 按值删除
    // remove(arr3.begin(), arr3.end(), 5);
    for (auto el : arr3)
        cout << el << " ";
    vector<int> arr4 = {5, 3, 423, 4, 567, 56, 23, 4};
    int sum;
    // 累加器，第三个元素为初值
    cout << "累加器：" << endl;
    sum = accumulate(arr4.begin(), arr4.end(), 0);
    cout << sum << endl;

    // 全排列！！！ vector, c数组等等都可以，只要存在迭代器。

    cout << "全排列：" << endl;
    string pl = "213";          //（先排序！）
    sort(pl.begin(), pl.end()); // 按照ascii排序
    do                          // pl.end()-1，就是前n-1个进行全排列
    {
        cout << pl << endl;
    } while (next_permutation(pl.begin(), pl.end()));
    // next_permutation 会循环到整个排列有序时结束，比如213排列到123就结束了
    cout << pl << endl;

    // 包含集合(按顺序来，最好先sort)
    array<int, 4> score = {10, 20, 30, 55};
    array<int, 3> sub_set = {10, 55, 30};
    sort(score.begin(), score.end());
    sort(sub_set.begin(), sub_set.end());
    cout << "includes: " << endl;
    cout << includes(score.begin(), score.end(), sub_set.begin(), sub_set.end()) << endl;
    return 0;
}
// vector不定长，可修改。
// array初始化就要长度，长度无法修改。
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //
    vector<int> all(5);
    // 在下标为2插一个
    all.insert(all.begin(), 2);
    // 在尾部插一个
    all.insert(all.end(), 5);
    // 删一个
    all.erase(all.end() - 1);
    // 删区间
    all.erase(all.begin() + 1, all.begin() + 3); //删除all[1]~all[3]
    for (auto l : all)
    {
        cout << l << endl;
    }
    // (min)max_element返回position（地址）
    printf("max: %d\n", *max_element(all.begin(), all.end()));
    // max min
    cout << max(1, 2) << min(5, 6) << endl;
    // pair 对
    pair<int, int> p;
    // pair嵌套 vector
    pair<int, vector<string>> pv;
    // vector嵌套 pair
    vector<pair<int, int>> vp;
    // make pair
    vp.push_back(make_pair(1, 2));
    // sort排序，默认升序
    array<int, 5> sort_arr = {5, 7, 2, 512, 43};
    // 设为降序，匿名函数：[](int x, int y){return xxx};
    sort(sort_arr.begin(), sort_arr.end(), [](int x, int y) { return x > y; });
    // sort(sort_arr.begin(), sort_arr.end(), greater());
    // 在pos1~pos2搜索val binary_search(pos1, pos2, val)
    vector<int> search = {1,2,3,4,5};
    cout<<binary_search(search.begin(), search.end(), 2)<<endl;
    for (auto &s : sort_arr)
        cout << s << " ";
    // set集合
    set<int> my_set;
    my_set.insert(5);
    my_set.insert(5); // 重复插入不计算
    for (auto &s : my_set)
        cout << s << " ";
    cout<<'\n';
    // map
    map<string, int> user_id;
    user_id["xwj"] = 5; // 直接插入
    cout<<user_id["xwj"]; //访问
    return 0;
}
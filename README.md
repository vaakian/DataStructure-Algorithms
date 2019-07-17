# DataStructure-Algorithms


    2019-5-31 19:21:09

## 以及记录一些日常代码心得
 -  `python`, `nodejs`

 - the python lib `graphviz` is great for data visualization.

## 递归

- 理论上所有递归都可以使用数据结构：栈（stack），进行非递归化。

- 动态规划（Dynamic Programming）也是类似于将递归非递归化。

- 递归最重要先找到递归出口条件。

## c++ STL 刷题常用库函数
|function|notes|
|:-------|:----|
|max(a, b)|return max of a and b|
|min(a, b)|return min of a and b|
|max_element(pos1, pos2)| return max_element's iterator(read with *) between pos1 ~ pos2|
|find(pos1, pos2, val)| return val's iterator between pos1 ~ pos2|
|reverse(pos1, pos2)| reverse the elements between pos1 ~ pos2|
|unique(pos1, pos2)| remove repetitve elements, return new_end iterator|
|sort(pos1, pos2, greater())|sort elements between pos1 ~ pos2 DESC`(降序)`|
|includes(s1_p1, s1_p2, s2_p1, s2_p2)| judge if set `s1` includes set `s2`|
|accumulate(pos1, pos2)| return sum between pos1 ~ pos2|
|next_permutation(pos1, pos2)| better sort as ASC before using it, end of execution the elements between pos1 ~ pos2 will be sorted as `ASC(升序)`|
|prev_permutation(pos1, pos2)| give a DESC, return FULL permutation, end of execution the elements between pos1 ~ pos2 will be sorted as `DESC(降序)`|
|swap(pos1, pos2)| swap|
|fill(pos1, pos2, val)| fill pos1 ~ pos2 with val|
|remove(pos1, pos2, val)| remove all value=val pos1 ~ pos2, return new_end|
|count(pos1, pos2, val)| return val count|

> erase 属于成员函数

## c++各自带数据结构成员函数
|type|funcs|
|:---|:----|
|vector| front, back`（类似于栈顶）`, pop_back`（删除最后一个元素，不返回删除掉的元素，类似于栈的pop）`


## 各数据结构用法

- do not access val.end(), it's empty. the last element is *(val.end()-1);

- all varibles above includes:

    |name|notes|
    |:---|:----|
    |empty()|if set is empty|
    |begin(), end()| iterator|
    |size()| size of set|
    |front(), back()| get val front, back|



- vector （sequential，accessible with index）

    ```C++
    vector<int> vec; // empty vector
    vector<int> vec(n); // create n elements, val 0
    vector<int> vec(n, 5) // create n elements, val 5
    vector<int> vec2(vec) // copy a vector
    vector<int>{1, 2, 3, 4} // create a anonymous vector
    vector<int> vec = {1, 2, 3, 4} // init vector

    vec.erase(pos1, pos2) // real remove pos1~pos2
    max_element(vec.begin(), vec.end()) // first max element's iterator.
    ```
- c++ array （sequential，accessible with index）

    - 创建方法：array<type, size> arr， 一旦创建大小无法更改。
    
    ```c++    
    array<int, 5> arr;
    array<int, 5> arr = {1, 2, 3, 4};
    max_element...
    fill...
    ```
- stack 

    ```c++
    stack<type> name;
    stack<int> data;
    data.push(5);
    data.pop();
    ```

- list （like DuLinklist）两边都可以删除增加

    ```c++
    list<int> data;
    list.back();
    list.front();
    list.push_back();
    list.push_front();
    list.pop_front();
    list.pop_back();
    ```
- pair (对)

    ``` c++
    pair<type, type> p;
    //access 
    cout << p.first << endl; 
    cout << p.second << endl;

    // create pair
    make_pair(first_val, second_val);
    ```

- map 类似javascript，python字典

    ```c++
    map<key_type, val_type> user_id;
    // add 
    user_id["xwj"] = 5;
    user_id["mht"] = 12;
    // access
    cout << user_id["xwj"] << endl;
    cout << user_id["mht] << endl;
    auto finded = map.find(5);
    if(finded == map.end()) 
        cout << "can't find." << endl;
    else 
        cout << "found it." << endl;
    ```
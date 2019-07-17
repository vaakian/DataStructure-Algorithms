# DataStructure-Algorithms


    2019-5-31 19:21:09

## 以及记录一些日常代码心得
 -  `python`, `nodejs`

 - the python lib `graphviz` is great for data visualization.

## 递归

- 理论上所有递归都可以使用数据结构：栈（stack），进行非递归化。

- 动态规划（Dynamic Programming）也是类似于将递归非递归化。

- 递归最重要先找到递归出口条件。

## c++ stl常用函数
|function|notes|
|:-------|:----|
|max(a, b)|return max of a and b|
|min(a, b)|return min of a and b|
|max_element(pos1, pos2)| return max_element's iterator(read with *) between pos1 ~ pos2|
|find(pos1, pos2, val)| return val's iterator between pos1 ~ pos2|
|reverse(pos1, pos2)| reverse the elements between pos1 ~ pos2|
|unique(pos1, pos2)| remove repetitve elements, return new_end iterator|
|sort(pos1, pos2, greater())|sort elements between pos1 ~ pos2 desc`(降序)`|
|includes(s1_p1, s1_p2, s2_p1, s2_p2)| judge if set `s1` includes set `s2`|
|accumulate(pos1, pos2)| return sum between pos1 ~ pos2|
|next_permutation(iteraterable_val val_name)| better sort before calling, end of execution the val_name will be sorted|
|swap(pos1, pos2)| swap|
|fill(pos1, pos2, val)| fill pos1 ~ pos2 with val|


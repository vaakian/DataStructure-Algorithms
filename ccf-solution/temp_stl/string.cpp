#include<iostream>
#include<string>
using namespace std;
int main() {
    string s = "hello, world!";
    // replcae(起始下标，个数，插入的字符)
    s.replace(3, 2, "NEWSTR");
    cout<<s<<endl;
    s.resize(5);
    cout<<s<<endl;
    string exp = '[][]{}ASD{}123[]213]12[3]12[3'
     // remove返回新的结束点
   
    auto new_end = remove(exp.begin(), exp.end(), '[');
   
    // 把新的end之后字符清空
    exp.erase(new_end, exp.end());
    cout<<exp<<endl;
    return 0;
}

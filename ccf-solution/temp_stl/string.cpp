#include <bits/stdc++.h>
using namespace std;
string parse_content(string content)
{
    auto em = make_pair("<em>", "</em>");
    int count = 1;
    for (auto i = 0; i < content.size(); ++i)
    {
        if (content[i] == '_')
        {
            if (count % 2)
                content.replace(i, 1, em.first);
            else
                content.replace(i, 1, em.second);
            ++count;
        }
        cout << content[i] << endl;
    }
    return content;
}
int main()
{
    string s = "hello, _wo_r2323ld!";
    // replcae(起始下标，个数，插入的字符)
    // s.replace(2, 1, "NEWSTR");
    // cout << parse_content(s) << endl;
    // cout<<s.substr(s.begin()+1);
    cout<<s.find("wo");

    // string exp = '[][]{}ASD{}123[]213]12[3]12[3';
    // remove返回新的结束点

    // auto new_end = remove(exp.begin(), exp.end(), '[');

    // 把新的end之后字符清空
    // exp.erase(new_end, exp.end());
    // cout<<exp<<endl;
    return 0;
}

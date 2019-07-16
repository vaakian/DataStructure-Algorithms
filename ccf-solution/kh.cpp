#include<bits/stdc++.h>
using namespace std;

int main()
{
    string exp = "[[][][][{}]()[{}{}]";
    map<char, char> hash;
    hash['['] = ']';
    hash['{'] = '}';
    hash['('] = ')';
    stack<char> s;
    s.push(exp[0]);
    for(auto c = exp.begin()+1; c<exp.end(); c++) {
        if(*c == hash[s.top()]) s.pop();
        else s.push(*c);
    }
    if(s.empty()) {
        cout<<"成功匹配！\n"<<endl;
    } else {
        cout<<"匹配失败！\n"<<endl;
    }
    return 0;
}

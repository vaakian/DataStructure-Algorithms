#include<iostream>
#include<string>
#include<vector>
using namespace std; 
// test fuck
int calc(int x, char opt, int y) {
    int result;
    if(opt == '/') result = x/y;
    else if(opt == '+') result = x+y;
    else if(opt == '-') result = x-y;
    else result = x*y;
    // cout<<x<<opt<<y<<"="<<result<<endl;
    return result;
}
int calc_exp(string exp) {
    int temp, result;
    vector<char> opt;
    vector<int> num;
    // 本次循环计算所有乘除法
    for(auto c: exp) {
        if(c == '+' || c== '-' || c == 'x' || c == '/') {
            if(!opt.empty() && num.size() >= 2) {  // 判断栈顶是不是乘除
                if(opt.back() == 'x' || opt.back() =='/') {
                    // 取数栈两个数 & 运算符一个 进行运算
                    temp = num.back(); num.pop_back();
                    result = calc(num.back(), opt.back(), temp);
                    num.pop_back();opt.pop_back();
                    num.push_back(result);
                }
            }
            opt.push_back(c);
            
        } else {
            num.push_back(c-0x30);
        }
    }
    // 乘除法解决了，就可直接从左往右算
    while(!opt.empty()) {
        temp = num.back(); num.pop_back();
        result = calc(num.back(), opt.back(), temp);
        num.pop_back(); opt.pop_back();
        num.push_back(result);
    }
    return num.front();
}
int main() {
    int n;
    string exp;
    vector<int> res;
    cin>>n;
    for(int i = 0; i < n; ++i) {
        cin>>exp;
        res.push_back(calc_exp(exp));
    }
    for(int i = 0; i < n; ++i) {
        if(res.at(i) == 24)
         cout<<"Yes"<<endl;
        else
         cout<<"No"<<endl;
    }
    return 0;
}
/*
test case:
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9+5/9
8/5+6x9
6x7-3x6
6x4+4/5
 */
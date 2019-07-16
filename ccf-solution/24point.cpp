#include<iostream>
#include<string>
#include<vector>
using namespace std;

int calc(int x, int opt, int y) {
    int result;
    if(opt == '+') result = x + y;
    else if(opt == '-') result = x - y;
    else if(opt == 'x') result = x * y;
    else result = x / y;
    return result;
}
int calc_exp(string exp) {
    vector<char> OPT;
    vector<int> NUM;
    int  a, b, result;
    for(auto c: exp) {
        if(c == '+' || c== '-' || c == 'x' || c == '/') {
            if( NUM.size() >= 2 
            && !OPT.empty() 
            && (OPT.back() == 'x' || OPT.back() == '/')) {
                a = NUM.back(); NUM.pop_back();
                b = NUM.back(); NUM.pop_back();
                result = calc(b, OPT.back(), a);
                NUM.push_back(result);
                OPT.pop_back();
            }
            OPT.push_back(c);
        } else {
            NUM.push_back(c-0x30);
        }
    }
    cout<<"end of stack: "<< endl;
    for(auto c: OPT) cout<<c<<" "<<endl;
    while(!OPT.empty()) {
        a = NUM.back(); NUM.pop_back();
        b = NUM.back(); NUM.pop_back();
        result = calc(b, OPT.back(), a);
        NUM.push_back(result);
        OPT.pop_back();
        // cout<<result<<endl;
    }
    // cout<<NUM.at(0)<<endl;
    return NUM.at(0);
}
int main()
{
    string exp;
    vector<int> res;
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i) {
        cin>>exp;
        res.push_back(calc_exp(exp));
    }
    for(auto num: res) {
        cout<<(num == 24 ? "Yes": "No")<<endl;
    }
}
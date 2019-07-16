// http://118.190.20.162/view.page?gpid=T89
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, temp;
    int max, min;
    float mid;
    vector<int> data;
    cin>>n;
    for(int i = 0; i <n; ++i) {
        cin>>temp;
        data.push_back(temp);
    }
    if(data.front() > data.back()) {
        max = data.front();
        min = data.back();
    } else {
        max = data.back();
        min = data.front();
    }
    if(n%2==0) {
        mid = (data[n/2]+data[(n/2)-1]) / 2.0;
    } else {
        mid = data[int(n/2)];
    }
    if(mid == int(mid)) {
        printf("%d %.0f %d", max, mid, min);
    }
    else {
        // 保留一位小数
        float l = mid - int(mid);
        float ll = l*10-int(l*10.0);
        if( ll > 0.4) mid += 0.1;
        printf("%d %.1f %d", max, mid, min);
    }
}
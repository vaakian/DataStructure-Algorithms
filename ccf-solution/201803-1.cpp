#include<iostream>
using namespace std;
int main()
{
    int score;
    int sum = 0, step = 1;
    while(1) {
        cin>>score;
        if(score == 0) break;
        if(score == 2) {
            if(step == 1) step = 2;
            else step += 2;
        } else step = 1;
        sum+=step;
    }
    cout<<sum<<endl;
    return 0;
}
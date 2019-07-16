#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, count = 0;
    int s = 0;
    cin >> N;
    s = N / 50; // 可以买s个5瓶
    N -= 50 * s;
    count += N / 50 * 7;
    N -= 30;
    count += 4;
    cout << count + N / 10 << endl;
    return 0;
}
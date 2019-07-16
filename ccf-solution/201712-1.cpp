#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n, temp;
    int i, j;
    int min;
    cin >> n;
    vector<int> NUM;
    for (i = 0; i < n; ++i)
    {
        cin >> temp;
        NUM.push_back(temp);
        
    }
    min = abs(NUM[0] - NUM[1]);
    for (i = 0; i < n - 1; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            temp = abs(NUM[i] - NUM[j]);
            if (temp < min)
                min = temp;
        }
    }
    cout<<min<<endl;
    return 0;
}
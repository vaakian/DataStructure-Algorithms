#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    int temp;
    int sum, count;
    sum = count = 0;
    vector<int> cake;
    vector<int>::iterator it;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        cake.push_back(temp);
    }
    sort(cake.begin(), cake.end());
    for (it = cake.begin(); it < cake.end(); ++it)
    {
        sum += *it;
        if (sum >= k)
        {
            ++count;
            sum = 0;
        }
    }
    if (sum)
        ++count;
    cout << count << endl;
    return 0;
}
/*
while (!cake.empty())
    {
        it = min_element(cake.begin(), cake.end());
        sum += *it;
        cake.erase(it);
        if (sum >= k)
        {
            ++count;
            sum = 0;
        }
    }
    if (sum)
    {
        cout << sum << endl;
        ++count;
    }
 */
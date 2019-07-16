#include <bits/stdc++.h>
using namespace std;
int calc(pair<int, int> h, pair<int, int> w)
{
    int start = max(h.first, w.first);
    int end = min(h.second, w.second);
    int result = end - start;
    return result < 0 ? 0 : result;
}
int main()
{
    int n, i;
    int sum = 0;
    cin >> n;
    vector<pair<int, int>> H(n);
    vector<pair<int, int>> W(n);
    for (i = 0; i < n; i++)
        cin >> H[i].first >> H[i].second;
    for (i = 0; i < n; i++)
        cin >> W[i].first >> W[i].second;
    for (auto h : H)
        for (auto w : W)
            sum += calc(h, w);
    cout << sum << endl;
    return 0;
}
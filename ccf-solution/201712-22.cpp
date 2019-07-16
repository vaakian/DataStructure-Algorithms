#include <iostream>
using namespace std;

int main() {
    bool per[1005];
    for (int i = 0; i < 1005; i++)
        per[i] = true;
    int n = 0, k = 0;
    cin >> n >> k;
    int i = 1;
    int cnt = n;
    int loc = 0;
    while (true) {
        while (per[loc] == false) {
            loc++;
            if (loc >= n)
                loc = 0;
        }
        if (i % k == 0 || i % 10 == k) {
            cnt--;
            per[loc] = false;
        }
        i++;
        loc++;
        if (loc >= n)
            loc = 0;
        if (cnt == 1)
            break;
    }
    for (int i = 0; i < n; i++) {
        if (per[i] == true)
            cout << i + 1 << endl;
    }

    return 0;
}
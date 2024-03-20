#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& a) {
    multiset<int> s;
    for (int x : a) {
        while (x >= 10) {
            s.insert(x % 10);
            x /= 10;
        }
        s.insert(x);
    }
    int prev = *s.begin();
    s.erase(s.begin());
    while (!s.empty()) {
        if (prev > *s.begin()) return false;
        prev = *s.begin();
        s.erase(s.begin());
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << (solve(a) ? "YES" : "NO") << endl;
    }
    return 0;
}

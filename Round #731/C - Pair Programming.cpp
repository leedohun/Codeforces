#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <bitset>
#include <queue>
 
typedef long long ll;
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    int t; cin >> t;
 
    while (t--) {
        int k, n, m; cin >> k >> n >> m;
 
        vector<int> a, b;
 
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            a.push_back(tmp);
        }
        for (int j = 0; j < m; j++) {
            int tmp; cin >> tmp;
            b.push_back(tmp);
        }
 
        vector <int> ans;
        int ret = 1;
 
        int i = 0, j = 0;
        while (i != n || j != m) {
            if (i != n && a[i] == 0) {
                ans.push_back(0);
                i++; k++;
            }
            else if (j != m && b[j] == 0) {
                ans.push_back(0);
                j++; k++;
            }
            else if (i != n && a[i] <= k) {
                ans.push_back(a[i]);
                i++;
            }
            else if (j != m && b[j] <= k) {
                ans.push_back(b[j]);
                j++;
            }
            else {
                ret = 0;
                break;
            }
        }
        if (ret == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
}

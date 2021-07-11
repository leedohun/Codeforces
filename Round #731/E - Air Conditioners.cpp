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
 
ll ret[300005] = { 0, };
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    int t; cin >> t;
 
    while (t--) {
        int n ,k; cin >> n >> k;
 
        for (int i = 1; i <= n; i++) {
            ret[i] = 9876543210;
        }
 
        vector<int> a, t;
        for (int i = 0; i < k; i++) {
            int tmp; cin >> tmp;
            a.push_back(tmp);
        }
        for (int i = 0; i < k; i++) {
            int tmp; cin >> tmp;
            t.push_back(tmp);
        }
 
        for (int i = 0; i < k; i++) {
            ret[a[i]] = t[i];
        }
 
        int m = ret[1] + 1;
        for (int i = 2; i <= n; i++) {
            if (m <= ret[i])
                ret[i] = m++;
            else
                m = ret[i] + 1;
        }
        m = ret[n] + 1;
        for (int i = n - 1; 0 < i; i--) {
            if (m <= ret[i])
                ret[i] = m++;
            else
                m = ret[i] + 1;
        }
 
        for (int i = 1; i <= n; i++)
            cout << ret[i] << " ";
        cout << "\n";
    }
}

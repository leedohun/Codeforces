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
        string n; cin >> n;
 
        int a_local = -1;
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == 'a') {
                a_local = i;
                break;
            }
        }
        if (a_local == -1) {
            cout << "NO\n";
        }
        else {
            int ret = 1;
 
            int left = a_local - 1;
            int right = a_local + 1;
 
            for (int i = 1; i < n.size(); i++) {
                if (0 <= left && n[left] == 'a' + i) {
                    left--;
                }
                else if (right < n.size() && n[right] == 'a' + i) {
                    right++;
                }
                else {
                    ret = 0;
                    cout << "NO\n";
                    break;
                }
            }
            if (ret == 1)
                cout << "YES\n";
        }
    }
}

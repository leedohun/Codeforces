#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <stack>
#include <cmath>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
using namespace std;
 
typedef long long ll;
 
const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;
 
struct P {
    ll x; ll y; ll cnt;
};
 
struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x > b.x;
        return
            a.y > b.y;
    }
};
//priority_queue <P, vector<P>, compare> pq;
 
bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}
 
void solved() {
    int t; cin >> t;
 
    while (t--) {
        string s; cin >> s;
        int ans = 0;
 
        int a = -1, b = -1;
        for (int j = s.size() - 1; 0 <= j; j--) {
            if (a == -1 && s[j] == '0') {
                a = j;
            }
            else if (b == -1 && s[j] == '5') {
                b = j;
            }
        }
        for (int j = s.size() - 1; 0 <= j; j--) {
            if (a != -1 && j < a && (s[j] == '0' || s[j] == '5')) {
                ans = s.size() - j - 2;
                break;
            }
            else if (b != -1 && j < b && (s[j] == '2' || s[j] == '7')) {
                ans = s.size() - j - 2;
                break;
            }
        }
 
        cout << ans << "\n";
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}

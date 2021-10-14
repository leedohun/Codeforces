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
 
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
void solved() {
    int t; cin >> t;
 
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        rep(i, n) cin >> v[i];
 
        sort(v.begin(), v.end());
 
        vector <int> tmp;
        rep(i, n - 1) 
            if(v[i+1] - v[0] != 0)
                tmp.push_back(v[i + 1] - v[0]);
 
        if (tmp.size() == 0) cout << -1 << "\n";
        else if (tmp.size() == 1) cout << tmp[0] << "\n";
        else {
            int a = tmp[0];
            for (int j = 1; j < tmp.size(); j++) {
                a = gcd(a, tmp[j]);
            }
            cout << a << "\n";
        }
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}

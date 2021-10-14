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
 
vector <int> a[400005];
int inDegree[400005] = { 0, };
bool visit[400005] = { false, };
 
void solved() {
    int t; cin >> t;
 
    while (t--) {
        int n, k; cin >> n >> k;
 
        for (int i = 0; i <= n; i++) {
            a[i].clear();
            inDegree[i] = 0;
            visit[i] = false;
        }
 
        for (int i = 0; i < n - 1; i++) {
            int tmp, ttmp; cin >> tmp >> ttmp;
            a[tmp].push_back(ttmp);
            a[ttmp].push_back(tmp);
            inDegree[tmp]++;
            inDegree[ttmp]++;
        }
 
        if (n - 1 <= k) {
            cout << 0 << "\n";
            continue;
        }
 
        queue <pair<int, int>> q;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 1) {
                visit[i] = true;
                q.push({ i, 1 });
            }
        }
        
        int cnt = 1; k--;
        while (k--) {
            while (q.front().second == cnt) {
                int x = q.front().first;
                int y = q.front().second;
 
                q.pop();
 
                for (int i = 0; i < a[x].size(); i++) {
                    int yy = a[x][i];
                    if (--inDegree[yy] == 1) {
                        visit[yy] = true;
                        q.push({ yy,  y + 1 });
                    }
                }
            }
            cnt++;
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) ans++;
        }
        cout << ans << "\n";
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}

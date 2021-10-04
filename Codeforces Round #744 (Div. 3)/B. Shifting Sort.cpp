#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
using namespace std;
 
typedef long long ll;
 
const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;
 
struct P {
    ll x; ll y; ll z;
};
 
/*struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x > b.x;
        return
            a.y > b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;*/
 
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
        int N; cin >> N;
        vector <int> v(N), tmp(N);
        rep(i, N) cin >> v[i];
 
        vector <P> ans;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (v[j] < v[i]) {
                    queue <int> q;
                    for (int k = i; k <= j; k++) {
                        q.push(v[k]);
                    }
                    for (int k = 0; k < j - i; k++) {
                        q.push(q.front());
                        q.pop();
                    }
                    for (int k = i; k <= j; k++) {
                        v[k] = q.front(); q.pop();
                    }
 
                    ans.push_back({ i + 1, j + 1, j - i });
 
                    i = -1;
                    break;
                }
            }
        }
 
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << "\n";
        }
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}

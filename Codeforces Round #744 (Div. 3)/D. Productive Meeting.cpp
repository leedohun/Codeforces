#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>*/
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
using namespace std;
 
typedef long long ll;
 
const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;
 
struct P {
    ll x; ll y;
};
 
struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;
 
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
        vector <P> v(N);
        rep(i, N) {
            cin >> v[i].x;
            v[i].y = i + 1;
        }
 
        sort(v.begin(), v.end(), cmp);
 
        ll tmp = 0;
        for (int i = 0; i < N - 1; i++) tmp += v[i].x;
 
        vector <pair<int, int>> ans;
 
        if (tmp <= v[N - 1].x) {
            for (int i = 0; i < N - 1; i++) {
                for (int j = 0; j < v[i].x; j++) {
                    ans.push_back({ v[i].y, v[N - 1].y });
                }
            }
        }
        else {
            int i = 0;
            bool flag = false;
            while (tmp > v[N - 1].x) {
                while (i < N - 2 && v[i].x == 0)
                    i++;
 
                if (i == N - 2) break;
 
                v[i].x--;
                v[i + 1].x--;
                ans.push_back({ v[i].y, v[i + 1].y });
                tmp -= 2;
            }
 
            for (; i < N - 1; i++) {
                for (int j = 0; j < v[i].x; j++) {
                    if (v[N - 1].x != 0) {
                        ans.push_back({ v[i].y, v[N - 1].y });
                        v[N - 1].x--;
                    }
                }
            }
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}

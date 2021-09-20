#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
using namespace std;
 
typedef long long ll;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
struct P {
    int x; int y;
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
    int N; cin >> N;
    vector <ll> v(N);
 
    ll total = 0;
    rep(i, N) {
        cin >> v[i];
        total += v[i];
    }
 
    sort(v.begin(), v.end());
 
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        ll x, y; cin >> x >> y; //수비력, 공격력
 
        int start = 0;
        int end = v.size() - 1;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (v[mid] < x) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
 
        if (start == v.size()) start -= 1;
        if (end == -1) end += 1;
     
        ll tmp1 = 0, tmp2 = 0;
        if (v[start] < x) {
            tmp1 += x - v[start];
        }
        if (total - v[start] < y) {
            tmp1 += y - (total - v[start]);
        }
 
        if (v[end] < x) {
            tmp2 += x - v[end];
        }
        if (total - v[end] < y) {
            tmp2 += y - (total - v[end]);
        }
 
        cout << min(tmp1, tmp2) << "\n";
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}

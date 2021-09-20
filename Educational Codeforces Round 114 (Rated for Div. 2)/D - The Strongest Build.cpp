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
//priority_queue <P, vector<P>, compare> pq;
 
bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}
 
void solved() {
    int N; cin >> N;
    vector <vector<int>> v(N);
    rep(i, N) {
        int c; cin >> c;
        vector <int> tmp(c);
        rep(j, c) cin >> tmp[j];
 
        v[i] = tmp;
    }
    
    int M; cin >> M;
    set <vector<int>> s;
    for (int i = 0; i < M; i++) {
        vector <int> tmp(N);
        for (int j = 0; j < N; j++) {
            cin >> tmp[j];
        }
        s.insert(tmp);
    }
 
    ll d = 0;
    for (int i = 0; i < N; i++) d += v[i][v[i].size() - 1];
 
    priority_queue <pair<ll, vector<int>>> pq;
    set <vector<int>> visit;
 
    vector <int> tmp;
    for (int i = 0; i < N; i++) tmp.push_back(v[i].size());
 
    pq.push({ d, tmp });
    visit.insert(tmp);
 
    while (!pq.empty()) {
        d = pq.top().first;
        tmp = pq.top().second;
 
        pq.pop();
 
        if (s.find(tmp) == s.end()) {
            for (int i = 0; i < N; i++) {
                cout << tmp[i] << " ";
            }
            return;
        }
 
        for (int i = 0; i < N; i++) {
            if (tmp[i] == 1) continue;
            tmp[i]--;
 
            d -= v[i][tmp[i]];
            d += v[i][tmp[i] - 1];
 
            if (visit.find(tmp) == visit.end()) {
                pq.push({ d, tmp });
                visit.insert(tmp);
            }
 
            d += v[i][tmp[i]];
            d -= v[i][tmp[i] - 1];
            tmp[i]++;
        }
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}

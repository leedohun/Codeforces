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
 
struct Info
{
    int x, y;
};
 
struct cmp {
    bool operator()(Info& a, Info& b) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        return a.x > b.x;
    }
};
 
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
 
        priority_queue<Info, vector<Info>, cmp > pq;
        for (int i = 0; i < k; i++) {
            pq.push({ t[i], a[i] });
        }
 
        int cnt = 0;
        while (!pq.empty()) {
            if (cnt == n)
                break;
 
            int tmp = pq.top().x;
            int x = pq.top().y;
 
            pq.pop();
 
            if (ret[x] > tmp) {
                ret[x] = tmp; cnt++;
                
                if (x == 1) {
                    pq.push({ tmp + 1, x + 1 });
                }
                else if (x == n) {
                    pq.push({ tmp + 1, x - 1 });
                }
                else if(1 < x && x < n) {
                    if (ret[x + 1] > tmp + 1)
                        pq.push({ tmp + 1, x + 1 });
                    if (ret[x - 1] > tmp + 1)
                        pq.push({ tmp + 1, x - 1 });
                }
            }
        }
 
        for (int i = 1; i <= n; i++) {
            cout << ret[i] << " ";
        }
        cout << "\n";
    }
}

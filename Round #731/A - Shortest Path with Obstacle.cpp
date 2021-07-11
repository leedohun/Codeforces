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
        int xa, ya, xb, yb, xf, yf;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
 
        if (xa == xf && xb == xf && ((ya < yf && yf <yb) || (yb < yf && yf < ya))) {
            cout << abs(ya - yb) + 2;
        }
        else if (ya == yf && yb == yf && ((xa < xf && xf < xb) || (xb < xf && xf < xa))) {
            cout << abs(xa - xb) + 2;
        }
        else {
            cout << abs(xa - xb) + abs(ya - yb);
        }
        cout << "\n";
    }
}

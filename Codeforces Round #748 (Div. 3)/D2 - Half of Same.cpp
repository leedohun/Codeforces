#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
 
int n;
int arr[50];
vector<int> v;
int ans;
 
void get_divisor(int x)
{
	int i;
 
	v.clear();
	for (i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			v.push_back(i);
			v.push_back(x / i);
		}
	}
}
 
void check(int s, int e, int value)
{
	int i;
	int cnt = 2;
 
	for (i = s + 1; i < e; i++)
	{
		if ((arr[i] - arr[s]) % value == 0) cnt++;
	}
 
	if (cnt >= n / 2) ans = max(ans, value);
}
 
int main()
{
	int t;
	int i, j, k;
	int cnt;
	bool same;
 
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
 
			arr[i] += 1000000;
		}
 
		sort(arr, arr + n);
 
		cnt = 1;
		same = false;
		for (i = 1; i < n; i++)
		{
			if (arr[i] != arr[i - 1])
			{
				if (cnt >= n / 2)
				{
					same = true;
					break;
				}
				cnt = 1;
			}
			else cnt++;
		}
 
		if (same || cnt >= n / 2)
		{
			cout << -1 << '\n';
			continue;
		}
 
		ans = 1;
		for (i = 0; i < n; i++)
		{
			for (j = i + n / 2 - 1; j < n; j++)
			{
				get_divisor(arr[j] - arr[i]);
 
				for (k = 0; k < v.size(); k++)
				{
					check(i, j, v[k]);
				}
			}
		}
 
		cout << ans << '\n';
	}
}

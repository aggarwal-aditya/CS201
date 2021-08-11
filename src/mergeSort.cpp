//Merge Sort
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
#define int long long
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define F first
#define S second
typedef vector<pli> vpli;
#define INF 1000000007
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define tests int t; cin>>t; while(t--)
#define take(a,b,c) for(b=0;b<c;b++) cin>>a[b];
typedef long long ll;
vector<int> adj[200007];
bool visited[200007];
bool cmp(int a, int b) {
	return a < b;
}
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};
string stepDir = "RLDU";
void merge (int *arr, int l, int m, int r)
{
	int s1 = m - l + 1, s2 = r - m;
	int lef[s1];
	int rig[s2];
	for (int i = 0; i < s1; i++) {
		lef[i] = arr[i + l];
	}
	for (int i = 0; i < s2; i++) {
		rig[i] = arr[i + m + 1];
	}
	int i = 0, j = 0;
	int k = l;
	while (i < s1 && j < s2) {
		if (lef[i] <= rig[j]) {
			arr[k++] = lef[i++];
		}
		else {
			arr[k++] = rig[j++];
		}
	}
	while (i < s1) {
		arr[k++] = lef[i++];

	}
	while (j < s2) {
		arr[k++] = rig[j++];
	}
}
void __sort(int * arr, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		__sort(arr, l, m);
		__sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
signed main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	{
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << "Array Before Sorting" << endl;
		for (int x : a)
			cout << x << " ";
		cout << endl;
		__sort(a, 0, n - 1);
		cout << "Array After Sorting" << endl;
		for (int x : a)
			cout << x << " ";
		cout << endl;


	}
}




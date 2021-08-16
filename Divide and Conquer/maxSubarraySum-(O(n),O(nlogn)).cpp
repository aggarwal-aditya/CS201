//Kadanes O(nlogn) variation by divide & conquer
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
int crossum(int *arr, int l, int m, int r) {
	int temp = 0;
	int left_max = -INF;
	for (int i = m; i >= l; i--) {
		temp += arr[i];
		left_max = max(left_max, temp);
	}
	int right_max = -INF;
	temp = 0;
	for (int i = m + 1; i <= r; i++) {
		temp += arr[i];
		right_max = max(right_max, temp);
	}
	return (right_max + left_max);
}
int maxsum(int *arr, int l, int r) {
	if (l == r)
		return arr[l];
	int m = (l + r) / 2;
	return max(maxsum(arr, l, m), max(maxsum(arr, l + 1, r), crossum(arr, l, m, r)));
}
signed main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << maxsum(arr, 0, n - 1);
	//KAdane Algo
	cout << endl << "Answer by Kadane ";
	int curr_sum = 0, max_sum = -INF;
	for (int i = 0; i < n; i++) {
		curr_sum += arr[i];
		max_sum = max(max_sum, curr_sum);
		curr_sum = max(curr_sum, 0LL);
	}
	cout << max_sum;

}

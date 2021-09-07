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
#define take(a, b, c) for(b=0;b<c;b++) cin>>a[b];
typedef long long ll;
vector<int> adj[200007];
bool visited[200007];

bool cmp(int a, int b) {
    return a < b;
}

template<typename T, typename T1>
T amax(T &a, T1 b) {
    if (b > a)a = b;
    return a;
}

template<typename T, typename T1>
T amin(T &a, T1 b) {
    if (b < a)a = b;
    return a;
}

string s;

//string res[100000];
void solve(string str, int index, string a) {
    if (index == -1) {
        cout << a << endl;
        return;
    }
    solve(str, index - 1, a + "");
    solve(str, index - 1, a + str[index]);


}

int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};
string stepDir = "RLDU";

signed main() {
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    int n = s.size();
    solve(s, n - 1, "");


}

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
string sub[100000];
string str;
int solve(string str)
{
    if(str.size()==0)
    {
        sub[0]="";
        return 1;
    }
    int small=solve(str.substr(1));
    for(int i=0;i<small;i++)
    {
        sub[i+small]=str[0]+sub[i];
    }
    return 2*small;

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
     cin>>str;
    int n=solve(str);
    sort(sub,sub+n);
     for(int i=0;i<n;i++)
     {
         cout<<sub[i]<<endl;
     }

}

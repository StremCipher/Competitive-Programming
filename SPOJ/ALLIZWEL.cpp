/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
int n,m;
string res = "ALLIZZWELL";
V<string> arr;


bool dfs(int i, int j, int k,V<V<bool> > visited){
    if(k == res.length())return true;
    if(i >= n || i < 0 || j < 0 || j >= m )return false;
    if(arr[i][j] != res[k])return false;
    if(visited[i][j])return false;
    visited[i][j] = true;
    bool res = dfs(i-1,j,k+1,visited);
    if(res == true)return res;
    res = (res || dfs(i+1,j,k+1,visited));
    if(res == true)return res;
    res = (res || dfs(i,j+1,k+1,visited));
    if(res == true)return res;
    res = (res || dfs(i,j-1,k+1,visited));
    if(res == true)return res;
    res = (res || dfs(i+1,j-1,k+1,visited));
    if(res == true)return res;
    res = (res || dfs(i-1,j-1,k+1,visited));
    if(res == true)return res;
    res = (res || dfs(i+1,j+1,k+1,visited));
    if(res == true)return res;
    res = (res || dfs(i-1,j+1,k+1,visited));
    if(res == true)return res;
    visited[i][j] = false;
    return res;
}

void solve(){
    cin >> n >> m;
    arr = V<string> (n,"");
    loop(i,0,n)cin >> arr[i];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(arr[i][j] == 'A'){
                 V<V<bool> > visited(n,V<bool> (m,false));
                if(dfs(i,j,0,visited)){
                    cout << "YES\n";
                    return ;
                }
            }
        }
    }
    cout << "NO\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
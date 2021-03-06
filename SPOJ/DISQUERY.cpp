#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll N = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
int maxi[20][N],mini[20][N],dp[20][N];
V<PII> g[N];
int lev[N];
int n;

void dfs(int s = 1, int p = 0){
    if(p == 0)lev[s] = 0;
    else lev[s] = lev[p] + 1;
    dp[0][s] = p;
    for(auto &i: g[s]){
        if(i.S != p){
            mini[0][i.S] = maxi[0][i.S] = i.F;
            dfs(i.S,s);
        }
    }
}

void pre(){
    loop(i,1,20){
        loop(j,1,n+1){
            dp[i][j] = dp[i-1][dp[i-1][j]];
            maxi[i][j] = max(maxi[i-1][j],maxi[i-1][dp[i-1][j]]);
            mini[i][j] = min(mini[i-1][j],mini[i-1][dp[i-1][j]]);
        }
    }
}

int lca(int a, int b){
    if(lev[b] < lev[a])swap(a,b);
    int diff = lev[b] - lev[a];
    loop(i,0,20)if((diff >> i)&1)b=dp[i][b];
    if(a == b)return a;
    loopr(i,19,0)if(dp[i][a] != dp[i][b])b=dp[i][b],a=dp[i][a];
    return dp[0][a];
}

int mn(int a, int b){
    int ans = INT_MAX;
    if(lev[b] < lev[a])swap(a,b);
    int diff = lev[b] - lev[a];
    loop(i,0,20)if((diff >> i)&1){ans=min(ans,mini[i][b]);b=dp[i][b];}
    return ans;
}

int mx(int a, int b){
    int ans = 0;
    if(lev[b] < lev[a])swap(a,b);
    int diff = lev[b] - lev[a];
    loop(i,0,20)if((diff >> i)&1){ans=max(ans,maxi[i][b]);b=dp[i][b];}
    return ans;
}


int main(){
    scanf("%d",&n);
    loop(i,1,n){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].pb(mp(c,b));
        g[b].pb(mp(c,a));
    }
    loop(i,0,20)loop(j,0,N)maxi[i][j]=0,mini[i][j]=INT_MAX,dp[i][j]=0;
    dfs();
    pre();
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        int l = lca(a,b);
        if(l == a || l == b){
            printf("%d %d\n",mn(a,b),mx(a,b));
        }else{
            printf("%d %d\n",min(mn(a,l),mn(b,l)),max(mx(a,l),mx(b,l)));
        }
    }
   return 0;
}
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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

vector<int> Rank;
vector<int> parent;
int findParent(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
   return x;
}
void UNION(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(Rank[a] < Rank[b]){
        parent[a]=b;
    }else if(Rank[a] > Rank[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
        Rank[b]++;
    }
}

void solve(int test_case){
    int n,m;
    cin >> n >> m;
    parent = V<int> (n+1,0);
    Rank = V<int> (n+1,0);
    ll ans = 0;
    loop(i,0,n+1)parent[i] = i;
    if(m == 0){
        ans = (n-1)*2;
    }else{
        unordered_map<int,int> connected_parent;
        while(m--){
            int a,b;
            cin >> a >> b;
            if(findParent(a) == findParent(b))continue;
            ans++;
            UNION(a,b);
        }
        for(int i = 1; i <= n; ++i){
            connected_parent[findParent(i)]++;
        }
        ans+=((connected_parent.size()-1)*2);
    }
    printf("Case #%d: %lld\n",test_case,ans);
}

int main(){
   int t = 1;
   cin >> t;
   loop(i,1,t+1){
       solve(i);
   }
   return 0;
}
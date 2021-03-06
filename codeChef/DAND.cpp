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
#define ll long long int
#define ull unsigned long long int
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
const int MAX_BIT = 62;
ll l, r, k;

struct hash_pair{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>& p)const{
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T1>{}(p.second);
        return hash1^hash2;
    }
};

unordered_map<PLL,ll, hash_pair> dp;
ll msb( ll a){
    ll cnt = 0;
    while(a > 0){
        cnt++;
        a/=2;
    }
    return cnt-1;
}

ll cnt(ll r, ll x){
    // * Supermax check
    if(x > r)return 0;
    ll ans = 0;
    bool o = false;
    loopr(i,59,0){
        if(((r >> i) & 1) == 1 && ((x >> i) & 1) == 0 && !o){
            ans+=(1LL << i);
        }else if(((x >> i) & 1) == 1){
            ans>>=1;
            if(((r >> 1) & 1) == 0) o = true;
        }
    }
    return ans + ((x & r) == x);
}

void solve(){
    ll ind = MAX_BIT;
    scanf("%lld %lld %lld",&l,&r,&k);
    ll MX = 0, Cnt = 0;
	ll pr = 0, pl = 0;
	bool tr = 1, tl = 1;
	for (int i = 59; ~ i; i --)
	{
		Cnt = (pr >> 1) - (pl >> 1);
		if (tr & ((r>>i)&1))
			Cnt += (r & ((1LL << i) - 1)) + 1;
		if (tl & ((l>>i)&1))
			Cnt -= (l & ((1LL << i) - 1)) + 1;
		if (Cnt >= k)
		{
			MX |= 1LL << i;
			pl >>= 1; tl &= ((l >> i) & 1);
			pr >>= 1; tr &= ((r >> i) & 1);
		}
		else
		{
			pl |= (tl & ((l >> i) & 1)) << i;
			pr |= (tr & ((r >> i) & 1)) << i;
		}
	}
    printf("%lld\n",MX);
}

int main(){
   int t = 0;
    scanf("%d",&t);
   while(t--){
       solve();
   }
//    cout << cnt(9,4) << "\n";
   return 0;
}
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
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    FAST
    list<PLL> arr;
    int n;
    ll k;
    cin >> n >> k;
    V<ll> a(n);
    loop(i,0,n)cin >> a[i];
    sort(all(a));
    arr.pb(mp(a[0],1));
    loop(i,1,n){
        if(arr.back().first == a[i]){
            arr.rbegin()->second++;
        }else{
            arr.pb(mp(a[i],1));
        }
    }
    while(1){
        // printf("k = %lld\n",k);
        // for(auto i: arr){
        //     printf("(%lld, %lld)\t",i.F,i.S);
        // }
        // printf("\n");
        if(arr.size() == 1)break;
        ll fdiff = (next(arr.begin())->first - arr.begin()->first);
        ll ldiff = (prev(arr.end())->first - prev(prev(arr.end()))->first);
        ll f = fdiff*(arr.begin()->second);
        ll l = ldiff*(arr.rbegin()->second);
        if(arr.begin()->second < arr.rbegin()->second){
            if(f < k){
                k-=f;
                ll s = arr.begin()->second;
                arr.pop_front();
                arr.begin()->second+=s;
            }else{
                // ll inc = k/arr.begin()->second - (k%arr.begin()->second != 0);
                ll inc = k/arr.begin()->second;
                cout << arr.back().first - (arr.front().first+inc);
                return 0;
            }
        }else{
            if(l < k){
                k-=l;
                ll s = arr.rbegin()->second;
                arr.pop_back();
                arr.rbegin()->second+=s;
            }else{
                // ll dec = k/arr.rbegin()->second + (k%arr.rbegin()->second != 0);
                ll dec = k/arr.rbegin()->second;
                cout << (arr.back().first - dec) - (arr.front().first);
                return 0;
            }
        }
    }
    cout << 0;
   return 0;
}
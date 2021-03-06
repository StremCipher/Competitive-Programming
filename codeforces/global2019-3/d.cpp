/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
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

bool cmp1(PII &a, PII &b){
    if(a.S < b.S)return true;
    if(b.S > a.S)return false;
    return false;
}
bool cmp2(PII &a, PII &b){
    if(a.S < b.S)return false;
    if(b.S > a.S)return true;
    return true;
}
int main(){
    FAST
    V<PII> inc;
    V<PII> dec;
    int n;
    cin >> n;
    map<PII,int> ind;
    V<int> ans;
    loop(i,0,n){
        int a,b;
        cin >> a >> b;
        if(b > a){
            inc.pb(mp(a,b));
        }else if(a > b){
            dec.pb(mp(a,b));
        }
        ind[mp(a,b)] = i+1;
    }
    sort(all(inc),cmp2);
    sort(all(dec),cmp1);
    PII c;
    V<int> tmp1;
    V<int> tmp2;
    c = mp(inf,inf);
    loop(i,0,inc.size()){
        if(inc[i].F < c.S){
            tmp1.pb(ind[inc[i]]);
            c = inc[i];
        }
    }
    c = mp(-1,-1);
    loop(i,0,dec.size()){
        if(dec[i].F > c.S){
            tmp2.pb(ind[dec[i]]);
            c = dec[i];
        }
    }
    if(tmp1.size() > tmp2.size()){
        cout << tmp1.size() << "\n";
        for(auto &i: tmp1){
            cout << i << " ";
        }
    }else{
        cout << tmp2.size() << "\n";
        for(auto &i: tmp2){
            cout << i << " ";
        }
    }
    return 0;
}
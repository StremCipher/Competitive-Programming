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
    int n,k;
    cin >> n >> k;
    priority_queue<int> p;
    unordered_map<int,int> m;
    V<int> arr(n);
    loop(i,0,n)cin >> arr[i];
    for(int i = 0; i < k; ++i)m[arr[i]]++;
    for(auto &i: m){
        if(i.second == 1)p.push(i.first);
    }
    if(p.size() == 0)cout << "Nothing\n";
    else cout << p.top() << "\n";
    for(int i = k; i < n; ++i){
        m[arr[i-k]]--;
        if(m[arr[i-k]] == 1)p.push(arr[i-k]);
        m[arr[i]]++;
        if(m[arr[i]] == 1)p.push(arr[i]);
        // cout << "i = " << i << "\n";
        while(p.size() && m[p.top()] != 1){
            // cout << p.top() << " ";
            p.pop();
        }
        // cout << "\n";
        if(p.size() == 0)cout << "Nothing\n";
        else cout << p.top() << "\n";
    }
   return 0;
}
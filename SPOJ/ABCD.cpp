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
    int n;
    cin >> n;
    string a;
    cin >> a;
    string ans = "";
    for(int i = 0; i < 2*n; i+=2){
        string to_add = "";
        if(a[i] == 'A' && a[i+1] == 'B')to_add = "CD";
        else if(a[i] == 'A' && a[i+1] == 'C')to_add = "BD";
        else if(a[i] == 'A' && a[i+1] == 'D')to_add = "BC";
        else if(a[i] == 'B' && a[i+1] == 'A')to_add = "CD";
        else if(a[i] == 'B' && a[i+1] == 'C')to_add = "AD";
        else if(a[i] == 'B' && a[i+1] == 'D')to_add = "AC";
        else if(a[i] == 'C' && a[i+1] == 'A')to_add = "BD";
        else if(a[i] == 'C' && a[i+1] == 'B')to_add = "AD";
        else if(a[i] == 'C' && a[i+1] == 'D')to_add = "AB";
        else if(a[i] == 'D' && a[i+1] == 'A')to_add = "BC";
        else if(a[i] == 'D' && a[i+1] == 'B')to_add = "AC";
        else if(a[i] == 'D' && a[i+1] == 'C')to_add = "AB";
        if(ans.size() && ans.back() == to_add.front())reverse(all(to_add));
        ans+=to_add;
    }
    cout << ans;
   return 0;
}
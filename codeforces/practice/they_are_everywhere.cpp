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
int n;
string a;
unordered_map<char,int> m;

bool check(int k){
    unordered_map<char,int> m1;
    for(int i = 0; i < k; ++i)m1[a[i]]++;
    if(m1.size() == m.size())return true;
    for(int i = k; i < a.size(); ++i){
        m1[a[i-k]]--;
        if(m1[a[i-k]] == 0)m1.erase(a[i-k]);
        m1[a[i]]++;
        if(m1.size() == m.size())return true;
    }
    return false;
}

int main(){
    cin >> n >> a;
    int low = 1;
    int high = n;
    int ans = n;
    for(char &i: a)m[i]++;
    while(low <= high){
        int mid = (low + high)/2;
        if(check(mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << ans;
    return 0;
}
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
using namespace std;

const ll maxn = 1e5;

int main(){
    int n,k;
    cin >> n >> k;
    V<int> arr(n);
    loop(i,0,n)cin >> arr[i];
    int ans = 0;
    V<int> b(n);
    for(int i = 0; i < n; ++i){
        int f = 0;
        int s = 0;
        for(int j = 0; j < n; ++j)b[j] = arr[j];
        for(int j = i; j < n; j+=k)b[j] = 0;
        for(int j = i; j >= 0; j-=k)b[j] = 0;
        for(int j = 0; j < n; ++j){
            if(b[j] > 0)f++;
            if(b[j] < 0)s++;
        }
        ans = max(abs(f-s),ans);
    }
    cout << ans;
    return 0;
}
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
set<int> pr;
void solve(){
    int n;
    cin >> n;
    unordered_map<int,int> odd;
    unordered_map<int,int> even;
    ll os = 0;
    ll es = 0;
    ll ans = 0;
    loop(i,0,n){
        int a;
        cin >> a;
        if(a%2){
            ll total_pairs = os;
            ll xor2 = a^2;
            ll xor0 = a;
            total_pairs -= (odd[xor2] + odd[xor0]);
            ans += total_pairs;
            odd[a]++;
            os++;
        }
        else{
            ll total_pairs = es;
            ll xor2 = a^2;
            ll xor0 = a;
            total_pairs -= (even[xor2] + even[xor0]);
            ans += total_pairs;
            even[a]++;
            es++;
        }   
    }
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
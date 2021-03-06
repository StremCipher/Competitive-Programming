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

int main(){
    ll n;
    cin >> n;
    if(n == 1){
        cout << "1 0";
        return 0;
    }
    map<int,int> m;
    ll k = n;
    while(n%2 == 0){
        m[2]++;
        n/=2;
    }
    for(int i = 3; i <= k; i+=2){
        while(n%i == 0){
            m[i]++;
            n/=i;
        }
    }
    ll ans = 0;
    int mx = 0;
    int mn = INT_MAX;
    for(auto i: m){
        mx = max(mx,i.second);
        mn = min(mx,i.second);
    }
    int i = 0;
    while((1 << i) < mx)i++;
    if(mx == (1 << i) && mn == (1 << i))ans = 0;
    else ans++;
    ans+=i;
    // for(auto i: m){
    //     cout << i.first << " " << i.second << "\n";
    // }
    ll prep = 1;
    for(auto i: m){
        prep*=i.first;
    }
    cout << prep << " " << ans;
    return 0;
}
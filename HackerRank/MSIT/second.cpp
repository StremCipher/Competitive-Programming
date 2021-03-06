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

const ll maxn = 2e6;

int main(){
    FILE_READ_OUT
    FILE_READ_IN
    int arr[maxn] = {0};
    loop(i,2,maxn){
        if(arr[i] == 0){
            for(int j = 2; i*j < maxn; ++j)arr[i*j]++;
        }
    }
    V<int> primes;
    loop(i,2,maxn){
        if(arr[i] == 0)primes.pb(i);
    }
    // for(int i = 0; i < 10; ++i)cout << primes[i] << " ";
    // cout << endl;
    V<ll> sum;
    sum.pb(0);
    for(auto i: primes){
        sum.pb(*sum.rbegin() + i);
    }
    int q;
    cin >> q;
    // cout << q << "\n";
    V<ll> ans;
    while(q--){
        int n;
        cin >> n;
        ans.pb(sum[n]);
        // cout << n << "\n";
    }
    // cout << "ANS\n";
    for(auto i: ans){
        cout << i << "\n";
    }
    return 0;
}
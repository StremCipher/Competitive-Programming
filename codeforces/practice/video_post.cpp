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
    int n,k;
    cin >> n >> k;
    V<ll> arr(n);
    ll s = 0;
    loop(i,0,n){
        cin >> arr[i];
        s+=arr[i];
    }
    if(s%k != 0){
        cout << "No";
        return 0;
    }
    s/=k;
    V<ll> ans;
    ll s1 = 0;
    int c = 0;
    loop(i,0,n){
        s1+=arr[i];
        c++;
        if(s1 == s){
            ans.pb(c);
            c = 0;
            s1 = 0;
        }
    }
    if(ans.size() == k){
        cout << "Yes\n";
        for(auto i: ans){
            cout << i << " ";
        }
    }else{
        cout << "No";
    }
    return 0;
}
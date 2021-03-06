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
    int n;
    cin >> n;
    V<double> arr(n);
    loop(i,0,n)cin >> arr[i];
    loop(i,0,n){
        if(arr[i] == 1){
            cout << "1.000000000000";
            return 0;
        }
    }
    sort(arr.begin(),arr.end(),greater<double>());
    double S = arr[0]/(1-arr[0]);
    double P = 1-arr[0];
    double ans = P*S;
    for(int i = 1; i < n; ++i){
        S+=(arr[i]/(1-arr[i]));
        P*=(1-arr[i]);
        ans = max(ans,P*S);
    }
    ans = max(ans,arr[0]);
    printf("%.12f",ans);
    return 0;
}
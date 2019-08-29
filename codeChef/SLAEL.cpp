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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
vector<ll> arr;

ll k;
bool bs(int p){
    int g = 0;
    unordered_map<ll,int> m;
    for(int i = 0; i < p; ++i){
        if(arr[i] > k){
            if(m[arr[i]] == 0)g++;
            m[arr[i]]++;
        }
    }
    if(g == 1)return true;
    for(int i = p; i < arr.size(); ++i){
        if(arr[i-p] > k){
            if(m[arr[i-p]] == 1)g--;
            m[arr[i-p]]--;
        }
        if(arr[i] > k){
            if(m[arr[i]] == 0)g++;
            m[arr[i]]++;
        }
        if(g == 1)return true;
    }
    return false;
}

void solve(){
    int n;
    cin >> n >> k;
    arr = vector<ll>(n);
    loop(i,0,n)cin >> arr[i];
    int high = n;
    int low = 0;
    int ans = 0;
    while(low <= high){
        int mid = (low+high)/2;
        if(bs(mid)){
            ans = max(ans,mid);
            low = mid+1;
        }
        else high = mid-1;
    }
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
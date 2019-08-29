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

void solve(){
    int last = -1;
    int n,no_pos = 1;
    cin >> n;
    unordered_map<int,vector<int> > m;
    vector<int> arr(n);
    loop(i,0,n){
        cin >> arr[i];
        if(arr[i] != -1)no_pos = 0;
        if(arr[i] != -1){
            if(m.find(arr[i]) != m.end()){
                m[arr[i]].pb(i);
            }
            else{
                m[arr[i]] = vector<int>();
                m[arr[i]].pb(i);
            }
        } 
    }
    loop(i,0,n){
        if(arr[i] != -1){
            if(last != -1){
                if(arr[last] < arr[i] && arr[i]-arr[last] != i-last){
                    cout <<  "impossible\n";
                    return ;
                }
            }
            last = i;
        }
    }
    int more_than_1 = 0;
    int period = -1;
    for(auto b: m){
        auto i = b.second;
        if(i.size() > 1){
            if(period == -1){
                period = i[1]-i[0];
            }
            if(period != -1){
                for(int k = 1; k < i.size(); ++k){
                    if((i[k]-i[k-1])%period != 0){
                        cout << "impossible\n";
                        return;
                    }
                }
            }
            more_than_1 = 1;
        }
    }
    if(more_than_1 == 0){
        cout << "inf\n";
        return;
    }
    for(int i = 0; i < n; ++i){
        if(i+period < n){
            if(arr[i+period] != -1 && arr[i] != -1 && arr[i] != arr[i+period]){
                cout << "impossible\n";
                return;
            }
        }
        if(i > 0){
            if(arr[i] != -1 && arr[i-1] != -1){
                if(arr[i] == 1 && arr[i-1] != period){
                    cout << "impossible\n";
                    return;
                }
                else if(arr[i] != 1 && arr[i-1]-arr[i] != 1){
                    cout << "impossible\n";
                    return;
                }
            }
        }
    }
    cout << period << "\n";
    
}

int main(){
    // freopen("input.txt","r",stdin);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
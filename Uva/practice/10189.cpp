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
#define MAXN 1001000
using namespace std;
int main(){
    // FILE_READ
    int f = 1;
    while(1){
        int n,m;
        cin >> n >> m;
        if(n == 0 || m == 0){
            break;
        }
        if(f > 1)cout << "\n";
        vector<vector<int> > ans(n,vector<int>(m,0));
        vector<string> s;
        for(int i = 0; i < n; ++i){
            string a;
            cin >> a;
            s.pb(a);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                pair<int,int> p[8] = {mp(-1,-1),mp(-1,0),mp(-1,1),mp(0,-1),mp(0,1),mp(1,-1),mp(1,0),mp(1,1)};
                if(s[i][j] == '*'){
                    ans[i][j] = -1;
                    continue;
                }
                for(int k = 0; k < 8; ++k){
                    int a = i + p[k].first;
                    int b = j + p[k].second;
                    if(a >= 0 && a < n && b >= 0 && b < m){
                        if(s[a][b] == '*')ans[i][j]++;
                    }
                }
            }
        }
        cout << "Field #" << f++ << ":\n";
        for(auto i: ans){
            for(auto j: i){
                if(j == -1)cout << "*";
                else cout << j;
            }
            cout << "\n";
        }
    }
    return 0;
}
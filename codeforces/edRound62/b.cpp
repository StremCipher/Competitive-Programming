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

void solve(){
    stack<char> s1;
    stack<char> s2;
    string a;
    int n;
    cin >> n;
    cin >> a;
    int a1 = 0;
    int a2 = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == '<'){
            while(s1.size()){
                s1.pop();
                a1++;
            }
        }else{
            s1.push(i);
        }
    }
    for(int i = a.size()-1; i >= 0; --i){
        if(a[i] == '>'){
            while(s2.size()){
                s2.pop();
                a2++;
            }
        }else{
            s2.push(i);
        }
    }
    cout << min(s1.size(),s2.size()) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
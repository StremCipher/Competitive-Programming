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
    while(1){
        int r;
        cin >> r;
        if(r <= 0)break;
        string a;
        cin >> a;
        unordered_map<char,int> m1,m2;
        int unique = 0;
        for(auto i : a){
            if(m1[i] == 0)unique++;
            m1[i] = 1;
        }
        cin >> a;
        int found = 0;
        int wrongMoves = 0;
        for(int i = 0; i < a.length(); ++i){
            if(m1[a[i]] != 0){
                found+=(m2[a[i]] ^ 1);
                m2[a[i]] = 1;
            }else{
                wrongMoves+=(m2[a[i]] ^ 1);
                m2[a[i]] = 1;
            }
            if(found >= unique)break;
            if(wrongMoves >= 7)break;
        }
        printf("Round %d\n",r);
        if(found >= unique){
            cout << "You win.\n";
        }
        else if(wrongMoves >= 7){
            cout << "You lose.\n";
        }else{
            cout << "You chickened out.\n";
        }
    }
   return 0;
}
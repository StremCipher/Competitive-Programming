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
  string a;
  cin >> a;
  if(n%2 == 1 || a[n-1] == '(' || a[1] == ')' || a[0] == ')'){
    printf(":(");
    return 0;
  }
  a[1] = '(';
  a[0] = '(';
  V<int> q,c,o;
  if(n == 2){
    cout << "()";
    return 0;
  }
  loop(i,1,n-1){
    if(a[i] == ')'){
      if(o.size() == 0 && q.size() == 0){
        printf(":(");
        return 0;
      }
      if(o.size()){
        o.erase(o.begin());
      }
      else if(q.size()){
        a[*q.begin()] = '(';
        q.erase(q.begin());
      }
    }
    else if(a[i] == '('){
      o.pb(i);
    }
    else{
      q.pb(i);
    }
  }
  if(o.size() > q.size()){
    printf(":(");
    return 0;
  }
  q.clear();
  o.clear();
  c.clear();
  loopr(i,n-2,1){
    if(a[i] == '('){
      if(c.size() == 0 && q.size() == 0){
        printf(":(");
        return 0;
      }
      if(c.size()){
        c.erase(c.begin());
      }
      else if(q.size()){
        a[*q.begin()] = ')';
        q.erase(q.begin());
      }
    }
    else if(a[i] == ')'){
      c.pb(i);
    }
    else{
      q.pb(i);
    }
  }
  if(q.size()){
    for(int i = 0; i < q.size(); ++i){
      if(i%2 == 0)a[q[i]] = ')';
      else a[q[i]] = '(';
    }
  }
  int op = 0;
  for(int i = 0; i < a.size(); ++i){
    if(a[i] == ')' && op == 0){
      printf(":(");
      return 0;
    }
    else if (a[i] == ')')op--;
    else if(a[i] == '(')op++;
  } 
  a[n-1] = ')';
  // if(op){
  //   printf(":(");
  //   return 0;
  // }
  cout << a;
  return 0;
}

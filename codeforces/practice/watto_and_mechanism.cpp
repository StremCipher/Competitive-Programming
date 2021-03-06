#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
const int N = 3e5+100;

struct node{
    int cnt;
	unordered_map<int,node*> child;
    node():cnt(0){}
};
string s;

class Trie{
public:
	struct node* top;
	Trie(){
		top = new node();
	}
	void addString(){
		struct node *cur = top;
		for(auto i: s){
			if(cur->child.find(i-'a') == cur->child.end()){
				cur->child[i-'a'] = new node();
            }
			cur = cur->child[i-'a'];
            cur->cnt++;
        }
	}
	void deleteString(){
		struct node *cur = top;
		for(auto i: s){
			cur = cur->child[i-'a'];
            cur->cnt--;
        }
	}
    bool present(){
		struct node *cur = top;
		for(auto i: s){
			if(cur->child.find(i-'a') == cur->child.end()){
                return false;
            }
			cur = cur->child[i-'a'];
        }
        return true;
    }
	bool possible(node* cur, int pos = 0 ,int cnt = 0){
		if(pos == s.size() && cnt == 1)return true;
		if(cnt > 1)return false;
		int j = s[pos]-'a';
		bool ans = false;
		loop(k,0,3){
			if(cur->child.find(k) != cur->child.end() && cur->child[k]->cnt > 0)ans|=possible(cur->child[k],pos+1,cnt+(k!=j));
		}
		return ans;
		// if(cur->child.find(j) == cur->child.end() || cur->child[j]->cnt == 0){
		// }
		// return possible(cur->child[j],pos+1,cnt);
	}
};

int main(){
	FAST
	unordered_map<int,Trie*> m;
	int n,nm;
	cin >> n >> nm;
	while(n--){
		cin >> s;
		if(m.find(s.size()) == m.end())m[s.size()] = new Trie();
		if(!m[s.size()]->present())m[s.size()]->addString();
	}
	while(nm--){
		cin >> s;
		if(m.find(s.size()) == m.end())m[s.size()] = new Trie();
        // bool p =false;
        // if(m[s.size()]->present()){
        //     m[s.size()]->deleteString();
        //     p =true;
        // }
        if(m[s.size()]->possible(m[s.size()]->top)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
        // if(p){
        //     m[s.size()]->addString();
        // }
	}
	return 0;
}
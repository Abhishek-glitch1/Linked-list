#include<bits/stdc++.h>
#include<bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//template<typename T>
 //using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF 1e18
#define nline "\n"
#define ll long long
#define ull  unsigned long long
#define lld  long double
#define ld  long double;
#define fr first
#define sc second
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define allr1(v) (v).rbegin()+1,(v).rend()
#define sort0(v) sort(all(v))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
//debug
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


#define sz(x) (ll)x.size()
#define pb push_back
#define pf push_front
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005
const ll mod = 1e9 + 7;
const int dx[9] = {1,0,-1,0,1,-1,-1,1,0};
const int dy[9] = {0,1,0,-1,1,-1,1,-1,0};
const int N=1e5 ;bitset<N> b;
vector<ll> primes;
void seive()
{
  b.set(); for(ll i=2;i<=N;i++)if(b[i]){ primes.pb(i);for(ll j=i*i;j<=N;j+=i)b[j]=0;}   
}
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Node
{
public:
	 int data;
     Node *next;

    Node(int data)
	{
     	this->data=data;
     	next=NULL;
     }
	
     
	
};
class Tnode
{
public:
	int data;
	Tnode * left,*right;
	Tnode(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
	
	
};
void addatend(Node *head,int data)
{
	while(head->next!=NULL)head=head->next;
	Node *tmp=new Node(data);
	head->next=tmp;
}

int cnt;
void display(Node *head)
{
	while(head!=NULL){
		cnt++;
		cout<<head->data<<" ";
     head=head->next;
   }
	cout<<endl; 
}

void insert(Tnode * &trav,int key)
{
	Tnode *r=NULL, *tmp;
	if(trav==NULL)
	{
      trav=new Tnode(key); return;
	}
    Tnode *t=trav;
    while(t!=NULL)
    {
    	r=t;
    	if(key==t->data)return;
    	else if(key<t->data)
    		t=t->left;
    	else t=t->right;
    }
    tmp=new Tnode(key);
    if(key<r->data)
    	r->left=tmp;
    else if(key>r->data)
    	r->right=tmp;


}
void displayBst(Tnode *bst)
{
	if(bst==NULL)return;
	cout<<bst->data<<" ";
	displayBst(bst->left);
	displayBst(bst->right);
}


void solve()
{

	Node * head=NULL;
	int n; cin>>n;
	rep(i,0,n)
	{
		 int e; cin>>e;
       if(i==0)
       { 
       	 head=new Node(e); continue;
       }
      
       addatend(head,e);
	}
	
	display(head);
	Node *fst=head,*slow=head;
	while( (fst && fst->next) )
	{
        fst=fst->next->next;
        slow=slow->next;
	}
	cout<<"Middle"<<" ";
	cout<<slow->data<<endl;

	Tnode *bst=NULL;
	while(head!=NULL)
	{
       insert(bst,head->data);
       head=head->next;
	}

	displayBst(bst);

}


int main(){
 
 fast; 
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("Error.txt", "w", stderr);
#endif

 int tests=1;
  cin>>tests;
  while(tests--)
  solve();


}

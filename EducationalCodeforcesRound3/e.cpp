// Code14 - vim:set fdm=marker:
// {{{
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

// part of these from betaveros
#define fori(i,a,b) for(int i = a; i <= int(b); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define rep(n) fori(_conc2(_,__LINE__),1,n)
#define allof(s) (s).begin(), (s).end()
#define mkp make_pair
#define pushb push_back
#define popb pop_back
#define fi first
#define sd second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int oo = 0x3f3f3f3f;
const ll  OO = 0x3f3f3f3f3f3f3f3fLL;
const int       M7  = 1000000007;
const int       M9  = 1000000009;
const long long M7L = 1000000007L;

#ifdef DEBUG
#define debug(code) code
#define debugf(...) \
	fprintf(stderr,  __VA_ARGS__)

// from SHIK {{{
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0)

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,allof(c)); }
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,allof(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,allof(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,allof(c)); }
// from SHIK }}}
#else
#define debug(code)
#define debugf(...)
#define dump(...)
#endif

// from SHIK {{{
template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%lld",&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const long long &x ) { printf("%lld",x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

template<typename T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
// from SHIK }}}
// }}}

#define N 200005
#define LOGN 20

typedef pair<ll, pair<int, PII>> Edge;
typedef vector<Edge> Edges;
typedef map<int, ll> MIL;

int n, m;
Edges edges, mst;
int root[N];
ll mst_cost;
MIL adje[N];
int fat[N][LOGN];
ll maxe[N][LOGN];
int tin[N], tout[N];
int gtime, hight;
ll ans[N];

int findset(int p)
{/*{{{*/
	if (root[p] == -1) {
		return p;
	}
	return root[p] = findset(root[p]);
}/*}}}*/

void joinset(int p, int q)
{/*{{{*/
	p = findset(p);
	q = findset(q);

	if (p != q) {
		root[q] = p;
	}
}/*}}}*/

void kruskal()
{/*{{{*/
	int u, v;
	ll w;

	memset(root, -1, sizeof(root));
	mst.clear();
	fori (i, 1, n) {
		adje[i].clear();
	}
	mst_cost = 0;

	sort(allof(edges));

	for (auto edge : edges) {
		w = edge.fi;
		u = edge.sd.sd.fi;
		v = edge.sd.sd.sd;

		if (findset(u) != findset(v)) {
			mst_cost += w;
			mst.pushb(edge);
			adje[u].insert(mkp(v, w));
			adje[v].insert(mkp(u, w));
			joinset(u, v);
		}
	}
}/*}}}*/

bool upper(int u, int v)
{
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void dfs(int u, int p)
{
	if (tin[u]) return;

	tin[u] = ++gtime;

	fat[u][0] = p;
	maxe[u][0] = adje[p][u];

	fori (i, 1, hight) {
		fat[u][i] = fat[fat[u][i-1]][i-1];
		maxe[u][i] = max(maxe[u][i-1], maxe[fat[u][i-1]][i-1]);
	}

	for (auto to : adje[u]) {
		if (to.fi == p) continue;

		dfs(to.fi, u);
	}

	tout[u] = ++gtime;
}

ll maxEdgeGet(int u, int v)
{
	ll ret = 0;

	if (upper(u, v))
		goto END;

	for (int i = hight; i >= 0; i--) {
		if (!upper(fat[u][i], v)) {
			chkmax(ret, maxe[u][i]);
			u = fat[u][i];
		}
	}

	chkmax(ret, maxe[u][0]);

END:
	return ret;
}

int main(int argc, char *argv[])
{
	int u, v, e;
	ll w;

	R(n, m);

	fori (i, 1, m) {
		R(u, v, w);
		edges.pushb(mkp(w, mkp(i, mkp(u, v))));
	}

	kruskal();

	gtime = 0;
	hight = ceil(log2(n));
	adje[1].insert(mkp(1, 0));

	dfs(1, 1);

	for (auto edge : edges) {
		w = edge.fi;
		e = edge.sd.fi;
		u = edge.sd.sd.fi;
		v = edge.sd.sd.sd;

		ans[e] = mst_cost - max(maxEdgeGet(u, v), maxEdgeGet(v, u)) + w;
	}

	fori (i, 1, m) {
		W(ans[i]);
	}

	return 0;
}

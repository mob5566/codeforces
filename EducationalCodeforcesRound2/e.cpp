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

#define N 100005

typedef map<int, int> MII;
typedef set<PII, greater<PII>> SII;
typedef vector<PII> VII;

struct Node {
	MII occ;
	SII tr;
	ll sum;
};

int n;
int color[N];
VI nxt[N];
ll cnt[N];
set<int> vis;

void merge(Node &a, const Node &b)
{
	int occval, clrval;
	int maxOcc = a.tr.begin()->fi;

	for (auto u : b.tr) {
		occval = u.fi;
		clrval = u.sd;
		auto idx = a.occ.find(clrval);

		if (idx == a.occ.end()) {
			a.occ[clrval] = occval;
		} else {
			a.tr.erase({a.occ[clrval], clrval});
			a.occ[clrval] += occval;
		}
		a.tr.insert({a.occ[clrval], clrval});

		if (chkmax(maxOcc, a.occ[clrval])) {
			a.sum = clrval;
		} else if (maxOcc == a.occ[clrval]) {
			a.sum += clrval;
		}
	}
}

Node dfs(int u)
{
	Node nd;

	vis.insert(u);

	nd.tr.insert({1, color[u]});
	nd.occ[color[u]] = 1;
	nd.sum = color[u];

	for (int v : nxt[u]) {
		if (vis.find(v) != vis.end())
			continue;
		Node subnd = dfs(v);

		if (subnd.tr.size() > nd.tr.size()) {
			swap(nd, subnd);
		}

		merge(nd, subnd);
	}

	cnt[u] = nd.sum;

	return nd;
}

int main(int argc, char *argv[])
{
	int u, v;

	R(n);

	fori (i, 1, n) {
		R(color[i]);
	}

	rep (n-1) {
		R(u, v);
		nxt[u].pushb(v);
		nxt[v].pushb(u);
	}

	dfs(1);

	fori (i, 1, n) {
		if (1 < i) putchar(' ');
		printf("%lld", cnt[i]);
	}
	putchar('\n');

	return 0;
}

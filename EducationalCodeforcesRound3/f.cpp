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
#define M (1<<18)
#define fat(x) ((x)>>1)
#define lch(x) ((x)<<1)
#define rch(x) (((x)<<1)+1)
#define bro(x) ((x)^1)

typedef multiset<pair<ll, ll>> SLL;
typedef pair<ll, pair<ll, int>> Frog;

int n, m;
ll segt[M<<1];
Frog frogs[N];
int mocnt[N];
ll ans[N];
SLL une_mo;

void update(int u, ll val)
{
	segt[u+M] = val;

	for (int i = u+M; i > 1; i = fat(i)) {
		segt[fat(i)] = max(segt[i], segt[bro(i)]);
	}
}

int bisearch(ll val)
{
	int u = 1;

	while (u < M) {
		if (segt[lch(u)] >= val) {
			u = lch(u);
		} else {
			u = rch(u);
		}
	}

	return u-M;
}

ll query(int l, int r)
{
	ll ret = 0;

	for (l = l+M-1, r = r+M+1; l^r^1; l = fat(l), r = fat(r)) {
		if (~l&1) ret = max(ret, segt[bro(l)]);
		if ( r&1) ret = max(ret, segt[bro(r)]);
	}

	return ret;
}

int main(int argc, char *argv[])
{
	ll p, b, v;
	int idx;

	R(n, m);

	fori (i, 1, n) {
		R(frogs[i].fi, frogs[i].sd.fi);
		frogs[i].sd.sd = i;
	}

	sort(frogs+1, frogs+1+n);

	fori (i, 1, n) {
		update(i, frogs[i].fi+frogs[i].sd.fi);
	}

	segt[M] = segt[M+n+1] = -1;

	rep (m) {
		R(p, b);

		idx = upper_bound(frogs+1, frogs+1+n, mkp(p, mkp(OO, oo))) - (frogs+1);

		if (idx <= 0 ) {
			continue;
		}
		if (query(1, idx) < p) {
			une_mo.insert(mkp(p, b));
			continue;
		}

		idx = bisearch(p);
		v = segt[idx+M]+b;
		mocnt[frogs[idx].sd.sd]++;

		auto it = une_mo.lower_bound(mkp(frogs[idx].fi, 0LL));

		while (it != une_mo.end() && it->fi <= v) {
			auto oit = it++;

			v += oit->sd;
			mocnt[frogs[idx].sd.sd]++;

			une_mo.erase(oit);
		}

		update(idx, v);
	}

	fori (i, 1, n) {
		ans[frogs[i].sd.sd] = segt[i+M]-frogs[i].fi;
	}

	fori (i, 1, n) {
		W(mocnt[i], ans[i]);
	}

	return 0;
}

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

#define N 55
typedef vector<PII> VII;

int n, m;
int pre[N];
int deg[N];
VII newedges;
bool hascycle;

int findset(int p)
{/*{{{*/
	if (pre[p] < 0) {
		return p;
	}

	return pre[p] = findset(pre[p]);
}/*}}}*/

int joinset(int p, int q)
{/*{{{*/
	p = findset(p);
	q = findset(q);

	if (p != q) {
		pre[p] = q;
	}
}/*}}}*/

bool checkfailed()
{
	bool failed = true;

	if (m > n) {
		goto END;
	}

	if (hascycle) {
		goto END;
	}

	fori (i, 1, n) {
		if (deg[i] > 2) {
			goto END;
		}
	}

	failed = false;
END:
	return failed;
}

bool checksucceed()
{
	bool succeed = false;
	bool setvis[N] = {0};
	int cntset = 0;

	fori (i, 1, n) {
		if (deg[i] != 2) {
			goto END;
		}
		if (!setvis[findset(i)]) {
			setvis[findset(i)] = true;
			++cntset;
		}
	}

	if (cntset != 1) {
		goto END;
	}

	succeed = true;
END:
	return succeed;
}

void solve()
{
	newedges.clear();

	fori (u, 1, n) {
		fori (v, 1, n) {
			if (deg[u] < 2 &&
				deg[v] < 2 &&
				findset(u) != findset(v)) {
				joinset(u, v);
				++deg[u];
				++deg[v];
				newedges.pushb(mkp(u, v));
			}
		}
	}

	PII tmpp = {-1, -1};

	fori (i, 1, n) {
		if (deg[i] == 0) {
			tmpp = mkp(i, i);
			break;
		}
		if (deg[i] == 1) {
			if (tmpp.fi != -1) {
				tmpp.sd = i;
				break;
			} else {
				tmpp.fi = i;
			}
		}
	}

	newedges.pushb(tmpp);
}

int main(int argc, char *argv[])
{
	int u, v;

	memset(pre, -1, sizeof(pre));
	memset(deg, 0, sizeof(deg));
	hascycle = false;

	R(n, m);

	fori (i, 1, m) {
		R(u, v);

		++deg[u];
		++deg[v];

		if (findset(u) == findset(v)) {
			hascycle = true;
		}

		joinset(u, v);
	}

	if (checksucceed()) {
		W("YES\n0");
	} else if (checkfailed()) {
		W("NO");
	} else {
		solve();

		W("YES");
		W(newedges.size());

		for (PII v : newedges) {
			W(v.fi, v.sd);
		}
	}

	return 0;
}

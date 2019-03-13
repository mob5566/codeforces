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

typedef vector<pair<ll, int>> VLI;
typedef vector<PII> VII;

int n, m, k;
ll s;

ll cost[3][N];
ll minc[3][N];
int mini[3][N];
VLI gadget[3];
VII ans;

bool valid(int day)
{
	ll minv[3] = {0, minc[1][day], minc[2][day]};
	int u, v;
	ll costu, costv;
	ll budget = s;
	bool ret = false;

	ans.clear();
	u = v = 0;

	while ((u+v) < k) {
		costv = costu = OO;

		if (u < gadget[1].size()) {
			costu = gadget[1][u].fi * minv[1];
		}
		if (v < gadget[2].size()) {
			costv = gadget[2][v].fi * minv[2];
		}

		if (min(costu, costv) > budget) {
			goto END;
		}

		if (costu <= costv) {
			ans.pushb(mkp(gadget[1][u++].sd, 1));
			budget -= costu;
		} else {
			ans.pushb(mkp(gadget[2][v++].sd, 2));
			budget -= costv;
		}
	}

	ret = true;
END:
	return ret;
}

int main(int argc, char *argv[])
{
	int t;
	ll c;
	int l, r, mid;

	R(n, m, k, s);

	minc[1][0] = minc[2][0] = OO;

	fori (j, 1, 2) {
		fori (i, 1, n) {
			R(cost[j][i]);

			if (minc[j][i-1] <= cost[j][i]) {
				minc[j][i] = minc[j][i-1];
				mini[j][i] = mini[j][i-1];
			} else {
				minc[j][i] = cost[j][i];
				mini[j][i] = i;
			}
		}
	}

	fori (i, 1, m) {
		R(t, c);
		gadget[t].pushb(mkp(c, i));
	}

	sort(allof(gadget[1]));
	sort(allof(gadget[2]));

	l = 1;
	r = n;

	while (l <= r) {
		mid = (l+r) / 2;

		if (valid(mid)) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}

	if (l > n) {
		W(-1);
	} else {
		W(l);
		valid(l);

		for (PII u : ans) {
			W(u.fi, mini[u.sd][l]);
		}
	}

	return 0;
}

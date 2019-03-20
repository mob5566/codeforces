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

#define N 1000005

typedef map<int, VI> MIVI;

int n;
int p[N], q[N];
bool vis[N];
MIVI cnt;

int count(int u)
{
	int ret = 1;
	vis[u] = true;

	for (int nxt = p[u]; nxt != u; nxt = p[nxt]) {
		vis[nxt] = true;
		++ret;
	}

	return ret;
}

void walkodd(int u)
{
	VI tmp;
	int pos[N];
	int ucur = u, len;

	do {
		dump(ucur, p[ucur]);
		tmp.pushb(p[ucur]);
		ucur = p[ucur];
	} while (ucur != u);

	len = tmp.size();

	fori (i, 0, len/2) {
		pos[i*2] = tmp[i];
	}

	fori (i, len/2+1, len-1) {
		pos[2*(i-(len+1)/2)+1] = tmp[i];
	}

	fori (i, 0, len-1) {
		q[pos[i]] = pos[(i+1)%len];
	}
}

void walkeven(int u, int v)
{
	int ucur = u, vcur = v;
	int unxt = p[u], vnxt = p[v];

	do {
		q[ucur] = vcur;
		q[vcur] = unxt;

		ucur = unxt, vcur = vnxt;
		unxt = p[ucur], vnxt = p[vcur];
	} while (ucur != u);
}

bool check()
{
	for (auto u : cnt) {
		if (u.fi & 1) {
			for (auto v : u.sd) {
				walkodd(v);
			}
		} else {
			if (u.sd.size()&1) {
				return false;
			} else {
				for (int i = 0; i < u.sd.size(); i += 2) {
					walkeven(u.sd[i], u.sd[i+1]);
				}
			}
		}
	}

	return true;
}

bool checkans()
{
	fori (i, 1, n) {
		if (p[i] != q[q[i]]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	int cc;
	bool space;

	R(n);

	fori (i, 1, n) {
		R(p[i]);
	}

	memset(vis, 0, sizeof(vis));

	fori (i, 1, n) {
		if (vis[i]) {
			continue;
		}

		cc = count(i);

		cnt[cc].pushb(i);
	}

	if (!check()) {
		W(-1);
	} else {
		debug(assert(checkans()));
		space = false;
		fori (i, 1, n) {
			if (space) putchar(' ');
			else space = true;
			printf("%d", q[i]);
		}
		putchar('\n');
	}

	return 0;
}

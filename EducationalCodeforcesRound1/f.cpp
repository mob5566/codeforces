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

#define PI acos(-1.0)
#define EPS 1e-9

/* precision decimal compare by EPS */
const int dcmp( const double &x ) { if( x < -EPS ) return -1; return x > EPS; }

/* return the absolute value of x */
inline const double ABS( const double &x ) { return (dcmp(x)<0?-x:x); }

/* return the square of x */
inline const double sqr( const double &x ) { return x*x; }

struct Point {/*{{{*/
    double x , y;
    Point( double _x = 0, double _y = 0 ): x(_x), y(_y) {}
    const Point operator+( const Point &op ) const { return Point( x+op.x, y+op.y ); }
    const Point operator-( const Point &op ) const { return Point( x-op.x, y-op.y ); }
    const Point operator*( const double &k ) const { return Point( x*k, y*k ); }
    const Point operator/( const double &k ) const { double t=(dcmp(k)?k:1); return Point( x/t, y/t ); }
    const double operator*( const Point &op ) const { return ( x*op.x + y*op.y ); }
    const double operator^( const Point &op ) const { return ( x*op.y - y*op.x ); }
    const bool operator<( const Point &op ) const
		{ return ( 0 < dcmp(op.x-x) || (!dcmp(x-op.x) && 0 < dcmp(op.y-y)) ); }
    const bool operator==( const Point &op ) const { return ( !dcmp(x-op.x)&&!dcmp(y-op.y) ); }
    const bool operator!=( const Point &op ) const { return ( dcmp(x-op.x)||dcmp(y-op.y) ); }
};/*}}}*/

ostream& operator<<(ostream& out, const Point& p)
{
	return out << '(' << p.x << ", " << p.y << ')';
}

struct Line {/*{{{*/
    Point s;
    Point t;
    Line ( Point _s = Point(), Point _t = Point() ): s(_s), t(_t) {}
    // return the polar angle of Line
    const double ang() const { double a = atan2(t.y-s.y,t.x-s.x); return a < 0 ? (a+2*PI) : a; }
    const Point v() const { return t-s; }
};/*}}}*/

typedef vector<Point> Polygon;

/* return the sqrare of distance between a and b */
const double disSqr( const Point &a, const Point &b = Point() ) { return sqr(a.x-b.x)+sqr(a.y-b.y); }

/* return the distance between a and b */
const double dis( const Point &a, const Point &b = Point() ) { return sqrt(disSqr(a,b)); }

/* rotate a line 'a' by ang radians */
const Point rot( const Point &a, const double &ang ) { return Point(a.x*cos(ang)-a.y*sin(ang), a.x*sin(ang)+a.y*cos(ang)); }

/* return point a equal point b or not */
const bool pointEqual( const Point &a, const Point &b ) { return (!dcmp(b.x-a.x) && !dcmp(b.y-a.y)); }

/* return the cross product OA^OB */
const double cross( const Point &o, const Point &a, const Point &b ) { return ((a-o)^(b-o)); }

/******************
 *      Line      *
 ******************/

double intersectionOfTwoLine(const Point &A, const Point &B, const Point &C, const Point &D)
{/*{{{*/
	return ((D-C)^(A-C))/((B-A)^(D-C));
}/*}}}*/

typedef vector< pair<double, int> > VDI;

int intersecPoints(const Polygon &gon, const Point &a, const Point &b, VDI &intPoints)
{
	double intk;
	Point c, d;
	int dirABxAC, dirABxAD;

	intPoints.clear();

	for (int i = 1; i < gon.size(); ++i) {
		c = gon[i-1];
		d = gon[i];

		dirABxAC = dcmp(cross(a, b, c));
		dirABxAD = dcmp(cross(a, b, d));

		if (dirABxAC == dirABxAD) {
			continue;
		}

		intk = intersectionOfTwoLine(a, b, c, d);

		if (dirABxAC > dirABxAD) {
			intPoints.pushb(mkp(intk, dirABxAC && dirABxAD ? 2 : 1));
		} else {
			intPoints.pushb(mkp(intk, dirABxAC && dirABxAD ? -2 : -1));
		}
	}

	return intPoints.size();
}

double commonLine(const Polygon &gon, const Point &a, const Point &b)
{
	VDI intps;
	double cmLineLen = 0;
	int cnt;

	intersecPoints(gon, a, b, intps);
	sort(allof(intps));

	cnt = 0;
	for (int i = 0; i+1 < intps.size(); ++i) {
		assert(i+1 < intps.size());
		cnt += intps[i].sd;
		if (cnt) {
			cmLineLen += intps[i+1].fi - intps[i].fi;
		}
	}

	return cmLineLen * dis(a, b);
}

int n, m;
Polygon gon;

int main(int argc, char *argv[])
{
	double x, y, u, v;
	cout << fixed << setprecision(16);

	R(n, m);

	gon.clear();
	rep (n) {
		R(x, y);

		gon.pushb(Point(x, y));
	}

	gon.pushb(gon[0]);

	rep (m) {
		R(x, y, u, v);

		W(commonLine(gon, Point(x, y), Point(u, v)));
	}

	return 0;
}

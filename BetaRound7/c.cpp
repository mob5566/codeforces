/**
 * Tittle:	C. Line
 * Author:	Cheng-Shih, Wong
 * Date:	2016/08/21
 */

// include files
#include <bits/stdc++.h>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )
#define F first
#define S second
#define PB push_back

typedef long long LL;

// declarations
LL a, b, c;
bool negA, negB;

// functions
void input()
{
	cin >> a >> b >> c;
	negA = negB = false;

	if( a < 0LL ) {
		negA = true;
		a = -a;
	}
	if( b < 0LL ) {
		negB = true;
		b = -b;
	}
}

LL gcd( LL x, LL y, LL &u, LL &v )
{
	if( y == 0LL ) {
		u = v = 1LL;
		return x;
	} else {
		LL t = gcd( y, x%y, u, v );
		LL uu = v;
		v = u-(x/y)*v;
		u = uu;
		return t;
	}
}

void solve()
{
	LL l, m;
	LL d = gcd(a,b,l,m);

	if( (c%d)==0 ) {
		l *= -c/d;
		if( negA ) l *= -1LL;
		m *= -c/d;
		if( negB ) m *= -1LL;

		cout << l << " " << m << endl;
	} else puts("-1");
}

// main function
int main( void )
{
	input();
	solve();
	
	return 0;
}

/**
 * Tittle:	D. Follow Traffic Rules
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/14
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
#define EPS 1e-7

// declarations
double a, v;
double l, d, w;

// functions
inline int dcmp( const double &x )
{
	return (x<-EPS ? -1:(x>EPS));
}

void input()
{
	cin >> a >> v;
	cin >> l >> d >> w;
}

void solve()
{
	double ans, tmp;
	double vp;

	if( w >= v ) {
		tmp = 0.5*v*v/a;
		if( tmp >= l ) ans = sqrt(2*l/a);
		else ans = (v/a) + (l-tmp)/v;
	} else {
		tmp = sqrt(2*a*d);

		if( tmp <= w ) {
			tmp = 0.5*v*v/a;

			if( tmp >= l ) ans = sqrt(2*l/a);
			else ans = (v/a) + (l-tmp)/v;
		} else {
			vp = sqrt( d*a + 0.5*w*w );

			if( vp <= v ) {
				ans = (2*vp-w)/a;
			} else {
				tmp = (0.5/a)*(2*v*v-w*w);
				ans = (d-tmp)/v + v/a + (v-w)/a;
			}

			vp = (v-w)/a;
			tmp = w*vp + 0.5*a*vp*vp;

			if( tmp+d >= l ) {
				ans += (-w + sqrt(w*w - 2*a*(d-l)))/a;
			} else {
				ans += vp + (l-d-tmp)/v;
			}
		}
	}

	printf( "%.8lf\n", ans );
}

// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}

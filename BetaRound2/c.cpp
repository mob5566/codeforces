/**
 * Tittle:	C. Commentator problem
 * Author:	Cheng-Shih, Wong
 * Date:	2016/06/29
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

// declarations
double cx[3], cy[3], cr[3];


// functions
void input()
{
	for( int i=0; i<3; ++i )
		cin >> cx[i] >> cy[i] >> cr[i];
}

inline double dis( double x0, double y0, double x1, double y1 )
{
	return sqrt( (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1) );
}

double eval( double x, double y )
{
	double d0 = dis( x, y, cx[0], cy[0] );
	double d1 = dis( x, y, cx[1], cy[1] );
	double d2 = dis( x, y, cx[2], cy[2] );

	double ret = max( abs(d0/cr[0]-d1/cr[1]), abs(d1/cr[1]-d2/cr[2]) );
	ret = max( ret, abs(d2/cr[2]-d0/cr[0]) );

	return ret;
}

void solve()
{
	double sx = (cx[0]+cx[1]+cx[2])/3.0;
	double sy = (cy[0]+cy[1]+cy[2])/3.0;
	double nx, ny;

	double step = 50.0;
	double minv, tmpv;
	int cnt = 0;

	while( cnt<10000 && (minv=eval(sx, sy))>1e-5 ) {
		// printf( "%.3lf %.3lf %.7lf\n", sx, sy, step );
		// printf( "eval %.6lf\n", minv );
		nx = sx;
		ny = sy;

		if( minv > (tmpv=eval(sx+step,sy)) ) {
			minv = tmpv;
			nx = sx+step;
			ny = sy;
		}
		if( minv > (tmpv=eval(sx,sy+step)) ) {
			minv = tmpv;
			nx = sx;
			ny = sy+step;
		}
		if( minv > (tmpv=eval(sx-step,sy)) ) {
			minv = tmpv;
			nx = sx-step;
			ny = sy;
		}
		if( minv > (tmpv=eval(sx,sy-step)) ) {
			minv = tmpv;
			nx = sx;
			ny = sy-step;
		}

		sx = nx;
		sy = ny;
		++cnt;
		if( step > 1e-5 ) step *= 0.995;
	}

	if( minv<=1e-5 ) printf( "%.5lf %.5lf\n", sx, sy );
}

// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}

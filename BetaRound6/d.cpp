/**
 * Tittle:	D. Lizards and Basements 2
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/25
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
#define INF 1e8

// declarations
int n, a, b;
int h[20];

// functions
void input()
{
	cin >> n >> a >> b;
	FOR( i, 1, n )
		cin >> h[i];
}

int shots[20];
int ans[20], mincnt;

void dfs( int u, int scnt )
{
	int tmp, e;

	if( scnt>=mincnt ) return;

	if( u==n ) {
		FOR( i, 1, n ) 
			if( h[i] >= 0 ) return;

		if( scnt<mincnt ) {
			mincnt = scnt;
			
			FOR( i, 1, n ) 
				ans[i] = shots[i];
		}
	} else {
		if( u==1 ) {
			tmp = h[1]/b+1;
			h[1] -= b*tmp;
			h[2] -= a*tmp;
			h[3] -= b*tmp;
			scnt += tmp;
			shots[2] += tmp;

			dfs( u+1, scnt );

			h[1] += b*tmp;
			h[2] += a*tmp;
			h[3] += b*tmp;
			scnt -= tmp;
			shots[2] -= tmp;
		} else {
			if( h[u]<0 ) tmp = 0;
			else tmp = h[u]/a+1;
			tmp = max( tmp, h[u-1]/b+1 );
			tmp = max( tmp, h[u+1]/b+1 );

			if( h[u-1]<0 ) e = 0;
			else e = h[u-1]/b+1;

			for( int s=tmp; s>=e; --s ) {
				h[u-1] -= b*s;
				h[u] -= a*s;
				h[u+1] -= b*s;
				shots[u] += s;
				scnt += s;

				dfs( u+1, scnt );

				h[u-1] += b*s;
				h[u] += a*s;
				h[u+1] += b*s;
				shots[u] -= s;
				scnt -= s;
			}
		}
	}
}

void solve()
{
	mincnt = INF;
	clr( shots, 0 );
	dfs( 1, 0 );

	bool space = false;
	printf( "%d\n", mincnt );
	FOR( i, 2, n-1 ) {
		FOR( j, 1, ans[i] ) {
			if( space ) putchar(' ');
			else space = true;
			printf( "%d", i );
		}
	}
	putchar('\n');
}

// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}

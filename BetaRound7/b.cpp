/**
 * Tittle:	B. Memory Manager
 * Author:	Cheng-Shih, Wong
 * Date:	2016/08/14
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
int t, m;
int mem[105];
int memcnt;

// functions
void input()
{
	cin >> t >> m;
	clr( mem, 0 );
	memcnt = 0;
}

int checkM( int len )
{
	int cnt = 0;

	FOR( i, 1, m ) {
		if( mem[i]==0 ) {
			++cnt;

			if( cnt==len )
				return i-len+1;
		} else cnt = 0;
	}

	return 0;
}

void solve()
{
	string cmd;
	int n, p, v;

	FOR( ti, 1, t ) {
		cin >> cmd;

		if( cmd=="alloc" ) {
			cin >> n;

			p = checkM( n );

			if( p ) {
				v = ++memcnt;
				FOR( i, p, p+n-1 )
					mem[i] = v;
				printf( "%d\n", v );
			} else puts("NULL");
			
		} else if( cmd=="erase" ) {
			cin >> n;

			bool cleaned = false;

			FOR( i, 1, m ) if( mem[i]==n ) {
				cleaned  = true;
				mem[i] = 0;
			}

			if( !cleaned || n<=0 ) puts("ILLEGAL_ERASE_ARGUMENT");
		} else {
			p = 1;
			int tmpm[105];
			clr( tmpm, 0 );
			FOR( i, 1, m ) if( mem[i] ) {
				tmpm[p++] = mem[i];
			}

			memcpy( mem, tmpm, sizeof(mem) );
		}
	}
}

// main function
int main( void )
{
	input();
	solve();
	
	return 0;
}

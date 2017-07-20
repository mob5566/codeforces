/**
 * Tittle:	B. Before an Exam
 * Author:	Cheng-Shih, Wong
 * Date:	2016/07/04
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
int d, sumTime;
int maxt[35];
int sche[35];
int accTime;

// functions
void input()
{
	cin >> d >> sumTime;
	accTime = 0;
	FOR( i, 1, d ) {
		cin >> sche[i] >> maxt[i];
		accTime += sche[i];
	}
}

void solve()
{
	if( accTime<sumTime ) {
		FOR( i, 1, d ) {
			if( accTime+maxt[i]-sche[i] >= sumTime ) {
				sche[i] += sumTime-accTime;
				accTime = sumTime;
			} else {
				accTime += maxt[i]-sche[i];
				sche[i] = maxt[i];
			}
		}
	}

	if( accTime != sumTime ) puts("NO");
	else {
		puts("YES");
		printf( "%d", sche[1] );
		FOR( i, 2, d ) 
			printf( " %d", sche[i] );
		putchar('\n');
	}
}

// main function
int main( void )
{

	input();
	solve();
	
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t[10][10];

int n;

int solve( int s, int a, int b, int c )
{
	if( s == 1 ) {
		return t[a][c];
	} else {
		return solve( s-1, a, c, b )+solve( 1, a, b, c )+solve( s-1, b, a, c );
	}
}

int main( void )
{
	int i, j, k;

	for( i = 1; i <= 3; ++i ) for( j = 1; j <= 3; ++j ) scanf( "%d", &t[i][j] );
	scanf( "%d", &n );

	for( k = 1; k <= 3; ++k ) for( i = 1; i <= 3; ++i ) for( j = 1; j <= 3; ++j ) {
		t[i][j] = min( t[i][j], t[i][k]+t[k][j] );
	}

	for( i = 1; i <= 3; ++i ) printf( "%d %d %d\n", t[i][1], t[i][2], t[i][3] );

	printf( "%d\n", solve( n, 1, 2, 3 ) );

	return 0;
}



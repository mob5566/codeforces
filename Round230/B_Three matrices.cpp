#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define EPS 1e-5

double a[200][200], b[200][200], c[200][200];
int n;

int main( void )
{
	int i, len, j;

	while( scanf( "%d", &n ) == 1 ) {
		memset( a, 0, sizeof(a) );
		memset( b, 0, sizeof(b) );
		memset( c, 0, sizeof(c) );

		for( i = 1; i <= n; ++i ) for( j = 1; j <= n; ++j ) {
			scanf( "%lf", &c[i][j] );
		}

		for( i = 1; i <= n; ++i ) a[i][i] = c[i][i];

		for( i = 1; i <= n; ++i ) for( j = i+1; j <= n; ++j ) {
			a[i][j] = a[j][i] = (c[i][j]+c[j][i])/2;
			b[i][j] = -(b[j][i] = (c[j][i]-c[i][j])/2);
		}

		for( i = 1; i <= n; ++i ) {
			for( j = 1; j <= n; ++j ) {
				if( j != 1 ) putchar(' ');
				printf( "%lf", a[i][j] );
			}
			putchar('\n');
		}

		for( i = 1; i <= n; ++i ) {
			for( j = 1; j <= n; ++j ) {
				if( j != 1 ) putchar(' ');
				printf( "%lf", b[i][j] );
			}
			putchar('\n');
		}
	}

	return 0;
}


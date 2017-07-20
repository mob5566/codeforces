#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 105


int n;
int arr[N];
int item[N][N];

int main( void )
{
	int i, j, k;
	int ans, tmp;

	while( scanf( "%d", &n ) == 1 ) {
		for( i = 1; i <= n; ++i ) scanf( "%d", &arr[i] );

		ans = 1e9;
		for( i = 1; i <= n; ++i ) {
			tmp = 0;
			for( j = 1; j <= arr[i]; ++j ) {
				scanf( "%d", &k );
				tmp += k;
			}
			ans = min( ans, tmp*5+15*arr[i] );
		}

		printf( "%d\n", ans );
	}

	return 0;
}

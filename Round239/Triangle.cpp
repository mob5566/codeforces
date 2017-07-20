#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int a, b;
int i, j;
double a1, a2;
double b1, b2;

const bool check( void  )
{
	for( i = 1; i < a; ++i ) {
		a1 = i*i; a2 = a*a-i*i;
		if( sqrt(a2) == (int)sqrt(a2) ) {
			for( j = 1; j < b; ++j ) {
				b1 = j*j; b2 = b*b-j*j;
				if( b2 == (int)b2 && (a1/b2) == (a2/b1) ) return true;
			}
		}
	}
	return false;
}

int main( void )
{
	while( scanf( "%d%d", &a, &b ) == 2 ) {
		if( a > b ) swap( a, b );


		if( check() ) {
			puts("YES");
			printf( "0 0\n" );
			printf( "%d %d\n", (int)sqrt(a1), (int)sqrt(a2) );
			printf( "%d %d\n", (int)-sqrt(b1), (int)sqrt(b2) );
		} else
			puts("NO");
	}

	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 1050

char s1[N], s2[N];
int c1[26];
int c2[26];
int l1, l2;

int main( void )
{
	int i;
	int ans;

	while( scanf( "%s%s", s1, s2 ) == 2 ) {
		memset( c1, 0, sizeof(c1) );
		memset( c2, 0, sizeof(c2) );
		l1 = strlen(s1); l2 = strlen(s2);

		for( i = 0; i < l1; ++i ) ++c1[s1[i]-'a'];
		for( i = 0; i < l2; ++i ) ++c2[s2[i]-'a'];

		ans = 0;
		for( i = 0; i <= 25; ++i ) if( ans >= 0 )
			if( !c1[i] && c2[i] ) ans = -1;
			else ans += min( c1[i], c2[i] );


		printf( "%d\n", ans );
	}


	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[150];
int cnt[30];

int main( void )
{
	int i, len;

	while( gets(s) ) {
		len = strlen(s);
		memset( cnt, 0, sizeof(cnt) );
		for( i = 0; i < len; ++i ) {
			++cnt[s[i]-'a'];
		}
		cnt['e'-'a'] /= 3;
		cnt['n'-'a'] = (cnt['n'-'a']-1)/2;

		printf( "%d\n", min( min(cnt['e'-'a'],cnt['n'-'a']), min(cnt['t'-'a'],cnt['i'-'a']) ) );
	}

	return 0;
}

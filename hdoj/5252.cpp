// by poursoul
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define mid ( ( l + r ) >> 1 )

#define root 1 , 1 , n

const int MAXN = 100005 ;

struct Rectangle {
    LL x1 , x2 , y1 , y2 ;
    LL t ;
    void input () {
        LL x , y ;
        scanf ( "%lld %lld %lld" , &x , &y , &t ) ;
        x *= 2 ;
        y *= 2 ;
        t *= 2 ;
        x1 = x + y ;
        x2 = x + y ;
        y1 = y - x ;
        y2 = y - x ;
    }
    bool operator < ( const Rectangle &a ) const {
        return t < a.t ;
    }
    Rectangle get ( LL d ) {
        Rectangle tmp ;
        tmp.x1 = x1 - d ;
        tmp.x2 = x2 + d ;
        tmp.y1 = y1 - d ;
        tmp.y2 = y2 + d ;
        return tmp ;
    }
} ;

Rectangle a[MAXN] ;
int n ;

int check ( LL d ) {
    Rectangle now = a[n] ;
    now = now.get ( d ) ;
    for ( int i = n - 1 ; i >= 1 ; -- i ) {
        int t = a[i + 1].t - a[i].t ;
        now = now.get ( t ) ;
        Rectangle tmp = a[i].get ( d ) ;
        if ( now.x2 < tmp.x1 || tmp.x2 < now.x1 ) return 0 ;
        if ( now.y2 < tmp.y1 || tmp.y2 < now.y1 ) return 0 ;
        now.x1 = max ( now.x1 , tmp.x1 ) ;
        now.x2 = min ( now.x2 , tmp.x2 ) ;
        now.y1 = max ( now.y1 , tmp.y1 ) ;
        now.y2 = min ( now.y2 , tmp.y2 ) ;
    }
    return 1 ;
}

void solve () {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[i].input () ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    LL l = 0 , r = 1e10 ;
    while ( l < r ) {
        LL m = ( l + r ) >> 1 ;
        if ( check ( m ) ) r = m ;
        else l = m + 1 ;
    }
    if ( l % 2 ) printf ( "%lld/2\n" , l ) ;
    else printf ( "%lld/1\n" , l / 2 ) ;
}

int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        printf ( "Case #%d:\n" , i ) ;
        solve () ;
    }
    return 0 ;
}

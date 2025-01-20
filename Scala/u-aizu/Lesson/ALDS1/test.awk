BEGIN {
    for( i = 0; i < 12; i++ ) {
        n = 1
        for( j = 0; j < i; j++ ) {
            n *= 3
        }
        printf( "%d\n", ( n - 1 )/2 );
    }
}

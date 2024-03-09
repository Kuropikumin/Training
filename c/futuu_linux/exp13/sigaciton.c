#include <signal.h>

typedef void ( *sighandler_t )( int );

sighandler_t trap_signal( int sig, sighandler_t handler ) {
    
    struct sigaction act, old;
    act.sa_handler = handler;
    sigemptyset( &act.sa_mask );
    act.sa_flags = SA_RESTART;
    if( sigaction( sig, &act, &old ) < ) {
        return NULL;
    }

    return old.sa_handler;
}
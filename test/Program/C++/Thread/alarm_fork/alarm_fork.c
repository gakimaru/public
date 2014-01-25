/* gcc alarm_fork.c -o alarm_fork -g -W -Wall */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

int main( const int argc, const char * argv[] ) {
	
	struct sigaction sa;
	int   sec = 0;
	int   i = 0;
	char  line[256];
	char  msg[256];
	pid_t pid = 0;
	pid_t mypid = getpid();
	pid_t parentpid = getppid();
printf("[%d->%d] Start Process!\n", parentpid, mypid);
	
	if( argc < 2 ) return( 1 );
	FILE * fp = fopen( argv[1], "w" );
	if( fp == 0 )  {
		return( 1 );
	}
	
	sa.sa_handler = SIG_IGN;
	sigemptyset( &sa.sa_mask );
	sigaction( SIGCHLD, &sa, 0 );
	
	while( 1 ) {
		printf( "[%d->%d] Alarm ( sec msg ) --> \n", parentpid, mypid );
		fgets( line, sizeof( line ), stdin );
		if( strlen( line ) <= 1 ) {
			continue;
		}
		if( memcmp( line, "quit", 4 ) == 0 ) break;
		
		line[strlen( line ) - 1] = '\0';
		if( sscanf( line, "%d %s", &sec, msg ) < 2 ) {
			continue;
		}
		
parentpid = getppid();
mypid = getpid();
printf("[%d->%d] fork() Before\n", parentpid, mypid);
		pid = fork( );
parentpid = getppid();
mypid = getpid();
printf("[%d->%d] fork()=%d After\n", parentpid, mypid, pid);
		if( pid == 0 ) {
			for( i = 0; i < sec; i ++ ) {
				fprintf( fp, "[%d] (%d) %s\n", sec, i, msg );
				fflush( fp );
				sleep( 1 );
			}
			exit( 0 );
		}
	}
	fclose( fp );
	kill( -( getpid( )), SIGINT );
	return 0;
}

// End of file

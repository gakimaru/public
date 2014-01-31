/* gcc alarm_thread.c -o alarm_thread -g -W -Wall -lpthread  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#define BUF_LEN 256
void * alarm_func( void * arg );

typedef struct {
	int    sec;
	FILE * fp;
	char   msg[BUF_LEN];
}   alarm_t;

int main( int argc, char ** argv ) {
	
	alarm_t * alarm;
	pthread_t pt;
	char      line[BUF_LEN];

	if( argc < 2 ) return( 1 );
	FILE * fp = fopen( argv[1], "w" );
	if( fp == 0 ) {
		return( 1 );
	}
	
printf("<Process Start!: %d->%d:%d>\n", getppid(), getpid(), pthread_self());
	while( 1 ) {
		printf( "Alarm ( sec msg ) --> " );
printf("\n");
		fgets( line, sizeof( line ), stdin );
		if( strlen( line ) <= 1 ) {
			continue;
		}
		if( memcmp( line, "quit", 4 ) == 0 ) {
			break;
		}
		alarm = malloc( sizeof( alarm_t ));
		alarm -> fp = fp;
		if( sscanf( line, 
			"%d %s", 
			&alarm -> sec, 
			alarm -> msg ) < 2 ) {
			free( alarm );
			continue;
		}
		pthread_create( &pt, NULL, &alarm_func, alarm );
printf("* thread_id=%d\n", pt);
sleep(1);
printf("* Send SIGCONT -> [%d]\n", pt);
pthread_kill(pt, SIGCONT);
sleep(1);
printf("* Send SIGTRAP -> [%d]\n", pt);
pthread_kill(pt, SIGTRAP);
sleep(1);
printf("* Send SIGCONT -> [%d]\n", pt);
pthread_kill(pt, SIGCONT);
	}
	
	fclose( fp );
printf("<Process End!: %d->%d:%d>\n", getppid(), getpid(), pthread_self());
	return 0;
}

void catch_SIGCONT(int sig) {
	printf(">>> catch_SIGCONT(%d):%d\n", sig, pthread_self());
}
void catch_SIGTRAP(int sig) {
	printf(">>> catch_SIGTRAP(%d):%d\n", sig, pthread_self());
	pause();
}
void * alarm_func( void * arg ) {
	alarm_t * alarm = ( alarm_t * )arg;
	int       cnt;
	
printf("[%s] <Thread Start!: %d->%d:%d>\n", alarm->msg, getppid(), getpid(), pthread_self());
	pthread_detach( pthread_self( ));
printf("[%s] Pause!:%d\n", alarm->msg, pthread_self());
signal(SIGCONT, catch_SIGCONT);
pause();
signal(SIGTRAP, catch_SIGTRAP);
printf("[%s] Resume!:%d\n", alarm->msg, pthread_self());
	for( cnt = 0; cnt < alarm -> sec; cnt ++ ) {
//printf("[%d] loop(%d)\n", pthread_self(), cnt);
		flockfile( alarm -> fp );
		fprintf( alarm -> fp, 
			"[%d] (%d) %s\n", 
			alarm -> sec, cnt, alarm -> msg );
		fflush( alarm -> fp );
		funlockfile( alarm -> fp );
		sleep( 1 );
	}
	free( alarm );
printf("[%s] <Thread End!: %d->%d:%d>\n", alarm->msg, getppid(), getpid(), pthread_self());
	return 0;
}

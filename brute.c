#include <stdio.h>
#define LENGTH 21

int inc( char *, int );

int inc( char *str, int n ) {
        str[n] = str[n] + 1;
        if ( str[n] == 'Z' + 1 ) {
                str[n] = '0';
                if ( n < LENGTH-1 ) {
                        return inc( str, n+1 );
                } else {
                        return 0;
                }
        } else if ( str[n] == '9' + 1 ) {
                str[n] = 'A';
        }
        return 1;
}

int main( int argc, char **argv ) {
  
  char unlock_candidate[LENGTH+1];
  for ( int i = 0; i < LENGTH; ++i ) {
            unlock_candidate[i] = '0';
  }
  unlock_candidate[LENGTH] = '\0';

  while ( inc(unlock_candidate,0) ) {
    printf("fastboot oem unlock %s\n", unlock_candidate);
  }

  return 0;
}

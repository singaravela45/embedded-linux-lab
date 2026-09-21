#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int main() {
	struct timeval tv;
	struct tm* ptm;
	char time_string[40]; 	
	long milliseconds;
	//TODO 1: Populate the timeval structure with gettimeofday
	if(gettimeofday(&tv,NULL)!=0){
		perror("get time of the day failed");
		return 1;
	}
	printf("second:%ld micorsecond : %ld",tv.tv_sec,tv.tv_usec);
	//TODO 2: Use localtime to get struct tm
	ptm=localtime(&tv.tv_sec);
	if (ptm == NULL) {
        perror("localtime failed");
        return 1;
    }
	//TODO 3: Use strftime to get the time in desired format
	strftime(time_string, sizeof(time_string), "\n date : %Y-%m-%d %H:%M:%S", ptm);
	milliseconds = tv.tv_usec / 1000;
    printf("%s.%03ld\n", time_string, milliseconds);	
	return 0;
}

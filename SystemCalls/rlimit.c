#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	struct rlimit r1;
	//TODO 1: Get the current cpu limit with getrlimit
	if(getrlimit(RLIMIT_CPU,&r1)!=0){
		perror("Rlimit falied");
		return 1;
	}
	printf("Current limit is %llu\n",(unsigned long long) r1.rlim_cur);
	//TODO 2: set the current limit to 1 sec with setrlimit
	r1.rlim_cur=15;
	if(setrlimit(RLIMIT_CPU,&r1)!=0){
		perror("SetRlimit failed");
		return 1;
	}
	printf("Current RLIMIT is %llu\n",(unsigned long long)r1.rlim_cur);
	while (1);
	return 0;
}
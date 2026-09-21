#include <stdio.h>
#include <sys/sysinfo.h>
int main() {
    const long minute = 60;
    const long hour = minute * 60;
    const long day = hour * 24;
    const double megabyte = 1024.0 * 1024.0;
    struct sysinfo si;

    // TODO 1: Get the system info using sysinfo system call
    if (sysinfo(&si) != 0) {
        perror("system info fetch failed");
        return 1;
    }
	
    // TODO 2: Print the total uptime
    long uptime = si.uptime;
    long days = uptime / day;
    long hours = (uptime % day) / hour;
    long minutes = (uptime % hour) / minute;
    long seconds = uptime % minute;

    printf("Total uptime: %ld days, %02ld:%02ld:%02ld\n",
           days, hours, minutes, seconds);

    // TODO 3: Print the total RAM in MB
    double total_ram_mb = (si.totalram * (double)si.mem_unit) / megabyte;
    printf("Total RAM in MB: %.2f\n", total_ram_mb);

    // TODO 4: Print the Free RAM in MB
    double free_ram_mb = (si.freeram * (double)si.mem_unit) / megabyte;
    printf("Total Free RAM in MB: %.2f\n", free_ram_mb);

    // TODO 5: Print the process count
    printf("Total number of processes: %hu\n", si.procs);

    return 0;
}
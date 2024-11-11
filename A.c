Q.1) Write a C program to get and set the resource limits such as files, memory associated with a process

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Current file limit: %ld\n", limit.rlim_cur);
    printf("Maximum file limit: %ld\n", limit.rlim_max);

    limit.rlim_cur = 2048;
    setrlimit(RLIMIT_NOFILE, &limit);

    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Updated file limit: %ld\n", limit.rlim_cur);

    getrlimit(RLIMIT_AS, &limit);
    printf("Current memory limit: %ld\n", limit.rlim_cur);
    printf("Maximum memory limit: %ld\n", limit.rlim_max);

    limit.rlim_cur = 512 * 1024 * 1024;
    setrlimit(RLIMIT_AS, &limit);

    getrlimit(RLIMIT_AS, &limit);
    printf("Updated memory limit: %ld\n", limit.rlim_cur);

    return 0;
}

Output:
Current file limit: <current limit>
Maximum file limit: <maximum limit>
Updated file limit: 2048
Current memory limit: <current memory limit>
Maximum memory limit: <maximum memory limit>
Updated memory limit: 536870912
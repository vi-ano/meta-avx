#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdint.h>

#define LEN sizeof(uint64_t)
#define PROC_KPAGECOUNTER "/proc/kpagecount"


int main(void)
{

	signed long long buffer;
	unsigned int pfn = 0;
	
	int fd = open(PROC_KPAGECOUNTER, O_RDONLY);

	if (fd < 0) {
	  perror(PROC_KPAGECOUNTER);
	  exit(EXIT_FAILURE);
	}

	while ( read(fd, &buffer, LEN) == LEN) {
	  if (buffer >=0 )
	    printf("pfn: %i counter:%lld\n",pfn, buffer);
	    pfn++;
	}

	close (fd);
	return 0;
}
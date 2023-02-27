#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 8192

int main()
{	
	int f;
	int rb;
	char buff[10];
	
	f = open("dest.txt", O_RDONLY);
	lseek(f, 5, SEEK_SET);

	if (read(f, &buff, 4) > 0)
		printf("Next 4 from SEEK_SET + 5 offset: %s\n", buff);

	lseek(f, 3, SEEK_CUR);
	if (read(f, &buff, 7) > 0)
		printf("Next 7 from SEEK_CUR + 3 offset: %s\n", buff);

	lseek(f, -12, SEEK_END);
	if (read(f, &buff, 6) > 0)
		printf("Next 6 from SEEK_END -12 offset: %s\n", buff);

	

	return 0;
}

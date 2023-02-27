#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>


int main()
{
	DIR* dr;
	struct dirent* data;
	struct stat st;
	char buff[20];
	
	dr = opendir("/home/alexandru/Desktop/SO");

	while (data = readdir(dr)) {
		stat(data->d_name, &st);
		printf("%s \t %zu \n", data->d_name, st.st_size);
	}

	closedir(dr);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

char* getType(const struct stat sb)
{
	if (S_ISREG(sb.st_mode))
		return "regular file";
	else if (S_ISDIR(sb.st_mode))
		return "directory";
	else if (S_ISCHR(sb.st_mode))
		return "character special";
	else if (S_ISFIFO(sb.st_mode))
		return "FIFO";
	else if (S_ISSOCK(sb.st_mode))
		return "socket";
	else if (S_ISLNK(sb.st_mode))
		return "symbolic link";
	else
		return "unknwon";
}

int main(int argc, char** argv)
{
	DIR* dr;
	struct dirent* entry;
	char* statType;
	

//	dr = opendir(".");
//
//	while ((entry = readdir(dr))) {
//
//			struct stat st;
//
//			if (stat(entry->d_name, &st) == -1) {
//				printf("stat error\n");
//				statType = "unknown";
//				continue;
//			}
//			else
//				statType = getType(st);
//
//			printf("%s \t %o\t %ld \t", entry->d_name, st.st_mode, st.st_size);
//			
//			if ((lstat(entry->d_name, &st)) == -1)
//				printf("lstat error\n");
//			else
//				printf("symlink to ");
//			
//			printf("%s\n", statType);
//
//	}
//
//	closedir(dr);

	struct stat st;
	
	stat("test", &st);
	printf("%o\n", st.st_mode);
	
	chmod("test", st.st_mode | S_IXUSR);

	return 0;
	//sasati urodi
}

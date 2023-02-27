#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>


char src_[1024];
char dest_[1024];
char path[1024];
char pwd[1024];
char cwd[1024];
char root[1024];

char *replace(const char *in, const char *pattern, const char *by)
{
    size_t outsize = strlen(in) + 1;
    char *res = (char*)malloc(outsize);
    // use this to iterate over the output
    size_t resoffset = 0;

    const char *needle;
    while (needle = strstr(in, pattern)) {
        // copy everything up to the pattern
        memcpy(res + resoffset, in, needle - in);
        resoffset += needle - in;

        // skip the pattern in the input-string
        in = needle + strlen(pattern);

        // adjust space for replacement
        outsize = outsize - strlen(pattern) + strlen(by);
        res = (char*)realloc(res, outsize);

        // copy the pattern
        memcpy(res + resoffset, by, strlen(by));
        resoffset += strlen(by);
    }

    // copy the remaining input
    strcpy(res + resoffset, in);

    return res;
}



void traverse(char* src, char* dest)
{
	DIR* dr;
	struct dirent* entry;

	getcwd(cwd, sizeof(cwd));
	printf("\ncwd: %s \n", cwd);

	chdir(src);

	getcwd(cwd, sizeof(cwd));
	printf("\ncwd: %s \n", cwd);

	dr = opendir(".");	// dr = pwd
	
	while(entry = readdir(dr)) {

		struct stat st;
		struct stat st_l;
		
		// failed stat
		if (stat(entry->d_name, &st) == -1) {
			
			printf("Can't stat %s \n", entry->d_name);
			continue;
		}

		// if file is symlink
		lstat(entry->d_name, &st_l);
		if (S_ISLNK(st_l.st_mode))
			continue;

		// ignore . and ..
		if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
			continue;

		// if folder
		if (S_ISDIR(st.st_mode)) {
			//printf("%s \n", entry->d_name);

			char temp[1024];
			char* rep;

			strcpy(temp, cwd);
			strcat(temp, "/");
			strcat(temp, entry->d_name);		
			rep = replace(temp, src_, dest_);
			printf("replaced: %s\n", rep);			// /home/alexandru/Desktop/SO/teme/tema_2/backup/dir

			if (!mkdir(rep, S_IRWXU)){
				printf("%s created successfully\n", rep);

				// dir chmod like entry
				chmod(rep, st.st_mode);
			}
			else	
				printf("%s create failed (!)\n", rep);

			traverse(entry->d_name, dest);

			getcwd(cwd, sizeof(cwd));
			printf("\ncwd: %s \n", cwd);
			chdir("..");
			getcwd(cwd, sizeof(cwd));
			printf("\ncwd: %s \n", cwd);
		}
		// if regular file
		else if (S_ISREG(st.st_mode)) {
			//printf("\t %s \n", entry->d_name);
			
			char temp[1024];
			char* rep;
			char cp[1024];

			// cp /home/alexandru/Desktop/SO/teme/tema_2/folder/f1 /home/alexandru/Desktop/SO/teme/tema_2/backup
			// link(/home/alexandru/Desktop/SO/teme/tema_2/folder/f1, /home/alexandru/Desktop/SO/teme/tema_2/backup/f1)
			
			if (st.st_size > 500){
				// copie

				char oldpath[1024], *newpath;

				strcpy(cp, "cp ");

				strcpy(temp, cwd);
				strcat(temp, "/");
				strcat(temp, entry->d_name);		// /home/alexandru/Desktop/SO/teme/tema_2/folder/f1

				strcpy(oldpath, temp);
				newpath = replace(oldpath, src_, dest_);

				strcat(cp, temp);
				strcat(cp, " ");

				strcpy(temp, cwd);
				rep = replace(temp, src_, dest_);
				strcat(cp, rep);					// /home/alexandru/Desktop/SO/teme/tema_2/backup

				printf("\ncp command: %s\n", cp);

				system(cp);

				// chmod r as parent, w for all
				mode_t mode = st.st_mode;
				mode = mode | S_IWGRP | S_IWOTH | S_IWUSR;
				mode = mode & ~(S_IXGRP) & ~(S_IXOTH) & ~(S_IXUSR);

				printf("newpath: %s\n", newpath);
				chmod(newpath, mode);

				printf("\nmode: %u\n", mode);

				
			}
			else if (st.st_size < 500 && st.st_size > 300) {
				// hardlink

				strcpy(temp, cwd);
				strcat(temp, "/");
				strcat(temp, entry->d_name);		// /home/alexandru/Desktop/SO/teme/tema_2/folder/f1

				rep = replace(temp, src_, dest_);	// /home/alexandru/Desktop/SO/teme/tema_2/backup/f1

				printf("\nold path: %s\n", temp);
				printf("new path: %s\n", rep);

				if(!link(temp, rep)) {
					printf("successfully hardlink-ed\n");

					// hardlink chmod like entry
					chmod(rep, st.st_mode);

				}
				else
					printf("unsuccessfully hardlink-ed (!)\n");
			}
			else {
				// symlink

				strcpy(temp, cwd);
				strcat(temp, "/");
				strcat(temp, entry->d_name);		// /home/alexandru/Desktop/SO/teme/tema_2/folder/f1

				rep = replace(temp, src_, dest_);	// /home/alexandru/Desktop/SO/teme/tema_2/backup/f1

				printf("\nold path: %s\n", temp);
				printf("new path: %s\n", rep);

				if (!symlink(temp, rep)) {
					printf("successfully symlink-ed\n");

					//  symlink chmod like entry
					chmod(rep, st.st_mode);
				}
				else
					printf("unsuccessfully symlink-ed (!)\n");
			}
			
		}
			
		
	}

	closedir(dr);
}


int main(int argc, char** argv)
{
	DIR* dr;
	struct dirent* entry;
	char buffer[1024];
	
    strcpy(src_, argv[1]);
    strcpy(dest_, argv[2]);

	getcwd(root, sizeof(root));
    strcat(root, "/");
    
    printf("root: %s \n\n", root);
    printf("argv[1]: %s\n", src_);
    printf("argv[2]: %s\n\n", dest_);

	printf("src: %s\n", strcat(strcpy(buffer, root), src_));
	printf("dest: %s\n", strcat(strcpy(buffer, root), dest_));

	mkdir(strcat(strcat(strcpy(buffer, root), "/"), dest_), S_IRWXU);	// /home/alexandru/Desktop/SO/teme/tema_2/backup/

	traverse(src_, dest_);
	
	return 0;
}

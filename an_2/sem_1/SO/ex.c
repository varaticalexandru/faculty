#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    DIR* dr;
    struct dirent* entryData;
    
    //dr = opendir(argv[1]);
    dr = opendir("catalog");
    
    while ((entryData = readdir(dr)) {
        printf("%s \t %u\n", entryData->d_name, (int long long)entryData->d_off); 
    }
    
    closedir(dr);

    return 0;
     
}

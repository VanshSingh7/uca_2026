#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat fileStat;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &fileStat) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);

  
    printf("File Type: ");
    if (S_ISREG(fileStat.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(fileStat.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(fileStat.st_mode))
        printf("Block Device\n");
    else if (S_ISFIFO(fileStat.st_mode))
        printf("FIFO (Pipe)\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISSOCK(fileStat.st_mode))
        printf("Socket\n");
    else
        printf("Unknown\n");
  
    printf("Permissions: %04o\n", fileStat.st_mode & 0777);

    printf("File Size: %lld bytes\n",
           (long long)fileStat.st_size);
 
    printf("Hard Links Count: %lu\n",
           (unsigned long)fileStat.st_nlink);
   
    printf("Owner (UID): %u\n", fileStat.st_uid);
    printf("Group (GID): %u\n", fileStat.st_gid);

    printf("Last Access Time: %s", ctime(&fileStat.st_atime));
    printf("Last Modification: %s", ctime(&fileStat.st_mtime));
    printf("Status Change Time: %s", ctime(&fileStat.st_ctime));

    return 0;
}

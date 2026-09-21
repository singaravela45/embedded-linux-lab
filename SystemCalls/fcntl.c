#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char *file;
	int fd;
	struct flock lock;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}
	file = argv[1];
	printf("Opening %s\n", file);
	//TODO: Open the File for read write   
	fd=open(file,O_RDWR | O_CREAT, 0666);
    if (fd == -1){
        perror("open failed");
        return 1;
    }
	printf("\nLocking ... ");
	fflush(stdout);
	//TODO: Zero out the 'lock' and initialize the various fields to lock the 
	//Entire file
	memset(&lock, 0, sizeof(lock));
	// Initialize fields to lock the entire file (write/exclusive lock)
	lock.l_type = F_WRLCK;    // Write lock (exclusive)
    lock.l_whence = SEEK_SET; // Offset relative to the start of the file
    lock.l_start = 0;         // Starting offset
    lock.l_len = 0;           // 0 means lock up to EOF (the entire file)
	//TODO: Invoke fcntl to lock the file
	// Invoke fcntl to lock the file (F_SETLKW waits/blocks if already locked)
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl lock failed");
        close(fd);
        return 1;
    }

    printf("Done. Hit <Enter> to unlock ...\n");
    getchar();
	printf("Unlocking ... ");
    fflush(stdout);
	lock.l_type = F_UNLCK;
    // Invoke fcntl to unlock the file
    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("fcntl unlock failed");
        close(fd);
        return 1;
    }
    printf("Done.\n");
    close(fd);
    return 0;
}
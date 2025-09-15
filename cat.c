#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

char buffer[4096]; // Create a character buffer with size of 4kb

int main(int argc, char *argv[])
{
    register int fileFlag = 0; // Marks whether input comes from a named file, 0, or stdin, 1
    register int fd;
    register int n;
    int retcode=0;
    struct stat statb;

    /* check existence of file descriptor for stdout, 1, and store its metadata in statb */
    if (fstat (1, &statb) < 0) {
		perror ("cat stdout"); // Example output: "cat stdout: Bad file descriptor"
		return 1; // Error
	}

    if(argc < 2) {
        fileFlag = 1; // No input argument, use stdin instead
        argc = 2;
    }
	while (--argc > 0) {
        argv++;
		if (fileFlag || ((*argv)[0] == '-' && (*argv)[1] == '\0')) // if argument is "-", also use stdin
			fd = 0; // set fd to file descriptor for stdin, 0.
		else {
			if ((fd = open (*argv, 0)) < 0) {
				fprintf(stderr, "cat: ");
				perror (*argv); // Example output: "<FILENAME>: No such file or directory" to stderr
				retcode = 1;
				continue;
			}
		}

        if (fstat (fd, &statb) >= 0 && statb.st_dev == dev && statb.st_ino == ino) {
			fprintf (stderr, "cat: input %s is output\n",
			   fileFlag? "-": *argv);
			close (fd);
			retcode = 1;
			continue;
		}
		while ((n = read (fd, buffer, sizeof(buffer))) > 0)
			if (write (1, buffer, n) != n){
				perror ("cat output");
				return 1;
			}
        
		if (fd != 0) // Skip if fd is stdin, 0.
			close (fd);
	}

    return retcode;
}
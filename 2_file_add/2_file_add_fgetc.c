#include <stdio.h>
#include <errno.h>

//Program reads and writes text byte by byte

void usage(char *name)
{
    fprintf(stdout, "Usage:\n"
            "\t%s <file name>\n",
            name);
}


int main(int argc, char *argv[])
{
    FILE *fp;
    char ch = 0;

    if (argc != 2)  {    //If wrong argument is given (no file or more than  
        usage(argv[0]); //one file is specified), usage of a program is displayed
        return 1;
    }

    fp=fopen(argv[1], "a"); //Open or create file for appending to the end of file

    if (!fp) {		 //If file is failed to open/create
        fprintf(stderr, "Error while opening file '%s' (error: %d)\n", argv[1], errno);
        return errno;
    }

    printf("File %s is opened\n", argv[1]); //If file is opened/created succesfully

    while(ch != EOF) {
        ch = (char)fgetc(stdin); //explicit cast int to char
        if (ch == EOF ) {
            if (errno) {  //If EOF is read and if it is an error
                fprintf(stderr, "Error while reading data from stdin (error: %d)\n", errno);
            }
            break; //if EOF is read, repeat cycle
        }
        fprintf(fp,"%c", ch); //If ch is not EOF, print ch to file
    }
    fclose(fp);

    return errno; //If any arror occured, errno is returned   
}

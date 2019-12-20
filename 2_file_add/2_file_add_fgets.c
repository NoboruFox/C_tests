#include <stdio.h>
#include <errno.h>

//Program reads and writes text by strings 9 bytes long

void usage(char *name)
{
    fprintf(stdout, "Usage:\n"
            "\t%s <file name>\n",
            name);
}


int main(int argc, char *argv[])
{
    FILE *fp;
    char buf[10] = {0};

    if (argc != 2) {        //If wrong argument is given (no file or more than
        usage(argv[0]);     //one file is specified), display instruction for usage of a program
        return 1;
    }

    fp=fopen(argv[1], "a"); //Open or create a file for appending to the end of file

    if (!fp) {
        fprintf(stderr, "Error while opening file '%s' (error: %d)\n", argv[1], errno);
        return errno;       //Return error number
    }

    printf("File %s is opened\n", argv[1]);

    while(1) {
        if (fgets(buf, 10, stdin)) { //Read text 9 bytes long from stdin and store it in buf
            fprintf(fp,"%s", buf);   //If fgets returns buf, Write to file from buf
            continue;                //and repeat 
        }

        /* EOF (ctrl+D) or some error */
        if (errno) {
            fprintf(stderr, "Some error occured while reading from stdin (error: %d)\n", errno);
        }
        break;	   //Stop reading
    }
    fclose(fp);    //Close file

    return errno;   
}

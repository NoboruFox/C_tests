#include <stdio.h>
  
int main(int argc, char *argv[])
{
 FILE *fp;
 void filecopy(FILE *, FILE *);
 if (argc == 1) /* нет аргументов; копируется стандартный ввод */
 filecopy(stdin, stdout);
 else
 filecopy(fp, stdout);
return 0;
}
/* filecopy: копирует файл ifp в файл ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
 int c;
 while ((c = getc(ifp)) != EOF)
 putc(c, ofp);
}


#include "libyottadb.h" /* for ydb_* macros/prototypes/typedefs */

#include <stdio.h>      /* for "printf" */
#include <string.h>     /* for "strtok" */
#include <stdlib.h>

int main()
{
         ydb_buffer_t   tmp1, tmp2, line1, i1, FILLIN;
         char           tmp1buff[64], tmp2buff[64], line[64], istr[5];
         int            status, i;
         FILE *pFile;
         YDB_LITERAL_TO_BUFFER("^FILELINES", &FILLIN);
         pFile = fopen("/home/yottadb/random.txt","r");
         if (pFile == NULL) perror ("Error opening file");
         else {
                while(1) {
                         if (fgets(line,150, pFile) == NULL) break;
                         strtok(line, "\n");
                         YDB_STRING_TO_BUFFER(line, &line1);
			 YDB_LITERAL_TO_BUFFER("BLANK", &tmp1);
                         status = ydb_set_s(&FILLIN, 1, &line1, &tmp1);
                         printf("%s\t%s\n", line1.buf_addr,tmp1.buf_addr); 
			 memset(tmp1buff, 0, 64);

                }
         }

}


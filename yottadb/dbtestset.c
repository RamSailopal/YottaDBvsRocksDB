#include "libyottadb.h" /* for ydb_* macros/prototypes/typedefs */

#include <stdio.h>      /* for "printf" */
#include <string.h>     /* for "strtok" */
#include <stdlib.h>

int main()
{
         ydb_buffer_t   RAM, test, testing, tmp1, tmp2, line1, i1, FILLIN;
         char           tmp1buff[64], tmp2buff[64], line[64], istr[5];
         int            status, i;
         FILE *pFile;
         YDB_LITERAL_TO_BUFFER("^FILELINES", &FILLIN);
         ydb_delete_s(&FILLIN, 0, NULL, YDB_DEL_TREE);
         pFile = fopen("/home/yottadb/words.txt","r");
         if (pFile == NULL) perror ("Error opening file");
         else {
                while(1) {
                         if (fgets(line,150, pFile) == NULL) break;
                         i++;
                         sprintf(istr, "%d", i);
                         strtok(line, "\n");
                         YDB_STRING_TO_BUFFER(line, &line1);
                         YDB_STRING_TO_BUFFER(istr, &i1);
                         status = ydb_set_s(&FILLIN, 1, &i1, &line1);
                }
         }
        tmp1.buf_addr = tmp1buff; /* M line : set tmp1="" */
        tmp1.len_used = 0;
        tmp1.len_alloc = sizeof(tmp1buff);
}


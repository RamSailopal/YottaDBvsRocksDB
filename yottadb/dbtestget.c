#include "libyottadb.h" /* for ydb_* macros/prototypes/typedefs */

#include <stdio.h>      /* for "printf" */
#include <string.h>     /* for "strtok" */
#include <stdlib.h>

int main()
{
        ydb_buffer_t    RAM, test, testing, tmp1, tmp2, line1, i1, FILLIN;
        char            tmp1buff[64], tmp2buff[64], line[64], istr[5];
        int             status, i;
        FILE *pFile;
        YDB_LITERAL_TO_BUFFER("^FILELINES", &FILLIN);
        tmp1.buf_addr = tmp1buff; /* M line : set tmp1="" */
        tmp1.len_used = 0;
        tmp1.len_alloc = sizeof(tmp1buff);

        do
        {
                status = ydb_subscript_next_s(&FILLIN, 1, &tmp1, &tmp1);
                if (YDB_ERR_NODEEND == status)
                        break;
                YDB_ASSERT(YDB_OK == status);
                YDB_ASSERT(0 != tmp1.len_used);
                tmp2.buf_addr = tmp2buff;
                tmp2.len_used = 0;
                tmp2.len_alloc = sizeof(tmp2buff);
                status = ydb_get_s(&FILLIN, 1, &tmp1, &tmp2);
                YDB_ASSERT(YDB_OK == status);
                printf("%s\t%s\n", tmp1.buf_addr, tmp2.buf_addr);
                memset(tmp2buff, 0, 64); /* Clear the buffer */
        } while(1);

}


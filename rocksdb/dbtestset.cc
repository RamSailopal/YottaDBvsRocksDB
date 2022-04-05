#include "/usr/include/assert.h"
#include <stdio.h>      /* for "printf" */
#include <string.h>     /* for "strtok" */
#include <iostream>
#include <iostream>
#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"

using ROCKSDB_NAMESPACE::DB;
using ROCKSDB_NAMESPACE::Options;
using ROCKSDB_NAMESPACE::PinnableSlice;
using ROCKSDB_NAMESPACE::ReadOptions;
using ROCKSDB_NAMESPACE::Status;
using ROCKSDB_NAMESPACE::WriteBatch;
using ROCKSDB_NAMESPACE::WriteOptions;


int main()
{
         FILE *pFile;
         int i;
         char line[64], istr[5];
         DB* db;
         Options options;
         options.create_if_missing = true;
         Status s = DB::Open(options, "/tmp/testdb", &db);
         assert(s.ok());
         pFile = fopen("/home/rocksdb/words.txt","r");
         if (pFile == NULL) perror ("Error opening file");
         else {
                while(1) {
                         if (fgets(line,150, pFile) == NULL) break;
                         i++;
                         std::string istr = std::to_string(i);
                         std::string iline;
                         iline = line;
                         iline = iline.substr(0, iline.size() - 1);
                         rocksdb::Status s = db->Put(rocksdb::WriteOptions(), istr, iline);
                }
         }
}


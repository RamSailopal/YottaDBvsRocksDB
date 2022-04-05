#include "/usr/include/assert.h" 
#include <stdio.h>      /* for "printf" */
#include <string.h>     /* for "strtok" */
#include <stdlib.h>
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
         char line[64];
         FILE *pFile;
         DB* db;
         Options options;
         options.create_if_missing = true;
         Status s = DB::Open(options, "/tmp/testdb", &db);
         assert(s.ok());
         std::string value;
         pFile = fopen("/home/rocksdb/random.txt","r");
         if (pFile == NULL) perror ("Error opening file");
         else {
                while(1) {
                         if (fgets(line,150, pFile) == NULL) break;
                         std::string iline;
                         iline = line;
                         iline = iline.substr(0, iline.size() - 1);
                         std::cout << iline << std::endl;
                         rocksdb::Status s = db->Put(rocksdb::WriteOptions(), iline, "BLANK");

                }
         }
         delete db;

}


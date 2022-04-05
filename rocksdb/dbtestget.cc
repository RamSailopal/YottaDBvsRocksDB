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
using ROCKSDB_NAMESPACE::Iterator;
using ROCKSDB_NAMESPACE::WriteOptions;


int main()
{
    DB* db;
    Options options;
    options.create_if_missing = true;
    Status s = DB::Open(options, "/tmp/testdb", &db);
    assert(s.ok());
    Iterator* iterator = db->NewIterator(ReadOptions());
    for (iterator->SeekToFirst(); iterator->Valid(); iterator->Next()) {
       std::string key = iterator->key().ToString();
       std::string value = iterator->value().ToString();
       std::cout << key << ":" << value << std::endl;
    }


}


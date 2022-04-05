# YottaDBvsRocksDB

![Alt text](yottadbvsrocksdb.JPG?raw=true "gitpod View")

A demonstration of the speed of YottaDB against RocksDB

The demonstration performs 4 tests:

**Sequential writes** - Writing 466550 records to each database with sequentials keys. Records are taken from the words.txt file in both the rocksdb and yottadb directories

**Sequentual reads** - Reading the 466550 records back one after the other

**Random writes** - Overwriting 1000 random records from each database. Record numbers are taken from the random.txt file in both the rocksdb and yottadb directories.

**Random reads** - Reading back the same 1000 records.



**NOTE** the RocksDB container has been built for production i.e. with **make shared_lib**, as recommended

https://github.com/facebook/rocksdb/blob/main/INSTALL.md


# Gitpod

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/RamSailopal/YottaDBvsRocksDB)

Once the environment has been provisioned and period of a minute has passed, two results windows will open, one showing the results for YottaDB and one showing the results for RocksDB.


#References

**YottaDB** - https://yottadb.com/

**RocksDB** - http://rocksdb.org/

# YottaDBvsRocksDB

A demonstration of the speed of YottaDB against RocksDB

The demonstration performs 4 tests:

Sequential writes - Writing 466550 records to each database with sequentials keys. Records are taken from the words.txt file in both the rocksdb and yottadb directories

Sequentual reads - Reading the 466550 records back one after the other

Random writes - Overwriting 1000 random records from each database. Record numbers are taken from the random.txt file in both the raocksdb and yottadb directories.

Random reads - Reading back the same 1000 records.


# Gitpod

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/RamSailopal/YottaDBvsRocksDB)

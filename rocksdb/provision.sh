#!/bin/bash
echo -e "RocksDB Performance Stats\n"
echo "Database sequential set test"
time ./dbtestset > results.txt
echo -e "\nDatabase sequential get test"
time ./dbtestget >> results.txt
echo -e "\nDatabase random get test (1000 shots)"
time ./dbtestgetrand >> results.txt
echo -e "\nDatabase random set test (1000 shots)"
time ./dbtestsetrand >> results.txt


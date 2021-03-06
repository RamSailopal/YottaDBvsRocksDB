#!/bin/bash
source `pkg-config --variable=prefix yottadb`/ydb_env_set
echo -e "YottaDB Performance Statistics\n"
echo "Database sequential set test"
time ./dbtestset > results.txt
echo -e "\nDatabase sequential get test"
time ./dbtestget >> results.txt
echo -e "\nDatabase random get test (1000 shots)"
time ./dbtestgetrand >> results.txt
echo -e "\nDatabase random set test (1000 shots)"
time ./dbtestsetrand >> results.txt




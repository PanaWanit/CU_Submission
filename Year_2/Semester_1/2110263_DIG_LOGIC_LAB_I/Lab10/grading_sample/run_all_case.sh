#!/bin/bash
FOLDER=$2
SOL=$1

echo "running" $(ls -1 $FOLDER | wc -l) "cases"
> out.txt
for file in $FOLDER/*.txt; do
    $(echo "${file##*/}" >> out.txt)
    $(sh testprog.sh $SOL $file >> out.txt)
done
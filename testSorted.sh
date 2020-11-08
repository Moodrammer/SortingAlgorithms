#! /bin/bash

pwd
if [ "$#" != 1 ]
then
    op=0
else
    op=$1
fi

N=( 1k 5k 10k 50k 75k 100k 500k )

for i in ${N[*]}
do 
    ./testS "SortedFiles/sorted_data_${op}_${i}.txt"
done
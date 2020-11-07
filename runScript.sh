#! /bin/bash
if [ "$#" = 0 ]
then
    op=0
else
    op=$1
fi

if [ "$#" = 2 ]
then
    sorted=$2
else
    sorted=0
fi

sizes=(1k 5k 10k 50k 75k 100k 500k)

pwd
for i in ${sizes[*]}
do
if [ $sorted = 0 ]
then
    `./output ${op} data/data_${i}.txt SortedFiles/sorted_data_${op}_${i}.txt runningTimes/running_time_${op}_${i}.txt`
else
    `./output ${op} SortedFiles/sorted_data_${op}_${i}.txt sorted_out.txt runningTimes/sorted_running_time_${op}_${i}.txt`
fi
done
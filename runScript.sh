#! /bin/bash
if [ "$#" != 1 ]
then
    op=0
else
    op=$1
fi

sizes=(1k 5k 10k 50k 75k 100k 500k)

pwd
for i in ${sizes[*]}
do
`./output ${op} data/data_${i}.txt SortedFiles/sorted_data_${op}_${i}.txt runningTimes/running_time_${op}_${i}.txt`
done
#! /bin/bash
op=0
sizes=(1k 5k 10k 50k 75k 100k)
echo $x
pwd
for i in ${sizes[*]}
do
`./output ${op} data/data_${i}.txt SortedFiles/sorted_data_${op}_${i}.txt runningTimes/running_time_${op}_${i}.txt`
done
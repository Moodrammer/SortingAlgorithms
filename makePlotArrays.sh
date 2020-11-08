#! /bin/bash

pwd

if [ "$#" != 0 ]
then
    op=$1
else
    op=0
fi

if [ "$#" = 2 ]
then
    sorted=$2
else
    sorted='r'
fi

N=(1k 5k 10k 50k 75k 100k 500k)
rm "running_time.txt"
touch "running_time.txt"

for i in ${N[*]}
do
    if [ $sorted = 'r' ]
    then
        cat "runningTimes/running_time_${op}_${i}.txt" >> "running_time.txt" 
    elif [ $sorted = 's' ]
    then
        cat "runningTimes/sorted_running_time_${op}_${i}.txt" >> "running_time.txt" 
    else
        cat "runningTimes/reverse_running_time_${op}_${i}.txt" >> "running_time.txt"
    fi
done

arr="["
for i in $(cat running_time.txt)
do
    arr="${arr}, ${i}"
done

arr="${arr}]"

arrsize=$((${#arr} - 3))
arr="[${arr:3:arrsize}"
echo $arr

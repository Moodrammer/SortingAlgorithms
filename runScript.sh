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
    sorted='r'
fi

sizes=(1k 5k 10k 50k 75k 100k 500k)

pwd
for i in ${sizes[*]}
do
# if the list is random
if [ $sorted = 'r' ]
then
    ./output ${op} data/data_${i}.txt SortedFiles/sorted_data_${op}_${i}.txt runningTimes/running_time_${op}_${i}.txt
# if the list is sorted in increasing order
elif [ $sorted = 's' ]
then
    ./output ${op} SortedFiles/sorted_data_${op}_${i}.txt sorted_out.txt runningTimes/sorted_running_time_${op}_${i}.txt
elif [ $sorted = 'd' ]
then
    ./output ${op} data/descending_arr_${i}.txt sorted_out.txt runningTimes/reverse_running_time_${op}_${i}.txt
else
    echo "ran on nearly sorted"
    ./output ${op} SortedFiles/nsorted_data_4_${i}.txt SortedFiles/sorted_data_${op}_${i}.txt runningTimes/sorted_running_time_${op}_${i}.txt
fi
done
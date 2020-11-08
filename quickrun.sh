#! /bin/bash

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

./runScript.sh ${op} ${sorted}
./testSorted.sh ${op}
./makePlotArrays.sh ${op} ${sorted}
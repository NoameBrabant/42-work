#!/bin/bash

MAX=0
MIN=42000000
LIMIT=0
SUM=0
ITERATIONS=0
PS=./push_swap
CHECKER=./checker

echo "*** PUSH_SWAP benchmark tester by CHAKU ***"

if [ "$1" -eq "3" ]
	then
	LIMIT=3;
fi
if [ "$1" -eq "5" ]
	then
	LIMIT=12;
fi
if [ "$1" -eq "100" ]
	then
	LIMIT=700;
fi
if [ "$1" -eq "500" ]
	then
	LIMIT=5500;
fi

for i in {1..1000}
do
	export STACK=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
	echo $STACK
	if $PS $STACK | $CHECKER $STACK | grep -q KO
	then
		echo "Error!"
		echo $STACK
		break
	fi
	NUMBER="$($PS $STACK | wc -l | sed 's/ //g')"
	if [ "$NUMBER" -gt "$MAX" ]
		then
		MAX=$NUMBER;
	fi
	if [ "$NUMBER" -lt "$MIN" ]
		then
		MIN=$NUMBER;
	fi
	echo $i ":" $NUMBER
	let SUM+=$NUMBER;
	let ITERATIONS+=1
done

echo "*** Results of the benchmark ***"
echo "$1 elements: ($MIN to $MAX) average: $(($SUM / $ITERATIONS))"

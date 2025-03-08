#!/bin/bash

PUSH_SWAP=./Push_swap
CHECKER=./testers/checker_linux

echo "Going to bench mark your Push_swap :)"

for ((i=0 ; i<100 ; i++)); do

	ARG=$(shuf -i 1-1000 -n 100)

	MOVES=$(PUSH_SWAP ARG | wc -l)
	AVERAGE=$(echo "$AVERAGE + $MOVES * 0.01" | bc)
	RESULT=$($PUSH_SWAP $ARG | $CHECKER $ARG)
	echo "$RESULT"

	if [ "$RESULT" == "KO" ]; then
		echo -e "\033[31mKO :(\033[0m"
		echo ""
		echo $ARG
		echo ""
		break
	fi
done

echo "done benchmarking for stacks of 100"
echo "your benchmark is: $AVERAGE"
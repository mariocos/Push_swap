#!/bin/bash

cp ../Push_swap .

PUSH_SWAP=./Push_swap
CHECKER=./checker_linux
AVERAGE=0

echo "Going to bench mark your Push_swap :)"

for ((i=0 ; i<100 ; i++)); do

	ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')

	MOVES=$($PUSH_SWAP $ARG | wc -l)
	AVERAGE=$(echo "$AVERAGE + $MOVES * 0.01" | bc)
	RESULT=$($PUSH_SWAP $ARG | $CHECKER $ARG)

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

echo ""
echo "benchmark for stacks of 500"
AVERAGE=0
for ((i=0 ; i<10 ; i++)); do

	ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')

	MOVES=$($PUSH_SWAP $ARG | wc -l)
	AVERAGE=$(echo "$AVERAGE + $MOVES * 0.1" | bc)
	RESULT=$($PUSH_SWAP $ARG | $CHECKER $ARG)
	if [ "$RESULT" == "KO" ]; then
		echo -e "\033[31mKO :(\033[0m"
		echo ""
		echo $ARG
		echo ""
		break
	fi
done

echo "done benchmarking for stacks of 500"
echo "your benchmark is: $AVERAGE"

rm -f Push_swap
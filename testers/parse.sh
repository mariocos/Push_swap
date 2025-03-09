#!/bin/bash

cp ../Push_swap .

COUNT=0

PUSH_SWAP=./Push_swap
PUSH_OUTPUT=push.txt
ERROR_FILE=error.txt
DIFF_OUTPUT=diff.txt

commands=(
	"\"\""
    "1 a 2"
	"a 2 3"
	"\"2\" a 3"
	"1 2 345768900234567890323456789"
	"1 \"\" 2"
)

echo "going to test your parsing"
echo ""
echo "Error" > "$ERROR_FILE"

for cmd in "${commands[@]}"
do
    # Run command in minishell
	$PUSH_SWAP $cmd 2> "$PUSH_OUTPUT"

    # Compare outputs
    diff "$PUSH_OUTPUT" "$ERROR_FILE" > "$DIFF_OUTPUT"

    if [ -s "$DIFF_OUTPUT" ]; then
        echo -e "\033[31mKO: \033[0m" "$cmd"
		echo -n "your output: "
		cat "$PUSH_OUTPUT"
		((COUNT++))
	else
		echo -e "\033[32mOK\033[0m"
	fi
done

echo "now checking leaks"

for cmd in "${commands[@]}"
do
    # Run command in minishell
	valgrind --show-leak-kinds=all $PUSH_SWAP $cmd 2> "$PUSH_OUTPUT"

	if grep -q "All heap blocks were freed -- no leaks are possible" "$PUSH_OUTPUT"; then
        echo -e "\033[32mOK\033[0m"
	else
		echo "oh no you got leaks :("
		echo "this comand leaked: $cmd"
		((COUNT++))
	fi
done

rm -f "$PUSH_SWAP" "$PUSH_OUTPUT" "$DIFF_OUTPUT" "$ERROR_FILE"

echo "done testing you got: $COUNT KO's"
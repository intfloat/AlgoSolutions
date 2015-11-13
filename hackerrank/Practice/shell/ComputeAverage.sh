#!/bin/sh

declare -i n
read n
sum=0
for (( i=0; i<$n; i++ ))
do
	read x
	let sum+=x
done
printf "%.3f" `echo "scale = 6; ${sum}/${n}" | bc`


#!/bin/sh

read a
read b
read c
if [ $a -eq $b -a $b -eq $c ]; then
	echo "EQUILATERAL"
elif [ $a -eq $b -o $b -eq $c -o $a -eq $c ]; then
	echo "ISOSCELES"
else
	echo "SCALENE"
fi


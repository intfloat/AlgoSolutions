#!/bin/sh

read a
if [ $a = "y" ]; then
	echo "YES"
elif [ $a = "Y" ]; then
	echo "YES"
else
	echo "NO"
fi

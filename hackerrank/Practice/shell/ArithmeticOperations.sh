#!/bin/sh

read ex
printf "%.3f" `echo "scale = 5; "${ex} | bc`

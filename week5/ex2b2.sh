#!/bin/bash
for i in $(seq 10)
do
	while ! ln ex2b.txt ex2b.txt.lock
	do
		sleep 0.1
	done

	lst=$( tail -n 1 ex2b.txt)	
	echo "$(($lst+1))">>ex2b.txt
done

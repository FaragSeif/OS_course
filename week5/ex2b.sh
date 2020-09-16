#!/bin/bash
for i in $(seq 10)
do
	lockfile -r 0 ex2b.txt.lock || exit 1
	lst=$( tail -n 1 ex2b.txt)	
	echo "$(($lst+1))">>ex2b.txt
	rm -f ex2b.txt.lock
done

for i in $(seq 100)
do
	lst=$( tail -n 1 ex2a.txt)
	echo "$(($lst+1))">>ex2a.txt
done

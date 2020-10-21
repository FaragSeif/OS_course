touch ../week1/file.txt
link ../week1/file.txt _ex2.txt > ex2.txt
ls -i _ex2.txt >> ex2.txt
INUM=$(ls -i _ex2.txt | cut -d ' ' -f 1)
find .. -inum "$INUM" >> ex2.txt
find .. -inum "$INUM" -exec rm {} \; >> ex2.txt

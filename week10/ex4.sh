mkdir tmp
cd tmp
touch file1 file2
link file1 link1
link file2 link2
link file1 link3
cd ..
gcc ex4.c -o ex4
./ex4
rm ex4
cd tmp
rm file1 link1 file2 link2 link3
cd ..
rmdir tmp 

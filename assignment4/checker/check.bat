g++ main.cpp -o main.exe
main.exe<in_1.txt>out_1.txt
main.exe<in_2.txt>out_2.txt
main.exe<in_3.txt>out_3.txt
g++ checker.cpp -o checker.exe
checker.exe
del *.exe
del out_1.txt
del out_2.txt
del out_3.txt
pause

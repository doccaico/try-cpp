@echo off

clang++ -std=c++23 -Wall -o %~n1.exe %1 && %~n1.exe

REM vim: ft=dosbatch fenc=cp932 ff=dos

@echo off

clang++ -std=c++23 -o %~n1.exe %1 && %~n1.exe

REM vim: ft=dosbatch fenc=cp932 ff=dos

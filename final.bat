@echo off
if "%1" == "kompiluj" goto kompiluj
if "%1" == "czysc" goto czysc

:kompiluj
gcc -o MyMath MyMath.c
gcc -o primitive_calc primitive_calc.c
gcc -o program primitive_calc.c MyMath.c
goto :eof

:czysc
del MyMath.exe primitive_calc.exe
goto :eof
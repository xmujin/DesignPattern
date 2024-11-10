:: 
::  the below code is used to build project using cmake.
:: 

@echo off
rem sb
echo build...
set "exeName=DesignPattern.exe"
if not exist build\ md build
cd build
cmake -G "MinGW Makefiles" ..
make
ctest -V
::move "%exeName%" "..\" 

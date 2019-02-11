@echo off
set argC=0
for %%x in (%*) do Set /A argC+=1
cls
echo Number of Parameters=%argC%
if %argC% LEQ 2 ( 
    @echo on
    echo usage e.g getcsv honda city 32 md_automatic
    goto exitnow
)
if exist output.txt del /Q output.txt
if exist %1_%2_%date:/=%.csv goto available
set arg1=%1
set arg2=%2
set arg3=%3
set arg4=%4

echo fetching %3 pages for %1 %2 

if %argC% EQU 3 ( 
    call g1.bat %arg1% %arg2% %arg3% > output.txt
)
if %argC% EQU 4 ( 
    call g1.bat %arg1% %arg2% %arg3% %arg4> output.txt
)
if exist output.csv del output.csv
@echo on
echo generting %1_%2_%date:/=%.csv 
@echo off
@pass1_1.exe > output.csv
ren output.csv %1_%2_%date:/=%.csv
:available
start %1_%2_%date:/=%.csv
start http://almende.github.io/chap-links-library/js/graph3d/playground/
:exitnow

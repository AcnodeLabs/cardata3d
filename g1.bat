cls
set loopcount=%3
set counter=1
set argC=0
for %%x in (%*) do Set /A argC+=1
:loop
@echo on
if %argC% EQU 3 ( 
curl https://www.pakwheels.com/used-cars/search/-/mk_%1/md_%2/?page=%counter%
)
if %argC% EQU 4 ( 
curl https://www.pakwheels.com/used-cars/search/-/mk_%1/md_%2/%4/?page=%counter%
)
@echo off
set /a loopcount=loopcount-1
set counter = loop - counter
set /a counter=counter+1
if %loopcount%==0 goto exitloop
goto loop
:exitloop

 # View Car Market Data in 3D - cardata3d

Requires curl.exe setup in your PATH (if u dont have curl just run getcurl.asadmin.bat in a command prompt with admin previlages)

What it does:
it extracts year, mileage and price data from specified make model from car sales listing sites (e.g pakwheels.com)
and presents the data so that it can be used for 3d graphical analysis

steps before processing:
1/1 just one manual intervention is required : determine how many pages of data are available on the site

to process first 9 pages of honda civic run this command
>getcsv honda civic 9

the 3d plotter webpage will be opened and data would be presented in notepad 

steps after processing:
1/4 copy paste data in the presented website cvs box
2/4 select graph type as dot
3/4 unselect keep aspect ratio
4/4 press Draw Graph button

Here is a sample output
![alt text](https://raw.githubusercontent.com/AcnodeLabs/cardata3d/master/graphpw.PNG)

Current version only grabs data from Pakwheels.com, other sites will be added progressively

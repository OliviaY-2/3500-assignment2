//file to organise the GPS data from the dataBag into a logical form
//To be adjusted for data directly from the server later
#include <iostream>
#include <fstream>


struct GPSdata {
   double northing;
   double easting;
   double height;
   uint32_t CRC;
};

int main () {
   GPSdata data;
   ifstream dataFile (dataBag.txt);
   retun 0;
};

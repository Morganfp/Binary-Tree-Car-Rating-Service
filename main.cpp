// additionally tests the printMake, printModel, and printYear methods
#include <fstream>
#include <iostream>

#include "CarRating.hpp"
#include "CarRatingService.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile;

  cout << "This test assumes that input3.txt exists " 
       << "in the current folder." << endl;

  ifile.open("input3.txt");
  CarRatingService  crs(ifile);
  ifile.close();

  cout << "==== contents of input3.txt ====" << endl;
  cout << crs << endl << endl; 

  cout << "=== the following should be all the Honda makes ===="<< endl;
  crs.printMake("Honda");
  cout << endl;

  cout << "=== the following should be all the Knockoff makes ===="<< endl;
  crs.printMake("Knockoff");
  cout << endl;

  cout << "=== the following should be all the 911 models ===="<< endl;
  crs.printModel("911");
  cout << endl;

  cout << "=== the following should be all the Civic models ===="<< endl;
  crs.printModel("Civic");
  cout << endl;

  cout << "=== the following should be all the 2010 car year ratings  ===="<< endl;
  crs.printYear(2010);
  cout << endl;

  cout << "=== the following should be all the 2001 car year ratings  ===="<< endl;
  crs.printYear(2001);
  cout << endl;

  return 0;
}

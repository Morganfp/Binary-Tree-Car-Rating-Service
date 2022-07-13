// additionally tests the += operator. 
#include <fstream>
#include <iostream>

#include "CarRating.hpp"
#include "CarRatingService.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile;

  if (argc==1)
  {
    ifile.open("input1.txt");
    if (!ifile)
    {
      cerr <<"could not open default input file (input1.txt)" << endl;
      return 1;
    }
  }
  else if (argc==2)
  {
    ifile.open(argv[1]);
    if (!ifile)
    {
      cerr <<"could not open input file (" << argv[1] << ")" << endl;
      return 1;
    }
  }
  else
  {
    cerr << "ERROR - USAGE: " << argv[0] << " <input file name>" << endl;
    return 2; 
  }

  CarRatingService  crs(ifile);

  ifile.close();

  cout << crs; 

  cout << "There were " << crs.numCars() << " cars ratings" << endl;
  
  cout << endl << endl;
  cout << "==== ratings after adding a Mustang (NOT in input1.txt) ====" << endl;
  CarRating stang("Ford", "Mustang", 2020);
  stang+=3;

  crs+=stang;

  cout << crs;

  cout << endl << endl;
  cout << "==== ratings after adding duplicate 2018 Prius (IN input1.txt) ====" << endl;
  CarRating priusDup("Toyota", "Prius", 2018);
  priusDup+=4;

  crs+=priusDup;

  cout << crs; 
  
  return 0;
}

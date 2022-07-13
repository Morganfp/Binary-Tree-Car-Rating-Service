// tests the overloaded << operator and constructor based on an 
// ifstream object. 
#include <fstream>
#include <iostream>

#include "CarRating.hpp"
#include "CarRatingService.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc!=2)
    {
      cerr << "ERROR - USAGE: " << argv[0] << " <input file name>" << endl;
      return 1; 
    }
  
  ifstream ifile(argv[1]);

  CarRatingService  crs(ifile);

  ifile.close();

  cout << crs; 

  cout << "There were " << crs.numCars() << " cars rated" << endl << endl;
  
  cout << "Now clearing the service ...." << endl;
  crs.clear();
  cout << "There are now " << crs.numCars() << " cars rated (should be 0)" << endl;
  cout << "===== So there should be nothing between this line =====" << endl;
  cout << crs; 
  cout << "===== and this line =====" << endl;
 

  return 0;
}

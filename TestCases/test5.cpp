// additionally tests the -= operator
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

  CarRating dummy("Knockoff", "911", 2010);
  crs -= dummy;

  cout << "==== after deleting the 2010 Knockoff 911, you get ====" << endl;
  cout << crs << endl << endl; 

  return 0;
}

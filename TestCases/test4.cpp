// additionally tests the += operator, with another CarRatingService
// as right hand side. 
#include <fstream>
#include <iostream>

#include "CarRating.hpp"
#include "CarRatingService.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile;

  cout << "This test assumes that input1.txt and input2.txt exist " 
       << "in the current folder." << endl;

  ifile.open("input1.txt");
  CarRatingService  crs1(ifile);
  ifile.close();

  ifile.open("input2.txt");
  CarRatingService  crs2(ifile);
  ifile.close();

  cout << "==== contents of input1.txt ====" << endl;
  cout << crs1 << endl << endl; 
  cout << "==== contents of input2.txt ====" << endl;
  cout << crs2 << endl << endl; 

  crs1+=crs2;

  cout << "==== after adding all of input2 to input1, you get ====" << endl;
  cout << crs1 << endl << endl; 

  cout << "==== result of input2 should not have changed from when it was first read ===" << endl;
  cout << crs2 << endl << endl; 

  return 0;
}

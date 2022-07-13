// additionally tests the = operator
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

  CarRatingService copyCat;
  copyCat =crs;

  CarRating expl("Ford", "Explorer", 1997);
  CarRating mini("Chrysler", "Pacifica", 2019);

  crs+=expl;

  cout <<"===the following SHOULD have Ford Explorer in it ===" << endl;
  cout << crs << endl << endl << endl; 

  cout <<"===the following should NOT have Ford Explorer in it ===" << endl;
  cout << copyCat << endl << endl << endl; 

  copyCat+=mini;

  cout <<"===the following should NOT have Chrysler Pacifica in it ===" << endl;
  cout << crs << endl << endl << endl; 

  cout <<"===the following SHOULD have Chrysler Pacifica in it ===" << endl;
  cout << copyCat << endl << endl << endl; 
  return 0;
}

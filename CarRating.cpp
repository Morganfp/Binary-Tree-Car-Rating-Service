/************************************************
 * FILE: CarRating.cpp                          *
 * AUTHOR: Morgan Purcell                       *
 * DATE: 05/01/2022                             *
 * PURPOSE: Implements CarRating class          *
 ************************************************/

#include "CarRating.hpp"

using namespace std;

//method to add a new rating to car
double
CarRating::addNewRating(int rating)
{
  // if the rating is invalid, give a message indicating such and return the current rating
  if (rating<1 || rating>4)
    {
      cerr << "Error: rating value must be 1, 2, 3, or 4 ("
	   << rating << " is invalid)" << endl;
      return _rating;
    }

  //else, edit the cars rating
  _rating = (_numRatings * _rating + rating)/(_numRatings+1);
  _numRatings++;

  //return the rating
  return _rating; 
}

//method to check if a car is the same as another
bool
CarRating::operator==(const CarRating &other) const
{
  //check make, model and year 
  return _year == other._year &&
    _model == other._model &&
    _make == other._make;
}

//method to check if a car is not the same as another
bool
CarRating::operator!=(const CarRating &other) const
{
  //check make, model and year
  return _year != other._year ||
    _model != other._model ||
    _make != other._make;
}

//method to check if a car is less than another based on year, make, and model
bool
CarRating::operator<(const CarRating &other) const
{
  //check year, make, and model
  if (_year < other._year)
    return true;

  else if (_year > other._year)
    return false;

  else if (_make < other._make)
    return true;

  else if (_make > other._make)
    return false;

  else
    return _model < other._model;
}

//method to check if a car is greater than another based on year, make, and model
bool
CarRating::operator>(const CarRating &other) const
{
  //check year, make, and model
  if (_year > other._year)
    return true;

  else if (_year < other._year)
    return false;

  else if (_make > other._make)
    return true;

  else if (_make < other._make)
    return false;

  else
    return _model > other._model;
}

//method to print a car
ostream&
CarRating::print(ostream &os) const
{
  //pass the year, make, model, rating, and number of ratinga to the output stream
  os << _year << " " << _make << " " << _model
     << " " << _rating << " " << _numRatings << "";
  return os;
}

//overloaded << operator using the print method
ostream& operator<< (ostream &os, const CarRating& cr)
{
  return cr.print(os);
}

//overloaded >> operator
istream& operator>> (istream &is, CarRating& cr)
{
  //update the cars year, make, model, rating, or number of ratings using the input stream
  is >> cr._year;
  is >> cr._make;
  is >> cr._model;
  is >> cr._rating;
  is >> cr._numRatings;

  return is;
}

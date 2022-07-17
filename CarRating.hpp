/************************************************
 * FILE: CarRating.hpp                          *
 * AUTHOR: Morgan Purcell                       *
 * DATE: 05/01/2022                             *
 * PURPOSE: Header file for CarRating class     *
 *   This class describes a car and a rating    *
 *   for that car.                              *
 ************************************************/

#ifndef _CAR_RATING_HPP_
#define _CAR_RATING_HPP_

#include <iostream>
#include <string>

//declare the CarRating class
class CarRating
{
private:
  std::string _make;   // the make (ex. Ford, Toyota, etc ...) for the car
  std::string _model;  // the model (ex. Explorer, Camry, etc...) for the car
  int _year;           // the model year for the car (ex. 1990, 2022, ...)
  int _numRatings;     // number of ratings for this car
  double _rating;      // current overall rating for this car

public:
  // default constructor
  CarRating() :
    _make("N/A"), _model("N/A"), _year(-1), _numRatings(0), _rating(0) {}

  // constructor to build a car out of make, model and year
  CarRating(const std::string &make, const std::string &model, int year) :
    _make(make), _model(model), _year(year), _numRatings(0), _rating(0) {}

  // accessor methods 
  const std::string& make() const {return _make;} 
  const std::string& model() const {return _model;}
  int year() const {return _year;}
  int numRatings() const {return _numRatings;}
  double rating() const {return _rating;}

  // mutator methods for the rating and number of ratings
  int& numRatings() {return _numRatings;}
  double& rating() {return _rating;}

  // methods to add a new rating for a car
  double addNewRating(int rating);
  double operator+=(int newRating) {return addNewRating(newRating);}

  // compares two car ratings for equality
  // two ratings are considered equal if they have the same make, model and year
  bool operator==(const CarRating &other) const;
  //overload the != for use in the find method within CarRatingService.cpp
  bool operator!=(const CarRating &other) const; 

  // determines if this CarRating is less than another CarRating. Note
  // that this decision is NOT based on the _rating fieldm but rather
  // on the underlying car's identifying features.
  bool operator<(const CarRating &other) const;
  //overload the > for use in the find method within CarRatingService.cpp
  bool operator>(const CarRating &other) const;
  
  // output a CarRating to the specified stream
  std::ostream& print(std::ostream &os) const;

  // overloaded >> (input) and << (output) operators
  friend std::istream& operator>> (std::istream &is, CarRating& cr);
  friend std::ostream& operator<< (std::ostream &os, const CarRating& cr);
};

#endif

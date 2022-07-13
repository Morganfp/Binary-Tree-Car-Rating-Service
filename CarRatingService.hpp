/************************************************
 * FILE: CarRatingService.hpp                   *
 * AUTHOR: Morgan Purcell                       *
 * DATE: 05/01/2022                             *
 * PURPOSE: Header file for TreeNode class      *
 *       This class dexribes a CarRatingService *           
 ************************************************/

#ifndef _CAR_RATING_SERVICE_HPP_
#define _CAR_RATING_SERVICE_HPP_

//include the necessary libraries
#include "TreeNode.hpp"
#include "CarRating.hpp"
#include <iostream>

//declare the CarRatingService class
class CarRatingService
{
    //declare the private instance variables
    private:
        //pointer to the root of a tree
        TreeNode *_root;
        //number of cars
        int _carCount;

    //declare the public methods
    public:
        //declare a CarRatingService constructor which takes no arguments
        CarRatingService(): _root() {}
        //declare a CarRatingService constructor which takes an argument of type istream
        CarRatingService(std::istream &input);
        
        TreeNode* recursiveInsert(TreeNode *intoSubTree, TreeNode *newNode);
        //declare the overloaded operator+= method
        CarRatingService& operator+=(const CarRating &cr);
        //declare the overloaded operator<< method
        friend std::ostream& operator<<(std::ostream &os, const CarRatingService &bt);

        //methods for adding a car rating service to another
        void addTree(CarRating ratingToInsert);
        void recursiveAddTree(TreeNode *curr);
        CarRatingService& operator+=(const CarRatingService &crs);

        //method for setting one car rating service equal to another
        CarRatingService& operator=(const CarRatingService &crs);

        //methods for removing a CarRatinf
        TreeNode* find(const CarRating &newVal) const;
        TreeNode* remove(const CarRating &val);
        CarRatingService& operator-=(const CarRating &cr);

        //methods for printing cars of a certain make
        void printFindMake(TreeNode *curr, const std::string &newVal);
        void printMake(const std::string &make);
        //methods for printing cars of a certain model
        void printFindModel(TreeNode *curr, const std::string &newVal);
        void printModel( const std::string &model);
        //methods for printing cars of a certain year
        void printFindYear(TreeNode *curr, const int &newVal);
        void printYear(const int &year);

        //traverse and count the cars
        void carCount(TreeNode* curr);
        //method to return the number of car
        int numCars();
        //method to clear the car rating service
        void clear();
};

#endif

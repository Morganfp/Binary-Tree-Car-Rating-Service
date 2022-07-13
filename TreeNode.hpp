/************************************************
 * FILE: TreeNode.hpp                           *
 * AUTHOR: Morgan Purcell                       *
 * DATE: 05/01/2022                             *
 * PURPOSE: Header file for TreeNode class      *
 *       This class describes a TreeNode        *
 *                                              *
 ************************************************/

#ifndef _TRE_NODE_HPP_
#define _TRE_NODE_HPP_

//include the necessary libraries
#include "CarRating.hpp"

//declare the TreeNode class
class TreeNode
{
    //declare the private instance variables
    private:
        //holds a pointer to a nodes data
        CarRating *_data;
        //pointer to the parent of node
        TreeNode *_parent;
        //pointer from the nodes left side
        TreeNode *_left;
        //pointer from the nodes right side
        TreeNode *_right;

    //delcare the public methods
    public:
        //constructor for a TreeNode object which takes a CarRating object
        TreeNode(const CarRating &value): 
            _data(new CarRating(value)), _parent(), _left(),  _right() {};


        //accessor and mutator methods

        const CarRating* data() const {return _data;}
        CarRating* & data()  {return _data;}

        const TreeNode* parent() const {return _parent;}
        TreeNode* & parent()  {return _parent;}

        const TreeNode* left() const {return _left;}
        TreeNode* & left() {return _left;}
  
        const TreeNode* right() const {return _right;}
        TreeNode* & right() {return _right;}

        //method to check if a node is a leaf
        bool isLeaf() const;

        //method to check the depth of a tree
        int depth() const;
};

#endif

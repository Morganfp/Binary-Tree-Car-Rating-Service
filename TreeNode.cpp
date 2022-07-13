/************************************************
 * FILE: TreeNode.cpp                           *
 * AUTHOR: Morgan Purcell                       *
 * DATE: 05/01/2022                             *
 * PURPOSE: Implements TreeNode class           *
 ************************************************/

//include the necessary libraries
#include "TreeNode.hpp"

//define the isLeaf method to check if a node is a leaf
bool
TreeNode::isLeaf() const
{
    return !_left && !_right;
}


//define the  depth method
int
TreeNode::depth() const
{
    //initialize the number of hops to 0
    int numHops=0;
    //initalize a node = to parent
    TreeNode* ancestor = _parent;

    // while ansestor is not the root node 
    while( ancestor!=NULL )
    {
        //increment the number of hops
        numHops++;
        //move to ancestors parent
        ancestor = ancestor->parent();
    }
    //return the number of hops
    return numHops;
}

/************************************************
 * FILE: CarRatingService.cpp                   *
 * AUTHOR: Morgan Purcell                       *
 * DATE: 05/01/2022                             *
 * PURPOSE: Implements CarRatingService class   *
 ************************************************/

#include "CarRatingService.hpp"
#include <fstream>

using namespace std;

//CarRatingService constructor
CarRatingService::CarRatingService(istream &input)
{
    _carCount = 0;
    _root = NULL;

    //declare an onject of type CarRating
    CarRating cr;
    //while there is a cr object in the input file
    while (input >> cr)
    {
        //call the operator+= method to add a CarRating object to the CarRatingService
        this->operator+=(cr);
    }
}

//method to recursively add node's to a tree
TreeNode*
CarRatingService::recursiveInsert(TreeNode *intoSubTree, TreeNode *newNode)
{
    //if subtree is empty
    if (!intoSubTree)
    {
        //return newNode
        return newNode;
    }

    //check if newNode is equal to the first node in the sub tree
    if( *(newNode->data()) == *(intoSubTree->data()) )
    {
        //update the node in the tree
        intoSubTree->data()->operator+=(newNode->data()->rating());
    }

    //check if newNode should be inserted in the left sub tree
    else if ( *(newNode->data()) < *(intoSubTree->data()) )
    {
        //insert newNode into the left subtree and update this node's left pointer
        intoSubTree->left() = recursiveInsert( intoSubTree->left() , newNode );

        //update modified left child's parent
        intoSubTree->left()->parent() = intoSubTree;
    }
    //insert into the right subtree
    else
    {
        //insert newNode into the right subtree and update this node's right pointer
        intoSubTree->right() = recursiveInsert( intoSubTree->right() , newNode );

        // update modified right child's parent
        intoSubTree->right()->parent() = intoSubTree;
    }
     
    return intoSubTree;
}

//overloaded += operator
CarRatingService&
CarRatingService::operator+=(const CarRating &cr)
{
    //insitalize a node to insert using the CarRating data
    TreeNode *nodeToInsert = new TreeNode(cr);
    //call recursiveInsert and pass in the tree's root and the node to insert
    _root = recursiveInsert(_root, nodeToInsert);
    //return the implicit parameter
    return *this;
}


//method to call recursive insert
void
CarRatingService::addTree(CarRating curr)
{
    //create a new tree node using curr
    TreeNode *nodeToAdd = new TreeNode(curr);
    //call recursiveInsert with the root and node to add 
 	_root = recursiveInsert(_root, nodeToAdd);
}

//method to recusively traverse the tree
void
CarRatingService::recursiveAddTree(TreeNode *curr)
{
    //if curr = NULL, return
    if(!curr)
        return;

    //call the addTree method with curr's car rating
    addTree(*(curr->data()));
    //move to curr's left and right children
    recursiveAddTree(curr->left());
    recursiveAddTree(curr->right());
}

//overloaded += operator which takes a CarRatingService object
CarRatingService& 
CarRatingService::operator+=(const CarRatingService &crs)
{
    //initialize a new tree node to the parameters root
    TreeNode *curr = crs._root;
    //call the recursiveAddTree method with the node 
    recursiveAddTree(curr);
    //return the implicit paramter
    return *this;
}

//method to set one car rating service equal to another
CarRatingService&
CarRatingService::operator=(const CarRatingService &crs)
{
    //call the clear method on the car rating service
    clear();
    //call the += operator on both car rating services
    *this += crs;
    //return the car rating service
    return *this;
}


//method to find a car rating
TreeNode*
CarRatingService::find(const CarRating &newVal) const
{
    //initialize a treenode curr to the root
    TreeNode *curr = _root;
    //while curr is not equal to NULL and curr is not the tree node is not equal to the tree node being searched for
    while (curr && *(curr->data()) != newVal)
    {
        //if the tree node is greater than the node being searched for
        if ( *(curr->data())  >  newVal )
        {
            //curr is equal to curr's left
            curr = curr->left();
        }
        //if the tree node is less than the node being searched for
        else if ( *(curr->data())  <  newVal )
        {
            //curr is equal to curr's right
            curr = curr->right();
        }
    }
    //return the treenode
    return curr;
}

//method to find and remove a car rating
TreeNode*
CarRatingService::remove(const CarRating &val)
{
  TreeNode *toDel = find(val);

  //if the car rating is not in the tree
  if (!toDel)
    {
      return NULL;
    }

  //if the car rating is a leaf
  if (toDel->isLeaf())
    {
        //if the car rating is the root
        if (toDel==_root)
        {
            //set the root to NULL
            _root=NULL;
            //return the car rating
            return toDel;
        }
        
        //initalize a treenode pointer to the parent of the car rating to delete
        TreeNode *parent = toDel->parent();
        //if the parent node's left child = the node to delete, set the parent's left to NULL
        if (parent->left() == toDel)
            parent->left()=NULL;
        //if the parent node's right child = the node to delete, set the parent's left to NULL
        else
            parent->right()=NULL;
        //
        toDel->parent()=toDel->left()=toDel->right() = NULL;
        return toDel;
    }

  //if toDel has 1 child
  else if ((toDel->left() && !toDel->right()) || (toDel->left() == NULL && toDel->right()!=NULL))
    {
        //if the node to delete = the root
        if (toDel==_root)
        {
            //check if toDel has a left or right child and set the root to that child
            if (toDel->left())
                _root=toDel->left();
            else
                _root=toDel->right();
            //set the roots parent = NULL
            _root->parent() = NULL;
        }

        else
        {
            //find the subtree to "move up" and  set the subtree to move up = to toDel's left child
            TreeNode *subTreeToMove;
            if (toDel->left())
                subTreeToMove = toDel->left();
            else
                subTreeToMove = toDel->right();

            //initalize a treenode to toDel's parent
            TreeNode *parent = toDel->parent();
            //check if the parents left or right is equal to toDel
            //Set the parents left of right = to the subtree to move
            if (parent->left() == toDel)
                parent->left() = subTreeToMove;
            else
                parent->right() = subTreeToMove;

            //make subtree's parent toDel's parent
            subTreeToMove->parent() = parent; 
        }
        //set the necessary nodes to NULL
        toDel->parent()=toDel->left()=toDel->right() = NULL;
        //return toDel
        return toDel;
    }

        //if the node to delete has two children
        else
    {
      //initialize a treenode which will be the largest node in the left subtree to toDel's left
      TreeNode *largestInLeft=toDel->left();

      //while the largestInLeft node has a right
      while( largestInLeft->right() )
        {
          //move right
          largestInLeft=largestInLeft->right();
        }

      //remove the largest value in left subtree
      remove(*(largestInLeft->data()));

      //update toDel's data
      toDel->data() = largestInLeft->data();

      //set the appropriate nodes = NULL
      largestInLeft->parent()=largestInLeft->left()=largestInLeft->right() = NULL;
      //return the largest node in the left of the tree
      return largestInLeft;
    }

    //should never reach here
    return NULL;
}

//method to remove a car rating
CarRatingService& 
CarRatingService::operator-=(const CarRating &cr)
{
    //call the remove method with the car rating to delete
    remove(cr);
    //return the implicit parameter tree
    return *this;
}


//print method
void print(TreeNode *subTree, ostream &toStream)
{
    //if subtree is empty
    if (!subTree)
        //return and leave the function
        return;
    
    //call the print method with the subTree node's right child
    print(subTree->right() , toStream);

    //for loop to add spacing
    for (int nspaces=0; nspaces < subTree->depth(); nspaces++)
        toStream << "    ";
  
    //pass a pointer to the subTree node's data to the stream
    toStream << *(subTree->data()) << endl;

    //call the print method with the subTree node's left child
    print(subTree->left() , toStream);
}

//overloaded operator<<
ostream& operator<<(ostream &os, const CarRatingService &bt)
{
    //call the print method and pass in the tree's root
    print(bt._root, os);
    //return the output stream
    return os;
}


void 
CarRatingService::carCount(TreeNode* curr)
{
    if (!curr)
        return;
 
    _carCount += 1;
    /* then recur on left subtree */
    carCount(curr->left()); 
    /* now recur on right subtree */
    carCount(curr->right());

    return;    
}

//method to find the number of cars in a car rating service
int
CarRatingService::numCars()
{
    //initalize a TreeNode pointer to the root
    TreeNode *curr = _root;
    //pass the pointer to the carCount function
    carCount(curr);

    //return carCount
    return _carCount;
}

//method to clear a car rating service
void 
CarRatingService::clear()
{
    //set the car count to 0
    _carCount = 0;
    //set the root = NULL
    _root = NULL;
}


//find and print cars of a certain make
void
CarRatingService::printFindMake(TreeNode *curr, const string &newVal)
{
    //if curr = NULL, return
    if(!curr)
        return;
    
    //if the current car ratings' make = the make that is being searched for
    if (curr->data()->make() ==  newVal )
        //print the current car rating
	    cout << *(curr->data()) << endl;
    
    //recursive call to the left child
    printFindMake(curr->left(), newVal);
    //recursive call to the right child
    printFindMake(curr->right(), newVal);

    return;
}
//method to print cars of a certain make
void 
CarRatingService::printMake(const string &make)
{
    //inialize a TreeNode pointer to the root
    //pass it to the function as well as  the value to find
    TreeNode *curr = _root;
    printFindMake(curr, make);
}

//find and print cars of a certain model
void
CarRatingService::printFindModel(TreeNode *curr, const string &newVal)
{
    //if curr = NULL, return 
    if(!curr)
        return;
    
    //if the current car ratings' model = the make that is being searched for
    if (curr->data()->model() ==  newVal )
	{
        //print the car rating
	    cout << *(curr->data()) << endl;
	}
    
    //recursive call to the left child
    printFindModel(curr->left(), newVal);
    //recursive call to the right child
    printFindModel(curr->right(), newVal);
    
    return;
}
//method to print cars of a certain model
void 
CarRatingService::printModel(const string &model)
{
    //inialize a TreeNode pointer to the root
    //pass it to the function as well as  the value to find
    TreeNode *curr = _root;
    printFindModel(curr, model);
}

//find and print cars of a certain year
void
CarRatingService::printFindYear(TreeNode *curr, const int &newVal)
{
    //if curr = NULL, return
    if(!curr)
        return;
    
    //if the current car ratings' year = the make that is being searched for
    if (curr->data()->year() ==  newVal )
	{
        //print the car rating
	    cout << *(curr->data()) << endl;
	}

    //recursive call to the left child    
    printFindYear(curr->left(), newVal);
    //recursive call to the right child
    printFindYear(curr->right(), newVal);
    
    return;
}
//method to print cars of a certain model
void 
CarRatingService::printYear(const int &year)
{
    //inialize a TreeNode pointer to the root
    //pass it to the function as well as  the value to find
    TreeNode *curr = _root;
    printFindYear(curr, year);
}

#ifndef BINAYTREEIMPLEMENTATION_H
#define BINAYTREEIMPLEMENTATION_H
//===================================================================================================================
// Header File Declaration 
//===================================================================================================================
#include<iostream>
using namespace std;
//-------------------------------------------------------------------------------------------------------------------
struct BinaryTreeNodeStructure
{
	struct BinaryTreeNodeStructure * myLeftChild ;
	int myBinaryTreeData;
	struct BinaryTreeNodeStructure *myRightChild;
};

class BinaryTree
{
public :

	BinaryTree();
	~BinaryTree();
	// Create Method to Create New Node Structure 
	struct BinaryTreeNodeStructure * CreateBinaryTreeNodeStructure();
	void InsertElementToBinaryTree(BinaryTreeNodeStructure** , int );
	void DeleteElementFromBinaryTree(BinaryTreeNodeStructure** , int );
	bool SearchElementInBanryTree(BinaryTreeNodeStructure**,int, BinaryTreeNodeStructure ** ,BinaryTreeNodeStructure** , int * );
	void DisplayBinaryTreeElement();
	void BinaryTree_InorderTraversal(struct BinaryTreeNodeStructure *);
	void BinaryTree_PreorderTraversal();
	void BinaryTree_PostorderTraversal();
	void BinaryTreeMenu();
private:
};

//-------------------------------------------------------------------------------------------------------------------

#endif //BINAYTREEIMPLEMENTATION_H
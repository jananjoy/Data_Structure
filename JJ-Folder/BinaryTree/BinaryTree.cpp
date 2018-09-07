//===================================================================================================================
// Header File Declaration 
//===================================================================================================================
#include"BinaryTree.h"
#include<iostream>
using namespace std;
//-------------------------------------------------------------------------------------------------------------------
struct BinaryTreeNodeStructure *BinaryTreeNode_Pointer;
BinaryTree::BinaryTree()
{
	BinaryTreeNode_Pointer = NULL;
}

BinaryTree::~BinaryTree()
{
}
// Create Method to Create New Node Structure 
struct BinaryTreeNodeStructure * BinaryTree ::CreateBinaryTreeNodeStructure()
{
	struct BinaryTreeNodeStructure *TempBinaryTreeNodeStructure ;
	TempBinaryTreeNodeStructure = new BinaryTreeNodeStructure();
	return TempBinaryTreeNodeStructure;
	
}
bool BinaryTree::SearchElementInBanryTree(struct BinaryTreeNodeStructure **RootNodePointer,int aSearchItem , BinaryTreeNodeStructure **Parent ,struct BinaryTreeNodeStructure **aNodePointer, int *aFound )
{
	struct BinaryTreeNodeStructure *TempNodePointer;
	TempNodePointer= *RootNodePointer;
	*aFound = false;
	*Parent = NULL;
	while(TempNodePointer!=NULL)
	{ // Start of the While Loop
     /* if the node to be deleted is found */
     if(TempNodePointer->myBinaryTreeData == aSearchItem)
	 { // Start of the If Loop
	   *aFound = true;
	   *aNodePointer = TempNodePointer;
	   *Parent =TempNodePointer;
	   return true;
	 }// End of the If Loop
	 if(TempNodePointer->myBinaryTreeData>aSearchItem)
	 {
		 *aNodePointer = TempNodePointer;
		 TempNodePointer = TempNodePointer->myLeftChild;
	 }
	 else
	 {
		 *aNodePointer = TempNodePointer;
		 TempNodePointer = TempNodePointer->myRightChild;

	 }

	}// End of the While Loop

	
	return true;

}
 
void BinaryTree::InsertElementToBinaryTree(struct BinaryTreeNodeStructure **TempNodeStructure , int aInsertitem)
{
	if(*TempNodeStructure == NULL)
	{
		// Create a New Node and Insert to the Binary Tree 
			(*TempNodeStructure) = CreateBinaryTreeNodeStructure();
			(*TempNodeStructure)->myLeftChild =NULL;
			(*TempNodeStructure)->myBinaryTreeData = aInsertitem;
			(*TempNodeStructure)->myRightChild= NULL;
	        return ;
	}
	else
	{
		if(aInsertitem< (*TempNodeStructure)->myBinaryTreeData)
		{
			InsertElementToBinaryTree(&(*TempNodeStructure)->myLeftChild,aInsertitem);
		}
		else
		{
			InsertElementToBinaryTree(&(*TempNodeStructure)->myRightChild,aInsertitem);
		}


	}
}
void BinaryTree::DeleteElementFromBinaryTree(struct BinaryTreeNodeStructure **RootNodePointer , int aInsertitem)
{
	int found;
	struct BinaryTreeNodeStructure *parent , *x , *xsucc;
	if(*RootNodePointer == NULL)
	{
		cout<<"\n Binary Tree is Empty"<<endl;
		return;
	}
	parent = x = NULL;
    /*Call to Search function to Find the node  to be deleted*/
//	found = SearchElementInBanryTree();
	/*If Node to be Deleted is not Found */
	bool afound = SearchElementInBanryTree(RootNodePointer , aInsertitem ,&parent ,&x, &found );
	if(found == false  )
	{
		cout<<"Data to be Deleted not Found "<<endl;
		return ;
	}
	/* If the Node to be deleted has two Children */
	if(x->myLeftChild !=NULL && x->myRightChild !=NULL) 
	{ // Start of the If Condition 

		parent = x;
		xsucc = x->myRightChild;
		while(xsucc->myLeftChild !=NULL)
		{//Start of the While Condition 
         parent = xsucc;
		 xsucc = xsucc->myLeftChild;
		}// End of the While Condition
		x->myBinaryTreeData = xsucc->myBinaryTreeData;
		x= xsucc;
	}// End of the If Condition 

	/* If the Node to be deleted has no Children */
	if(x->myLeftChild ==NULL && x->myRightChild ==NULL)
	{// Start of the If Condition 
		if(parent->myRightChild ==x)
		{
			parent->myRightChild =NULL;
		
		}
		else
		{
			parent->myLeftChild =NULL;
		
		}
		free(x);
		return ;


	}// End of the If Condition 
	/* If the Node to be deleted has Only Right Children */
	if(x->myLeftChild ==NULL && x->myRightChild !=NULL)
	{// Start of the If Condition
		if(parent->myLeftChild =x)
		{
			parent->myLeftChild = x->myRightChild ;
		}
		else
		{
          parent->myRightChild = x->myRightChild ;
		
		}
		free(x);
		return ;



	}// End of the If Condition 
	/* If the Node to be deleted has Only Left Children */
	if(x->myLeftChild !=NULL && x->myRightChild ==NULL)
	{// Start of the If Condition
		if(parent->myLeftChild ==x)
		{
			parent->myLeftChild = x->myLeftChild;
		}
		else
		{
			parent->myRightChild = x->myLeftChild;
		
		}
		
	}// End of the If Condition 

}
void BinaryTree::DisplayBinaryTreeElement()
{
}
// Methods To Traverse the Binary Tree
void BinaryTree::BinaryTree_InorderTraversal(struct BinaryTreeNodeStructure *RootNodePointer )
{
	if(RootNodePointer!=NULL)
	{
		BinaryTree_InorderTraversal(RootNodePointer->myLeftChild);
		//Print the Data of the Node Whose Left Child is NULL or the path has already been traversed
        cout<<RootNodePointer->myBinaryTreeData;
		BinaryTree_InorderTraversal(RootNodePointer->myRightChild);
	}
	else
	return;

}
void BinaryTree::BinaryTree_PreorderTraversal()
{
}
void BinaryTree::BinaryTree_PostorderTraversal()
{
}
void BinaryTree::BinaryTreeMenu()
{

	int aUserOption;
	while(1)
	{
	cout<<endl<<"Binary Tree List Menu Display "<<endl;
	cout<<"================================="<<endl;
	cout<<"1.Add New Element to the Binary Tree "<<endl;
	cout<<"2.Delete Element From the Binary Tree "<<endl;
	cout<<"3.Display the Binary Tree "<<endl;
    cout<<"4.Exit from the Application"<<endl;
	cout<<"=================================="<<endl;
	cout<<"Enter Your choice =>";
	cin>>aUserOption;
	switch(aUserOption)
	{
	case 1:
		int InputData;
		cout<<"Enter The Element To The Binary Tree=>";
		cin>>InputData;
 		InsertElementToBinaryTree( &BinaryTreeNode_Pointer,InputData);
			break;
	case 2:
		int DeleteData;
		cout<<"Enter The Element To Be Deleted From The Binary Tree=>";
		cin>>DeleteData;
		DeleteElementFromBinaryTree( &BinaryTreeNode_Pointer,DeleteData);
			break;
	case 3:
		BinaryTree_InorderTraversal(BinaryTreeNode_Pointer);
			break;
	default:
		exit(0);
			break;
	}
	}

}
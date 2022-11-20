


#include <iostream>
#include <string>
#include "fstream"

using namespace std;

class BST
{
private:
	struct TreeNode
	{
		char english; // English character that the
		std::string morse; // Morse Code string represents
		TreeNode* left;
		TreeNode* right;
	};
	TreeNode* root;

	void insert(TreeNode*& nodePtr, TreeNode*& newNode); // inserts the newNode into the nodePtr
	void destroySubTree(TreeNode*nodePtr); // destroys the subtree
	void displayInOrder(TreeNode*nodePtr) const; // prints the English characters in order
public:
    // Constructor
    BST()
    {
        root = NULL;
    }
    BST(bool balance);
    char ar1[39];
    string ar2[39];
    int ind=0;
    BST(char e, std::string m);

    // Destructor
    ~BST(); 

    // Binary tree operations
    void insertNode(char e, std::string m); // inserts the English character and the Morse Code string into the BST
    std::string lookUp(char e) const; // finds the English character in the BST and returns the Morse Code string
	void displayInOrder() const; // prints the English characters in order
    void Array(TreeNode*nodePtr);
    void SortArray();

};
//balancing the BINARY SEARCH TREE
void BST::Array(TreeNode*nodePtr)
{
    if (nodePtr)
    {
        Array(nodePtr->left);
        ar1[ind]= nodePtr->english;
        ar2[ind]= nodePtr->morse;
        ind++;
        Array(nodePtr->right);
    }

}
void BST::SortArray()
{
    int i,j;
    char temp;
    string temp2;
    for(i=0;i<39;i++)
    {
        for(j=i+1;j<39;j++)
        {
            if(ar1[i]>ar1[j])
            {
                temp=ar1[i];
                ar1[i]=ar1[j];
                ar1[j]=temp;
                temp2=ar2[i];
                ar2[i]=ar2[j];
                ar2[j]=temp2;
            }
        }
    }
}

// private
void BST::insert(TreeNode*&nodePtr, TreeNode*&newNode) // inserts the newNode into the nodePtr
{
    if (nodePtr == nullptr)
    {
        nodePtr = newNode; // inserting node
    }
    else if (newNode->english < nodePtr->english)
    {
        insert(nodePtr->left, newNode); // searching left
    }
    else
    {
        insert(nodePtr->right, newNode); // searching right
    }
}

void BST::destroySubTree(TreeNode*nodePtr) // destroys the subtree
{
    if (nodePtr)
    {
        if (nodePtr->left) // if nodePtr->left isn't null
        {
            destroySubTree(nodePtr->left);
        }
        if (nodePtr->right) // if nodePtr->right isn't null
        {
            destroySubTree(nodePtr->right);
        }
        delete nodePtr; // if both are null then delete it
    }
}
void BST::displayInOrder(TreeNode*nodePtr) const // prints the English characters in order
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->english << endl;
        displayInOrder(nodePtr->right);
    }
}

// public
// Constructor
BST::BST(bool balance=false)
{
    char e;
    string m;
    root = nullptr;

    std::ifstream file;
    file.open("MorseTable.txt", std::ios::in);

    if (file.is_open()) // if MorseTable.txt opened fine
    {
        while (file >> e) // read in the english character that is first
        {
            file >> m; // then the string of morse code after it
            insertNode(e, m); // and insert into tree
        }

        file.close();
    }
    else
    {
        cout << "MorseTable.txt failed to open!" << endl;
    }
    if(balance==true)
    {
        Array(root);
        SortArray();
        root=nullptr;
        for(int i=0;i<39;i++)
        {
            insertNode(ar1[i],ar2[i]);
        }
    }
}

BST::BST(char e, std::string m)
{
    root->english = e;
    root->morse = m;
}

// Destructor
BST::~BST()
{
    destroySubTree(root);
}

// Binary tree operations
void BST::insertNode(char e, string m) // inserts the English character and the Morse Code string into the BST
{
    TreeNode* newNode = new TreeNode;	
    // initializing new node
    newNode->english = e;
    newNode->morse = m;
    newNode->left = nullptr;
    newNode->right = nullptr;

    insert(root, newNode);
}

string BST::lookUp(char e) const // finds the English character in the BST and returns the Morse Code string
{
    TreeNode* nodePtr = root;

    while (nodePtr) // while not null
    {
        if (nodePtr->english == e) // if this node's english character matches the one we are searching for
        {
            return nodePtr->morse; // return the morse code that represents that english character
        }
        else if (e < nodePtr->english) // otherwise, go left if it is less than
        {
            nodePtr = nodePtr->left;
        }
        else // or go right if it is more than
        { 
            nodePtr = nodePtr->right;
            }
    }

    return "[NO TRANSLATION]"; // if it is a character not found in our morse code, print out [No translation]
}

void BST::displayInOrder() const // prints the English characters in order
{
    displayInOrder(root); // start at the root
}


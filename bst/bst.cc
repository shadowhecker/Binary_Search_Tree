#include "stdafx.h"
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include "bst.h"

using namespace std;



/***************************
 * EEE2020-03 ASSIGNMENT 4 *
 ***************************/
// Return "true" if the element exists in the tree.
bool bst_t::contain(const element_t m_element) const {
	node_t* cur = root;
	while (cur)
	{
		if (cur->element > m_element)
			cur = cur->left;
		else if (cur->element < m_element)
			cur = cur->right;
		else
			return true;
	}
	return false;
}


// Add a new element to the tree.
void bst_t::insert(const element_t m_element) {
	if (root == NULL)
	{
		root = new node_t(m_element);
		++num_nodes;
	}
	node_t *cur = root;
	node_t *parent = NULL;
	while (cur)
	{
		if (cur->element > m_element)
		{
			parent = cur;
			cur = cur->left;
		}
		else if (cur->element < m_element)
		{
			parent = cur;
			cur = cur->right;
		}
		else
		{
			return;
		}
	}
	if (parent->element > m_element)
	{
		parent->left = new node_t(m_element);
		++num_nodes;
	}
	else
	{
		parent->right = new node_t(m_element);
		++num_nodes;
	}
}

// Remove the element if found in the tree.
void bst_t::remove(const element_t m_element) {
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		if (root->element == m_element)
		{
			delete root;
			root = NULL;
			return;
		}
		else
			return;
	}
	node_t* parent = NULL;
	node_t* cur = root;
	while (cur)
	{
		node_t* del = NULL;
		if (cur->element > m_element)
		{
			parent = cur;
			cur = cur->left;
		}
		else if(cur->element < m_element)
		{
			parent = cur;
			cur = cur->right;
		}
		else
		{
			if (cur->left == NULL)
			{
				if (parent == NULL)
				{
					root = cur->right;
					delete cur;
					cur = NULL;
					--num_nodes;
					return;
				}
				if (parent->element > cur->element)
				{
					del = cur;
					parent->left = cur->right;
					delete del;
					--num_nodes;
					return ;
				}
				else if (parent->element < cur->element)
				{
					del = cur;
					parent->right = cur->right;
					delete del;
					--num_nodes;
					return;
				}
			}
			else if (cur->right == NULL)
			{
				if (parent == NULL)
				{
					root = cur->left;
					delete cur;
					cur = NULL;
					--num_nodes;
					return ;
				}
				if (parent->element > cur->element)
				{
					del = cur;
					parent->left = cur->left;
					delete del;
					--num_nodes;
					return ;
				}
				else if (parent->element < cur->element)
				{
					del = cur;
					parent->right = cur->left;
					delete del;
					--num_nodes;
					return ;
				}
			}
			else
			{
				node_t* del = cur;
				node_t* parent = NULL;
				node_t* RightFirst = cur->right;
				if (RightFirst->left == NULL)
				{
					element_t tmp = RightFirst->element;
					RightFirst->element = cur->element;
					cur->element = tmp;
					del = RightFirst;
					cur->right = RightFirst->right;
					delete del;
					--num_nodes;
					return ;
				}
				//右边第一个节点的左子树不为空  
				while (RightFirst->left)
				{
					parent = RightFirst;
					RightFirst = RightFirst->left;
				}
				element_t tmp = RightFirst->element;
				RightFirst->element = cur->element;
				cur->element = tmp;
				del = RightFirst;
				parent->left = RightFirst->right;
				delete del;
				--num_nodes;
				return ;
			}
		}
	}
}

/**************************************************************************
 If necessary, uncomment and implement the following recursive functions.
 Note that you may have to uncomment the corresponding function definitions
 inside bst_t in bst.h file. 
 **************************************************************************/

/*
// Recursively find if the element exists in the tree.
bool bst_t::contain(const element_t m_element, const node_t *m_node) const {
}
//Recursively add a new element to the tree.
node_t* bst_t::insert(const element_t m_element, node_t *m_node) {		
}
// Recursively remove the element if found in the tree.
node_t* bst_t::remove(const element_t m_element, node_t *m_node) {
	
}
*/


/***********************
 * END OF ASSIGNMENT 4 *
 ***********************/




// Binary search tree constructor
bst_t::bst_t() : 
    num_nodes(0),
    root(NULL) {
}

// Binary search tree destructor
bst_t::~bst_t() {
    clear();
}

// Get the number of elements (or nodes) in the tree.
int bst_t::size() const { return num_nodes; }

// Print the values of all elements in preorder.
void bst_t::print() const { if(root) { print(0, root); } }

// Return the tree height.
int bst_t::height() const { return height(root); }

// Find the minimum element in the tree.
element_t bst_t::find_min() const { if(root) { return find_min(root); } return -1; }

// Find the maximum element in the tree.
element_t bst_t::find_max() const { if(root) { return find_max(root); } return -1; }

// Remove all nodes in the tree.
void bst_t::clear() { if(root) { clear(root); root = NULL; } }

// Recursively print the values of all element in preorder.
void bst_t::print(int m_depth, const node_t *m_node) const {
    for(int d = 0; d < m_depth; d++) { cout << "...."; } cout << m_node->element << endl;
    if(m_node->left)  { print(m_depth+1, m_node->left);  }
    if(m_node->right) { print(m_depth+1, m_node->right); }
}

// Recursively calculate the height of tree.
int bst_t::height(const node_t *m_node) const {
    if(m_node) {
        int left_height  = height(m_node->left);
        int right_height = height(m_node->right);
        int height = left_height > right_height ? left_height : right_height;
        return ++height;
    }
    return -1;
}

// Recursively find the minimum element in the tree.
element_t bst_t::find_min(const node_t *m_node) const {
    if(m_node->left) { return find_min(m_node->left); }
    return m_node->element;
}

// Recursively find the maximum element in the tree.
element_t bst_t::find_max(const node_t *m_node) const {
    if(m_node->right) { return find_max(m_node->right); }
    return m_node->element;
}

// Recursively remove all nodes in the tree.
void bst_t::clear(node_t *m_node) {
    if(m_node->left)  { clear(m_node->left);  }
    if(m_node->right) { clear(m_node->right); }
    delete m_node;
    num_nodes--;
}


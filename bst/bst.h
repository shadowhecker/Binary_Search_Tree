#ifndef __BST_H__
#define __BST_H__

#include "node.h"

// Binary search tree
class bst_t {
public:
    bst_t();            // Binary search tree constructor
    ~bst_t();           // Binary search tree destructor

    // Get the number of nodes in the tree.
    int size() const;
    // Print the values of all nodes in preorder.
    void print() const;
    // Return the tree height.
    int height() const;
    // Find the minimum element in the tree.
    element_t find_min() const;
    // Find the maximum element in the tree.
    element_t find_max() const;
    // Return "true" if the element exists in the tree.
    bool contain(const element_t m_element) const;
    // Add a new element to the tree.
    void insert(const element_t m_element);
    // Remove the element if found in the tree.
    void remove(const element_t m_element);
	node_t * insert(const element_t m_element, node_t * m_node);
	node_t * remove(const element_t m_element, node_t * m_node);
    // Remove all nodes in the tree.
    void clear();

private:
    // Recursively print the values of all element in preorder.
    void print(int m_depth, const node_t *m_node) const;
    // Recursively calculate the height of tree.
    int height(const node_t *m_node) const;
    // Recursively find the minimum element in the tree.
    element_t find_min(const node_t *m_node) const;
    // Recursively find the maximum element in the tree.
    element_t find_max(const node_t *m_node) const;
    // Recursively remove all nodes in the tree.
    void clear(node_t *m_node);

    /*

    // Recursively find if the element exists in the tree.
    bool contain(const element_t m_element, const node_t *m_node) const;
    // Recursively add a new element to the tree.
    node_t* insert(const element_t m_element, node_t *m_node);
    // Recursively remove the element if found in the tree.
    node_t* remove(const element_t m_element, node_t *m_node);

    */

    unsigned num_nodes; // Number of nodes in the tree
    node_t *root;       // Pointer to the root node
};

#endif


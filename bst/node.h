#ifndef __NODE_H__
#define __NODE_H__

#include <stdint.h>

// Binary search tree element is 32-bit unsigned integer type.
typedef uint32_t element_t;

// Binary search tree node
class node_t {
public:
    node_t(const element_t m_element);  // Binary search tree node constructor
    ~node_t();                          // Binary search tree node destructor

    element_t element;                  // Node element
    node_t *left, *right;               // Left, right child pointers
};

#endif


#include "stdafx.h"
#include <cstddef>
#include "node.h"

// Binary search tree node constructor
node_t::node_t(const element_t m_element) :
    element(m_element),
    left(NULL),
    right(NULL) {
}

// Binary search tree node destructor
node_t::~node_t() {
}


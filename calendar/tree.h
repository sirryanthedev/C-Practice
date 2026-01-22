#ifndef TREE_H // include guard 1/2
#define TREE_H

// associate each level of the hierachy to an integer value
typedef enum{ROOT, YEAR, MONTH, DAY, APPOINTMENT} node_type;

// architecture for node
typedef struct node{
    node_type type; // keep track of level in the tree
    void* data; // integer for year||month||day or appointment* ONLY FOR APPOINTMENT NODES
    struct node* first_child; // use this once, then add to siblings
    struct node* siblings; // linked list of siblings
} node;

node* create_node(node_type type, void* data); // arg1: level in tree (e.g. YEAR), arg2: int or * (! ROOT HAS NULL AS DATA)
node* add_child_sorted(node* parent, node* child);

#endif // include guard 2/2
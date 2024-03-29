#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/*--------------- L i n k e d L i s t . h ---------------
PURPOSE
This header file is the interface to the module "LinkedList.cpp."
*/
#include <cassert>
#include "Point.h"
// Make the list data generic.
typedef Point NodeData;
//----- C l a s s L i n k e d L i s t -----
class LinkedList
{
private:
	// List node class definition
	struct Node
	{
		NodeData data; // The "contents" of the node
		Node *next; // Link to the next node
		// Node Constructor Functions
		Node(){}
		Node(const NodeData &theData, Node *const theNext = 0)
			: data(theData), next(theNext) { }
	};
public:
	// Constructor
	LinkedList();
	// True if the list is empty
	bool Empty() const;
	// True if the current position is beyond the last entry.
	bool AtEnd() const;
	// Rewind the current entry to the beginning of the list.
	void Rewind() { current = first; pred = 0; }
	// Skip to the next entry in the list.
	void Skip();
	// Get the contents of the current list entry.
	NodeData CurrentEntry() const;
	// Insert a new list entry before the current entry.
	void Insert(const NodeData &d);
	// Update the current entry.
	void Update(NodeData &d) { assert(!AtEnd()); current->data = d; }
	//Delete the current entry.
	//The new current entry is the successor of the deleted node.
	void Delete();
private:
	Node *first; // Points to the first node in the list
	Node *current; // Points to the current node
	Node *pred; // Points to the node preceding the current entry.
};
#endif
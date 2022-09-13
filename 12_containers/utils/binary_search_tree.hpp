#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

/* EXTERNAL LIBRARIES */
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include "utils.hpp"
#include "pair.hpp"
#include "binary_search_tree_iterator.hpp"

/*
**
** @MACROS
**
*/

#define RED 0
#define BLACK 1

namespace ft {

	/*
	**
	** @NODE STRUCT
	**
	*/

	template < class Key, class T >
	struct Node {

		typedef ft::pair<const Key, T>	value_type;

		value_type	data;
		bool		color;
		Node		*parent;
		Node		*left;
		Node		*right;

		/* Node Constructors */
		Node() : data(), parent(NULL), left(NULL), right(NULL), color(BLACK) {}
		Node(value_type data) : data(data), color(RED), parent(NULL) {}
	};


	/*
	**
	** @REDBLACKTREE CLASS
	**
	*/

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<T> >
	class RedBlackTree {

		/*
		**
		** @Member Types
		**
		*/

		typedef typename Alloc::template rebind<Node<Key, T> >::other	node_allocator;

		public:

			typedef Key																key_type;
			typedef T																mapped_type;
			typedef ft::pair<const Key, T>											value_type;
			typedef Node<Key, T>*													NodePtr;
			typedef Compare															key_compare;
			typedef Alloc															allocator_type;
			typedef size_t															size_type;
			typedef ptrdiff_t														difference_type;
			typedef ft::TreeBidirectionalIterator<value_type, Node<Key, T> >		iterator;
			typedef ft::TreeBidirectionalIterator<const value_type, Node<Key, T> >	const_iterator;
			typedef ft::TreeReverseIterator<value_type, Node<Key, T> >				reverse_iterator;
			typedef ft::TreeReverseIterator<const value_type, Node<Key, T> >		const_reverse_iterator;

		private:

			NodePtr			root;
			NodePtr			TreeNull;
			key_compare		comp;
			allocator_type	alloc;
			node_allocator	nodeAlloc;

		/*
		**
		** @Member Functions
		**
		*/

		public:

			/*
			** @Constructors and destructor
			*/

			/* Default constructor - empty binary search tree */
			RedBlackTree(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type(),
				const node_allocator &nodeAlloc = node_allocator()) :
			comp(comp), alloc(alloc), nodeAlloc(nodeAlloc)
			{
				this->TreeNull = newNode(value_type());
				this->TreeNull->left = NULL;
				this->TreeNull->right = NULL;
				this->TreeNull->parent = NULL;
				this->TreeNull->color = BLACK;
				this->root = this->TreeNull;
			}

			/* Destructor */
			~RedBlackTree() {}

			/*
			** @Modifiers
			*/

			/* Insert a node and then fix the tree */
			NodePtr insert(const value_type &data)
			{
				NodePtr node = newNode(data);

				/* Do a 'standard' BST insert */
				this->root = BSTInsert(this->root, node);

				/* Fix RBT violations */
				FixInsertViolations(node);

				return(node);
			}

			/* Delete a node and then fix the tree */
			void	deleteNode(key_type key)
			{
				NodePtr node = this->root;
				
				/* Loop while node to delete hasn't been found
				or end of the binary search tree hasn't been reached */
				while (node != NULL && node != TreeNull)
				{
					if (key == node->data.first)
					{
						BSTDelete(node);
						break ;
					}
					else if (this->comp(key, node->data.first)) // key < node->data.first
						node = node->left;
					else if (this->comp(node->data.first, key)) // key > node->data.first
						node = node->right;
				}
			}

			/* Exchanges the content of the Tree by the content of x */
			void swap(RedBlackTree &other)
			{
				if (&other == this)
					return ;
				std::swap(this->root, other.root);
				std::swap(this->TreeNull, other.TreeNull);
				std::swap(this->comp, other.comp);
				std::swap(this->alloc, other.alloc);
				std::swap(this->nodeAlloc, other.nodeAlloc);
			}

			/*
			** @Operations
			*/

			/* Search for a node */
			NodePtr search(const key_type &key) const { return BSTSearch(this->root, key); }

			/* Print BST */
			void print()
			{
				if (root)
					printTree(this->root, NULL, false, 0);
			}

			/* Clear binary search tree */
			void clear(NodePtr node)
			{
				if (node != this->TreeNull) {
					clear(node->left);
					clear(node->right);
					simple_delete(node);
				}
			}

			void simple_delete(NodePtr node) {
				if (node->parent)
				{
					if (node == node->parent->left)
						node->parent->left = this->TreeNull;
					else if (node == node->parent->right)
						node->parent->right = this->TreeNull;
				}
				else
					this->root = this->TreeNull;
				this->nodeAlloc.destroy(node);
				this->nodeAlloc.deallocate(node, 1);
			}

			/* Retrieve a tree's root */
			NodePtr	getRoot() const { return this->root; }

			/* Retrieve a tree's null node */
			NodePtr	getTreeNull() const { return this->TreeNull; }

			/* Helper function to find minimun value of a BST */			
			NodePtr	BSTMinVal(NodePtr node) const
			{
				/* Loop until leftmost node is found */
				while (node->left != NULL && node->left != TreeNull)
					node = node->left;

				return (node);
			}

			/* Helper function to find maximum value of a BST */
			NodePtr	BSTMaxVal(NodePtr node) const
			{
				/* Loop until rightmost node is found */
				while (node->right != NULL && node->right != TreeNull)
					node = node->right;

				return (node);
			}

			NodePtr	find_next(NodePtr node) const
			{
				NodePtr	next;

				if (node->right == this->TreeNull)
				{
					next = node;
					while (next->parent != NULL && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = node->right;
					while (next->left != this->TreeNull)
						next = next->left;
				}
				return (next);
			}

			/* Helper function to delete leaf node */
			void	deleteTreeNull()
			{
				this->nodeAlloc.destroy(this->TreeNull);
				this->nodeAlloc.deallocate(this->TreeNull, 1);
			}

		/*
		**
		** @Helper Functions
		**
		*/

		protected:

			/* Helper function to insert new node */
			NodePtr	BSTInsert(NodePtr root, NodePtr node)
			{
				/* Empty tree? Return new node */
				if (root == NULL || root == TreeNull)
					return (node);
				
				/* If not, recursively call BSTInsert */
				if (this->comp(node->data.first, root->data.first))
				{
					root->left = BSTInsert(root->left, node);
					root->left->parent = root;
				}
				else if (this->comp(root->data.first, node->data.first))
				{
					root->right = BSTInsert(root->right, node);
					root->right->parent = root;
				}

				/* Return root (unchanged) */
				return (root);
			}

			/* Helper function to resolve violations after insert */
			void	FixInsertViolations(NodePtr node)
			{
				/*	If node is root, it must be black
					If node is red and node's parent is black, no conflict
					If node is red and if node's uncle is also red, we only need recoloring:
						1. Change color of parent and uncle to BLACK. 
						2. Color of grand parent as RED. 
						3. Call recursively function starting from grandparent node
					Else (if node's uncle is black), rotation is needed */
				if (getParent(node) == NULL || getParent(node) == TreeNull)
					node->color = BLACK;
				else if (getParent(node)->color == BLACK)
					(void)node;
				else if (getUncle(node) != NULL && getUncle(node)->color == RED)
				{
					getParent(node)->color = BLACK;
					getUncle(node)->color = BLACK;
					getGrandParent(node)->color = RED;
					FixInsertViolations(node->parent->parent);
				}
				else
				{
					NodePtr parent = getParent(node);
					NodePtr grandParent = node->parent->parent;

					/* Case 1 - Node is right-child and Parent node is left-child node of grand-parent node */
					if (node == parent->right && parent == grandParent->left)
					{
						rotateLeft(parent);
						node = node->left;
					}
					/* Case 2 - Node is left-child and Parent node if right-child node of grand-parent node */
					else if (node == parent->left && parent == grandParent->right)
					{
						rotateRight(parent);
						node = node->right;
					}
					parent = getParent(node);
					grandParent = node->parent->parent;
					if (node == parent->left)
						rotateRight(grandParent);
					else
						rotateLeft(grandParent);
				
					/* Update parent's color to black and grandparent's to red */
					parent->color = BLACK;
					grandParent->color = RED;
				}
			}

			/* Helper function to delete a node */
			void BSTDelete(NodePtr node)
			{
				NodePtr x, y = NULL;
				NodePtr toDelete = node;

				if (toDelete == NULL || toDelete == TreeNull)
					return ;

				y = toDelete;
				int originalColor = toDelete->color;

				/*	Case 1 - Node has one child (or none)
					Case 2 - Node has two children */
				if (toDelete->left == TreeNull || toDelete->left == NULL)
				{
					x = toDelete->right;
					// right-child of toDelete replaces toDelete
					replaceNode(toDelete, toDelete->right);
				}
				else if (toDelete->right == TreeNull || toDelete->right == NULL)
				{
					x = toDelete->left;
					// left-child of toDelete replaces toDelete
					replaceNode(toDelete, toDelete->left);
				}
				else
				{
					// find successor node (left-most child in the right subtree)
					y = BSTMinVal(toDelete->right);
					originalColor = y->color;
					x = y->right;
					// if succesor node's parent is toDelete
					if (getParent(y) == toDelete)
						x->parent = y;
					else
					{
						replaceNode(y, y->right);
						y->right = toDelete->right;
						y->right->parent = y;
					}
					// y replaces toDelete
					replaceNode(toDelete, y);
					y->left = toDelete->left;
					y->left->parent = y;
					y->color = toDelete->color;
				}
				this->nodeAlloc.destroy(toDelete);
				this->nodeAlloc.deallocate(toDelete, 1);

				/* Fix RBT violations if toDelete node was black */
				if (originalColor == BLACK)
					FixDeleteViolations(x);
			}

			/* Helper function to fix violations after a delete */
			void	FixDeleteViolations(NodePtr x)
			{
				/*	While x is a 'double black' and is not the root, check sibling's color as well as its children's colors
					- If sibling is red, perform rotation and recolor the old sibling and its parent;
					- If sibling is black and both its children are black, perform recoloring;
					- If sibling is black and one of its children is red, perform rotatation(s).
					If x is root, make it single black and return */
				if (x == this->root)
				{
					x->color = BLACK;
					return ;
				}

				NodePtr	sibling;
				while (x != this->root && x->color == BLACK)
				{
					// If x is left-child node
					if (x == x->parent->left)
					{
						sibling = getSibling(x);
						// If sibling is red, perform rotation and recolor the old sibling and its parent.
						if (sibling->color == RED)
						{
							sibling->color = BLACK;
							x->parent->color = RED;
							rotateLeft(x->parent);
							sibling = getSibling(x);
						}
						// If sibling is black and both its children are black,
						// perform recoloring and recur for the parent.
						if (sibling->left->color == BLACK && sibling->right->color == BLACK)
						{
							sibling->color = RED;
							x = x->parent;
						}
						// If sibling is black and one of its children is red, perform rotatation(s)
						else
						{
							// if sibling is right-child and its child on the left is red (but not the one on the right)
							if (sibling->right->color == BLACK)
							{
								// change child's color to black and sibling's color to red
								sibling->left->color = BLACK;
								sibling->color = RED;
								// do a right rotation and update sibling node
								rotateRight(sibling);
								sibling = getSibling(x);
							}
							// if sibling is right-child and its child on the right is red (but not the one on the left)
							sibling->right->color = BLACK;
							sibling->color = x->parent->color;
							x->parent->color = BLACK;
							rotateLeft(x->parent);
							x = this->root;
						}
					}
					// if x is right-child
					else
					{
						sibling = getSibling(x);
						// If sibling is red, perform rotation and recolor the old sibling and its parent.
						if (sibling->color == RED)
						{
							sibling->color = BLACK;
							x->parent->color = RED;
							rotateRight(x->parent);
							sibling = getSibling(x);
						}
						// If sibling is black and both its children are black,
						// perform recoloring and recur for the parent.
						if (sibling->left->color == BLACK && sibling->right->color == BLACK)
						{
							sibling->color = RED;
							x = x->parent;
						}
						// If sibling is black and one of its children is red, perform rotatation(s)
						else
						{
							// if sibling is left-child and its child on the right is red (but not the one on the left)
							if (sibling->left->color == BLACK)
							{
								// change child's color to black and sibling's color to red
								sibling->right->color = BLACK;
								sibling->color = RED;
								// do a right rotation and update sibling node
								rotateLeft(sibling);
								sibling = getSibling(x);
							}
							// if sibling is left-child and its child on the left is red (but not the one on the right)
							sibling->left->color = BLACK;
							sibling->color = x->parent->color;
							x->parent->color = BLACK;
							rotateRight(x->parent);
							x = this->root;
						}
					}
				}
				x->color = BLACK;
			}

			/* Helper function to search recursively through the BST */
			NodePtr	BSTSearch(NodePtr node, const key_type &key) const
			{
				if (node == TreeNull || key == node->data.first)
					return (node);
				else
				{
					if (this->comp(key, node->data.first))
						return (BSTSearch(node->left, key));
					else
						return (BSTSearch(node->right, key));
				}
			}

			/* Helper functions to replace a node by another one */
			void replaceNode(NodePtr toReplace, NodePtr replacor)
			{
				// If toReplace is the root note, replacor becomes root
				if (toReplace->parent == NULL || toReplace->parent == TreeNull)
					root = replacor;
				// If toReplace is left-child, parent of toReplace now points to replacor instead of toReplace
				else if (toReplace == getParent(toReplace)->left)
					getParent(toReplace)->left = replacor;
				// If toReplace is right-child, parent of toReplace now points to replacor instead of toReplace
				else
					getParent(toReplace)->right = replacor;

				// Update parent of replacor to point to parent of toReplace
				replacor->parent = toReplace->parent;
			}

			/* Helper function to rotate left */
			void	rotateLeft(NodePtr pt)
			{
				// Pointer to x (node that was just inserted)
				NodePtr	x = pt->right;

				// Make pt point to T2 (instead of pointing to x)
				pt->right = x->left; 

				// Update parent of T2 (instead of pointing to x, it points to pt)
				// if (x->left != NULL && x->left != TreeNull)
				if (x->left != TreeNull)
					x->left->parent = pt;
				
				// Make sure x's parent is pt's parent
				x->parent = getParent(pt);

				// If pt was the root node, then root is now x
				// If pt was not root, then root now points to x instead of pt
				if (getParent(pt) == NULL || getParent(pt) == TreeNull)
					this->root = x;
				else
				{
					if (pt == getParent(pt)->left)
						getParent(pt)->left = x;
					else
						getParent(pt)->right = x;
				}

				// Finally, make x point to pt & update parent of pt to x
				x->left = pt;
				pt->parent = x;
			}

			/* Helper function to rotate right */
			void	rotateRight(NodePtr pt)
			{
				// Pointer to x (parent of node that was just inserted)
				NodePtr	x = pt->left;

				// Make pt point to T3 (instead of pointing to x)
				pt->left = x->right; 

				// Update parent of T3 (instead of pointing to x, it points to pt)
				// if (x->right != NULL && x->right != TreeNull)
				if (x->right != TreeNull)
					x->right->parent = pt;
				
				// Make sure x's parent is pt's parent
				x->parent = getParent(pt);

				// If pt was the root node, then root is now x
				// If pt was not root, then root now points to x instead of pt
				if (getParent(pt) == NULL || getParent(pt) == TreeNull)
					this->root = x;
				else
				{
					if (pt == getParent(pt)->right)
						getParent(pt)->right = x;
					else
						getParent(pt)->left = x;
				}

				// Finally, make x point to pt & update parent of pt to x
				x->right = pt;
				pt->parent = x;
			}

			/* Helper function to retrieve the grand-parent node */
			NodePtr	getGrandParent(NodePtr node)
			{
				return (getParent(getParent(node)));
			}

			/* Helper function to retrieve the parent node */
			NodePtr	getParent(NodePtr node)
			{
				if (node == NULL)
					return (NULL);
				else
					return (node->parent);
			}

			/* Helper function to retrieve a node' sibling */
			NodePtr getSibling(NodePtr node)
			{
				NodePtr parent = getParent(node);

				if (!parent)
					return (NULL);
				if (parent->left == node)
					return (parent->right);
				return (parent->left);	
			}

			/* Helper function to retrieve a node's uncle */
			NodePtr getUncle(NodePtr node)
			{
				NodePtr parent = getParent(node);

				return (getSibling(parent));
			}

			/* Helper function to allocate memory for a node */
			NodePtr newNode(value_type val)
			{
				NodePtr	node = this->nodeAlloc.allocate(1);
				this->nodeAlloc.construct(node, val);
				node->left = this->TreeNull;
				node->right = this->TreeNull;
				node->parent = NULL;
				node->color = RED;
				return (node);
			}

			/* Debugging functions to print BST. Credit to mdeclerf */
			struct Trunk
			{
				Trunk *prev;
				std::string str;

				Trunk(Trunk *prev, std::string str)
				{
					this->prev = prev;
					this->str = str;
				}
			};

			void showTrunks(Trunk *p)
			{
				if (p == NULL) {
					return;
				}

				showTrunks(p->prev);
				std::cout << p->str;
			}

			void printTree(NodePtr root, Trunk *prev, bool isLeft, bool type)
			{
				if (root == NULL) {
					return;
				}

				std::string prev_str = "    ";
				Trunk *trunk = new Trunk(prev, prev_str);

				printTree(root->right, trunk, true, type);

				if (!prev) {
					trunk->str = "———";
				}
				else if (isLeft)
				{
					trunk->str = "/———";
					prev_str = "   |";
				}
				else {
					trunk->str = "\\———";
					prev->str = prev_str;
				}

				showTrunks(trunk);
				std::cout << " " << root->data.first << "(" << root->color << "): " << root->data.second << std::endl;
				if (prev) {
					prev->str = prev_str;
				}
				trunk->str = "   |";

				printTree(root->left, trunk, false, type);
			}
	};
} // namespace

#endif

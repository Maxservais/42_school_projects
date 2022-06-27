#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP

#include "binary_search_tree.hpp"
#include "utils.hpp"
#include <iostream>

namespace ft {

	/*
	**
	** Prototypes
	**
	*/

	template < class T , class Node >
	class TreeBidirectionalIterator;

	template < class T , class Node >
	class TreeReverseIterator;

	/*
	**
	** Bidirectional Iterator
	**
	*/

	template < class T , class Node >
	class TreeBidirectionalIterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:

			typedef Node*																				NodePtr;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type				value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category			iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer					pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference					reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type			difference_type;
			typedef size_t																				size_type;
	
		public:

			NodePtr	_ptr;
			NodePtr	_root;
			NodePtr	_treeNull;

		public:

			/* Default constructor
			----------------------------------------------------------------------------- */
			TreeBidirectionalIterator() : _ptr(NULL), _root(NULL), _treeNull(NULL) {}

			/* Parameterized constructor
			----------------------------------------------------------------------------- */
			TreeBidirectionalIterator(NodePtr node, NodePtr root, NodePtr treeNull) : _ptr(node), _root(root), _treeNull(treeNull) {}

			/* Copy constructor
			----------------------------------------------------------------------------- */
			TreeBidirectionalIterator(const TreeBidirectionalIterator &src) : _ptr(src._ptr), _root(src._root), _treeNull(src._treeNull) {}

			/* Default destructor
			----------------------------------------------------------------------------- */
			~TreeBidirectionalIterator() {}

			/* Dummy constructor
			----------------------------------------------------------------------------- */
			TreeBidirectionalIterator(const TreeReverseIterator<value_type, Node>& it, int dummy) : _ptr(it._ptr), _root(it._root), _treeNull(it._treeNull)
			{
				(void)dummy;
			}

			/* Cast operator (https://docs.microsoft.com/en-us/cpp/cpp/cast-operator-parens?view=msvc-170)
			----------------------------------------------------------------------------- */
			operator	TreeBidirectionalIterator<value_type const, Node>() const
			{
				return (TreeBidirectionalIterator<value_type const, Node>(this->_ptr, this->_root, this->_treeNull));
			}

			/* Assignment operator
			----------------------------------------------------------------------------- */
			TreeBidirectionalIterator &operator=(const TreeBidirectionalIterator &rhs)
			{
				if (this != &rhs)
				{
					this->_ptr = rhs._ptr;
					this->_root = rhs._root;
					this->_treeNull = rhs._treeNull;
				}
				return (*this);
			}

			/* Dereference operator
			----------------------------------------------------------------------------- */
			reference	operator*() const
			{
				return (this->_ptr->data);
			}

			pointer	operator->() const
			{
				return &(operator*());
			}

			/* Pre and postfix Increment operators (++)
			----------------------------------------------------------------------------- */
			TreeBidirectionalIterator &operator++()
			{
				/*	If node is the last one, iterator is treeNull
					Else, find next node
				*/
				if (this->_ptr == this->_treeNull)
					this->_ptr = BSTMinVal(this->_root);
				else if (this->_ptr == BSTMaxVal(this->_root))
					this->_ptr = this->_treeNull;
				else
					this->_ptr = find_next(this->_ptr);
				return (*this);
			}

			TreeBidirectionalIterator operator++(int)
			{
				TreeBidirectionalIterator<value_type, Node> tmp(*this);
				this->operator++();
				return (tmp);
			}

			/* Pre and postfix Decrement operators (--)
			----------------------------------------------------------------------------- */
			TreeBidirectionalIterator &operator--()
			{
				/*	If node is past the last node
					Else, find previous node
					Note: when trying to decrement iterator pointing to first node, it will segfault
				*/
				if (this->_ptr == this->_treeNull)
					this->_ptr = BSTMaxVal(this->_root);
				else
					this->_ptr = find_prev(this->_ptr);
				return (*this);
			}

			TreeBidirectionalIterator operator--(int)
			{
				TreeBidirectionalIterator<value_type, Node> tmp(*this);
				this->operator--();
				return (tmp);
			}

			/* Equality and non-equality operators
			----------------------------------------------------------------------------- */
			bool	operator==(const TreeBidirectionalIterator rhs) const
			{
				return (this->_ptr == rhs._ptr);
			}

			bool	operator!=(const TreeBidirectionalIterator rhs) const
			{
				return (this->_ptr != rhs._ptr);
			}

		private:

			/* Helper functions
			----------------------------------------------------------------------------- */
			NodePtr	find_next(NodePtr node) const
			{
				NodePtr	next;

				if (node->right == this->_treeNull)
				{
					next = node;
					while (next->parent != NULL && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = node->right;
					while (next->left != this->_treeNull)
						next = next->left;
				}
				return (next);
			}

			NodePtr	find_prev(NodePtr node) const
			{
				NodePtr	prev;

				if (node->left == NULL || node->left == this->_treeNull)
				{
					prev = node;
					while (prev->parent != NULL && prev == prev->parent->left)
						prev = prev->parent;
					prev = prev->parent;
				}
				else
				{
					prev = node->left;
					while (prev->right != this->_treeNull)
						prev = prev->right;
				}
				return (prev);
			}

			NodePtr	BSTMinVal(NodePtr node) const
			{
				/* Loop until leftmost node is found */
				while (node->left != NULL && node->left != this->_treeNull)
					node = node->left;

				return (node);
			}

			NodePtr	BSTMaxVal(NodePtr node) const
			{
				if (node == this->_treeNull)
					return (node);

				/* Loop until rightmost node is found */
				while (node->right != NULL && node->right != this->_treeNull)
					node = node->right;

				return (node);
			}
	};

	/*
	**
	** Reverse Iterator
	**
	*/

	template < class T , class Node >
	class TreeReverseIterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:

			typedef Node*																				NodePtr;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type				value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category			iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer					pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference					reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type			difference_type;
			typedef size_t																				size_type;
			typedef TreeBidirectionalIterator<T, Node>													iterator_type;
	
		public:

			NodePtr	_ptr;
			NodePtr	_root;
			NodePtr	_treeNull;

		public:

			/* Default constructor
			----------------------------------------------------------------------------- */
			TreeReverseIterator() : _ptr(NULL), _root(NULL), _treeNull(NULL) {}

			/* Parameterized constructor
			----------------------------------------------------------------------------- */
			TreeReverseIterator(NodePtr node, NodePtr root, NodePtr treeNull) : _ptr(node), _root(root), _treeNull(treeNull) {}

			/* Copy constructor
			----------------------------------------------------------------------------- */
			TreeReverseIterator(const TreeReverseIterator &src) : _ptr(src._ptr), _root(src._root), _treeNull(src._treeNull) {}

			template <class v, class n>
			TreeReverseIterator(const TreeBidirectionalIterator<v, n> &src)
			{
				this->_ptr = src._ptr;
				this->_root = src._root;
				this->_treeNull = src._treeNull;
				if (this->_ptr == BSTMinVal(this->_root))
					this->_ptr = this->_treeNull;
			}

			/* Default Destructor
			----------------------------------------------------------------------------- */
			~TreeReverseIterator() {}

			/* Cast operator (https://docs.microsoft.com/en-us/cpp/cpp/cast-operator-parens?view=msvc-170)
			----------------------------------------------------------------------------- */
			operator	TreeReverseIterator<value_type const, Node>() const
			{
				return (TreeReverseIterator<value_type const, Node>(this->_ptr, this->_root, this->_treeNull));
			}

			/* Assignment operator
			----------------------------------------------------------------------------- */
			TreeReverseIterator &operator=(const TreeReverseIterator &rhs)
			{
				if (this != &rhs)
				{
					this->_ptr = rhs._ptr;
					this->_root = rhs._root;
					this->_treeNull = rhs._treeNull;
				}
				return (*this);
			}

			/* Base()
			----------------------------------------------------------------------------- */
			iterator_type	base() const
			{
				TreeBidirectionalIterator<T, Node> tmp(*this, 0);
				tmp++;
				return (tmp);
			}

			/* Dereference operator
			----------------------------------------------------------------------------- */
			reference	operator*() const
			{
				return (this->_ptr->data);
			}

			pointer	operator->() const
			{
				return &(operator*());
			}

			/* Pre and postfix Increment operators (++)
			----------------------------------------------------------------------------- */
			TreeReverseIterator &operator++()
			{
				/*	If node is the last one, iterator is treeNull
					Else, find next node */
				if (this->_ptr == this->_treeNull || this->_ptr == BSTMinVal(this->_root))
					this->_ptr = this->_treeNull;
				else
					this->_ptr = find_prev(this->_ptr);
				return (*this);
			}

			TreeReverseIterator operator++(int)
			{
				TreeReverseIterator<value_type, Node> tmp(*this);
				this->operator++();
				return (tmp);
			}

			/* Pre and postfix Decrement operators (--)
			----------------------------------------------------------------------------- */
			TreeReverseIterator &operator--()
			{
				/*	If node is past the last node
					Else, find previous node
					Note: when trying to decrement iterator pointing to first node, it will segfault */
				if (this->_ptr == this->_treeNull)
					this->_ptr = BSTMinVal(this->_root);
				else
					this->_ptr = find_next(this->_ptr);
				return (*this);
			}

			TreeReverseIterator operator--(int)
			{
				TreeReverseIterator<value_type, Node> tmp(*this);
				this->operator--();
				return (tmp);
				
			}

			/* Equality and non-equality operators
			----------------------------------------------------------------------------- */
			bool	operator==(const TreeReverseIterator rhs) const
			{
				return (this->_ptr == rhs._ptr);
			}

			bool	operator!=(const TreeReverseIterator rhs) const
			{
				return (this->_ptr != rhs._ptr);
			}

		private:

			/* Helper functions
			----------------------------------------------------------------------------- */
			NodePtr	find_next(NodePtr node) const
			{
				NodePtr	next;

				if (node->right == this->_treeNull)
				{
					next = node;
					while (next->parent != NULL && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = node->right;
					while (next->left != this->_treeNull)
						next = next->left;
				}
				return (next);
			}

			NodePtr	find_prev(NodePtr node) const
			{
				NodePtr	prev;

				if (node->left == this->_treeNull || node->left == NULL)
				{
					prev = node;
					while (prev->parent != NULL && prev == prev->parent->left)
						prev = prev->parent;
					prev = prev->parent;
				}
				else
				{
					prev = node->left;
					while (prev->right != this->_treeNull)
						prev = prev->right;
				}
				return (prev);
			}

			NodePtr	BSTMinVal(NodePtr node) const
			{
				/* Loop until leftmost node is found */
				while (node->left != NULL && node->left != this->_treeNull)
					node = node->left;

				return (node);
			}

			NodePtr	BSTMaxVal(NodePtr node) const
			{
				/* Loop until rightmost node is found */
				while (node->right != NULL && node->right != this->_treeNull)
					node = node->right;

				return (node);
			}
	};
} // namespace

#endif

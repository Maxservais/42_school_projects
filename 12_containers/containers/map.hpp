#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include "../utils/binary_search_tree.hpp"
#include "../utils/binary_search_tree_iterator.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map {

		/*
		**
		** @Member Types
		**
		*/

		public:
			typedef Key																	key_type;
			typedef T																	mapped_type;
			typedef pair<const key_type, mapped_type>									value_type;
			typedef Compare																key_compare;
			typedef Alloc																allocator_type;
			typedef value_type&															reference;
			typedef const value_type&													const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef RedBlackTree<key_type, mapped_type, key_compare, allocator_type>	tree;
			typedef typename tree::NodePtr												NodePtr;
			typedef typename tree::iterator												iterator;
			typedef typename tree::const_iterator										const_iterator;
			typedef typename tree::reverse_iterator										reverse_iterator;
			typedef typename tree::const_reverse_iterator								const_reverse_iterator;
			typedef typename tree::size_type											size_type;
			typedef typename tree::difference_type										difference_type;

			/* Nested function class to compare elements */
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					key_compare	comp;
					value_compare(key_compare c) : comp(c) {}
				public:
					bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};

		private:
			allocator_type	_alloc;
			key_compare		_comp;
			tree			_rbt;


		/*
		**
		** @Member Functions
		**
		*/

		public:

			/*
			** @Constructors and destructor
			*/

			explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _rbt(comp, alloc, alloc) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp)
			{
				insert(first, last);
			}

			map(const map& x) { *this = x; }

			~map()
			{
				this->clear();
				this->_rbt.deleteTreeNull();
			}

			/*
			** @Copy Assignment operator
			*/

			map &operator=(const map &rhs)
			{
				this->clear();
				this->insert(rhs.begin(), rhs.end());
				return (*this);
			}

			/*
			** @Iterators
			*/

			iterator begin()
			{
				if (this->_rbt.getRoot() == this->_rbt.getTreeNull())
					return iterator(this->_rbt.getRoot(), this->_rbt.getRoot(), this->_rbt.getTreeNull());
				return iterator(this->_rbt.BSTMinVal(this->_rbt.getRoot()), this->_rbt.getRoot(), this->_rbt.getTreeNull());
			}

			const_iterator begin() const
			{
				if (this->_rbt.getRoot() == this->_rbt.getTreeNull())
					return iterator(this->_rbt.getRoot(), this->_rbt.getRoot(), this->_rbt.getTreeNull());
				return const_iterator(this->_rbt.BSTMinVal(this->_rbt.getRoot()), this->_rbt.getRoot(), this->_rbt.getTreeNull());
			}

			iterator end() { return iterator(this->_rbt.getTreeNull(), this->_rbt.getRoot(), this->_rbt.getTreeNull()); }

			const_iterator end() const { return const_iterator(this->_rbt.getTreeNull(), this->_rbt.getRoot(), this->_rbt.getTreeNull()); }

			reverse_iterator rbegin()
			{
				if (this->_rbt.getRoot() == this->_rbt.getTreeNull())
					return reverse_iterator(this->_rbt.getRoot(), this->_rbt.getRoot(), this->_rbt.getTreeNull());
				return reverse_iterator(this->_rbt.BSTMaxVal(this->_rbt.getRoot()), this->_rbt.getRoot(), this->_rbt.getTreeNull());
			}

			const_reverse_iterator rbegin() const
			{
				if (this->_rbt.getRoot() == this->_rbt.getTreeNull())
					return const_reverse_iterator(this->_rbt.getRoot(), this->_rbt.getRoot(), this->_rbt.getTreeNull());
				return const_reverse_iterator(this->_rbt.BSTMaxVal(this->_rbt.getRoot()), this->_rbt.getRoot(), this->_rbt.getTreeNull());
			}

			reverse_iterator rend() { return reverse_iterator(this->_rbt.getTreeNull(), this->_rbt.getRoot(), this->_rbt.getTreeNull()); }

			const_reverse_iterator rend() const { return const_reverse_iterator(this->_rbt.getTreeNull(), this->_rbt.getRoot(), this->_rbt.getTreeNull()); }

			/*
			** @Capacity
			*/

			bool empty() const
			{
				if (this->size() > 0)
					return (false);
				return (true);
			}

			size_type size() const
			{
				size_type size = 0;
				for (const_iterator it = this->begin(); it != this->end(); ++it)
					size++;
				return (size);
			}

			size_type max_size() const { return (this->_alloc.max_size()); }

			/*
			** @Element access
			*/

			mapped_type &operator[](const key_type &k)
			{
				iterator tmp = this->find(k);

				if (tmp == this->end())
					this->insert(ft::make_pair(k, mapped_type()));
				tmp = this->find(k);
				return ((*tmp).second);
			}

			/*
			** @Modifiers
			*/

			pair<iterator,bool> insert(const value_type &val)
			{
				NodePtr		node;
				iterator	it = this->find(val.first);

				if (it == this->end())
				{
					node = this->_rbt.insert(val);
					return ft::make_pair<iterator, bool>(iterator(node, this->_rbt.getRoot(), this->_rbt.getTreeNull()), true);
				}
				return ft::make_pair<iterator, bool>(it, false);
			}

			iterator insert(iterator position, const value_type &val)
			{
				(void)position;
				return iterator(this->_rbt.insert(val), this->_rbt.getRoot(), this->_rbt.getTreeNull());
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (InputIterator it = first; it != last; ++it)
					this->_rbt.insert(*it);
			}

			void erase(iterator position)
			{
				this->_rbt.deleteNode((*position).first);
			}

			size_type erase(const key_type &k)
			{
				size_type	size_old = this->size();
				this->_rbt.deleteNode(k);
				if (size_old != this->size())
					return (1);
				return (0);
			}

			void erase(iterator first, iterator last)
			{
				while (first != last)
				{
					NodePtr min = this->_rbt.BSTMinVal(this->_rbt.getRoot());
					NodePtr max = this->_rbt.BSTMaxVal(this->_rbt.getRoot());
					NodePtr node_tmp = this->_rbt.getTreeNull();
					while (min != max)
					{
						if (min->data.first == first->first)
							node_tmp = this->_rbt.find_next(min);
						min = this->_rbt.find_next(min);
					}
					if (max->data.first == first->first)
						node_tmp = this->_rbt.getTreeNull();
					this->_rbt.deleteNode(first->first);
					iterator tmp(node_tmp, this->_rbt.getRoot(), this->_rbt.getTreeNull());
					first = tmp;
				}
			}

			void swap(map& x) { this->_rbt.swap(x._rbt); }

			void clear() { this->_rbt.clear(this->_rbt.getRoot()); }
			
			/*
			** @Observers
			*/

			key_compare key_comp() const { return (this->_comp); }

			value_compare value_comp() const { return(value_compare(this->_comp)); }

			/*
			** @Operations
			*/

			iterator find(const key_type &k) { return iterator(this->_rbt.search(k), this->_rbt.getRoot(), this->_rbt.getTreeNull()); }

			const_iterator find(const key_type &k) const { return const_iterator(this->_rbt.search(k), this->_rbt.getRoot(), this->_rbt.getTreeNull()); }

			size_type count(const key_type &k) const { return !(this->_rbt.search(k) == this->_rbt.getTreeNull()); }

			iterator lower_bound(const key_type &k)
			{
				if (this->_rbt.getRoot() == this->_rbt.getTreeNull())
					return (this->end());

				iterator ret = this->begin();
				for(; ret != this->end(); ++ret)
				{
					if (!this->_comp(ret->first, k))
						break ;
				}
				return ret;
			}

			const_iterator lower_bound(const key_type &k) const
			{
				if (this->_rbt.getRoot() == this->_rbt.getTreeNull())
					return (this->end());

				const_iterator ret = this->begin();
				for(; ret != this->end(); ++ret)
				{
					if (!this->_comp(ret->first, k))
						break ;
				}
				return ret;
			}

			iterator upper_bound(const key_type &k)
			{
				if (this->_rbt.getRoot() == this->_rbt.getTreeNull())
					return iterator(this->_rbt.getTreeNull(), this->_rbt.getRoot(), this->_rbt.getTreeNull());

				iterator ret = this->begin();
				for(; ret != this->end(); ++ret)
				{
					if (this->_comp(k, ret->first))
						break ;
				}
				return ret;
			}

			const_iterator upper_bound(const key_type &k) const
			{
				if (this->_rbt.getRoot() == this->_rbt.getTreeNull())
					return const_iterator(this->_rbt.getTreeNull(), this->_rbt.getRoot(), this->_rbt.getTreeNull());

				const_iterator ret = this->begin();
				for(; ret != this->end(); ++ret)
				{
					if (this->_comp(k, ret->first))
						break ;
				}
				return ret;
			}

			pair<iterator,iterator> equal_range(const key_type &k)
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			pair<const_iterator,const_iterator> equal_range(const key_type &k) const
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			/*
			** @Allocator
			*/

			allocator_type get_allocator() const { return (this->_alloc); }

			/*
			** @Equality operators
			*/

			template <typename K1, typename T1, typename C1, typename A1>
			friend bool operator==(const map<K1, T1, C1, A1>&, const map<K1, T1, C1, A1>&);

			template <typename K1, typename T1, typename C1, typename A1>
			friend bool operator<(const map<K1, T1, C1, A1>&, const map<K1, T1, C1, A1>&);
	};

	/*
	**
	** @Non-member function overloads
	**
	*/

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return !(x == y);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return y < x;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return !(x < y);
	}

	template <class _Key, class T, class Compare, class Alloc>
	bool operator<=(const map<_Key, T, Compare, Alloc>& x,
			const map<_Key, T, Compare, Alloc>& y)
	{
		return !(y < x);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) { x.swap(y); }

} // namespace

#endif

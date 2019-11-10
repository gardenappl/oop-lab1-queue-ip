#ifndef OOP_LAB1_PRIORITY_QUEUE_TREE_H
#define OOP_LAB1_PRIORITY_QUEUE_TREE_H

#include <memory>
#include "priority_queue.h"
#include "algorithms.h"

/*!
 * A struct which represents a node of a binary tree.
 * \tparam T the type of element stored in the tree
 */
template<typename T>
struct tree_node
{
	/*!
	 * A pointer to the left child of this node, or nullptr if there is no left child.
	 */
	tree_node* left = nullptr;
	/*!
	 * A pointer to the right child of this node, or nullptr if there is no right child.
	 */
	tree_node* right = nullptr;
	/*!
	 * The value of the element stored in this node.
	 */
	T value;

	/*!
	 * Construct a node containing an element
	 * \param value the value of the element
	 */
	explicit tree_node(const T& value)
		: value(value)
	{}
};

/*!
 * A priority queue implementation using a binary search tree. The tree is not self-balancing.
 * \tparam T type of the stored elements
 */
template<typename T>
struct priority_queue_tree : public priority_queue<T> {
private:
	tree_node<T>* root;

public:
	/*!
	 * \copydoc priority_queue::priority_queue()
	 */
	priority_queue_tree() = default;
	/*!
	 * \copydoc priority_queue::priority_queue(comparator<T>&)
	 */
	explicit priority_queue_tree(comparator<T>& sort_comparator);
	~priority_queue_tree();

	/*!
	 * \copydoc priority_queue::add(const T&)
	 * \details The tree-based implementation of this function operates in O(log n) time on average,
	 * O(n) time in the worst case.
	 */
	void add(const T& element) override;
	/*!
	 * \copydoc priority_queue::pop()
	 * \details The tree-based implementation of this function operates in O(log n) time on average,
	 * O(n) time in the worst case.
	 */
	T pop() override;
	/*!
	 * \copydoc priority_queue:peek()
	 */
	const T& peek() const override;

private:
	void remove(tree_node<T>* node);
	/*!
	 * An internal function used by priotity_queue_tree<T>::print(std::ostream& os)
	 * Performs an inorder traversal of the binary tree, recursively.
	 * \param os the output stream
	 * \param node the current node
	 * \param printed_once set to true if one element has already been printed before, this is used
	 * to determine whether or not a comma should be printed
	 */
	void print(std::ostream& os, const tree_node<T>* node, bool& printed_once) const;
	/*!
	 * Prints all the elements in the queue into the output stream in the format "{ element1, element2, ... }"
	 * The order of printed elements is based on their priority, starting from the highest priority.
	 * If the queue is empty, prints "<empty>"
	 * This method should be invoked by the << operator.
	 * \param os the output stream
	 */
	void print(std::ostream& os) const override;
};

#endif //OOP_LAB1_PRIORITY_QUEUE_TREE_H

#include "priority_queue_tree.tpp"

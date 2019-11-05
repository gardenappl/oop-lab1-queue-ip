#ifndef OOP_LAB1_PRIORITY_QUEUE_TREE_H
#define OOP_LAB1_PRIORITY_QUEUE_TREE_H

#include <memory>
#include "priority_queue.h"
#include "algorithms.h"

template<typename T>
struct tree_node
{
    tree_node* left = nullptr;
    tree_node* right = nullptr;
    T value;

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
    explicit priority_queue_tree(comparator<T>& comparator);
    ~priority_queue_tree();

    /*!
     * \copydoc priority_queue::add(const T&)
     * \details The tree-based implementation of this function operates in O(log n) time on average,
     * O(n) time in the worst case.
     */
    void add(const T& element) override;
    /*!
     * \copydoc priority_queue::add(const T&)
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
    void print(std::ostream& os, const tree_node<T>* node, bool& printed_once) const;
    void print(std::ostream& os) const override;
};

#endif //OOP_LAB1_PRIORITY_QUEUE_TREE_H

#include "priority_queue_tree.tpp"

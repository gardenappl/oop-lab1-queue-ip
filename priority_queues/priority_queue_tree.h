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

template<typename T>
struct priority_queue_tree : public priority_queue<T> {
private:
    tree_node<T>* root;

public:
    /*!
     * \copydoc priority_queue::priority_queue(comparator<T>&)
     */
    explicit priority_queue_tree(comparator<T>& comparator);
    ~priority_queue_tree();

    void add(const T& element) override;
    T pop() override;
    const T& peek() const override;

private:
    void remove(tree_node<T>* node);
    void print(std::ostream& os, const tree_node<T>* node, bool& printed_once) const;
    void print(std::ostream& os) const override;
};

#endif //OOP_LAB1_PRIORITY_QUEUE_TREE_H

#include "priority_queue_tree.tpp"

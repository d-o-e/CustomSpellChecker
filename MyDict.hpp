/**
 *  Deniz Erisgen ©
 */
#ifndef MYDICT_HPP
#define MYDICT_HPP

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class CustomList;

template<typename H, unsigned nums>
class MyHash {
	CustomList<H> myDataArray[nums];

public:
	MyHash() = default;

	void insert(H item);

	bool find(H item);

	double percentOfBucketsUsed() const;

	double averageNonEmptyBucketSize() const;

	unsigned largestBucketSize() const;

	unsigned hashIt(H input) const;

	unsigned size() const { return nums; }
};

template<typename T>
class Node {
	T data_;
	Node* next_;

public:
	Node(const Node&) = delete;

	Node& operator=(const Node&) = delete;

	Node() : data_(), next_(0) {};

	Node(T d, Node* n) : data_(d), next_(n) {};

	const T& data() const { return data_; };

	Node* next() const { return next_; };
};

template<typename T>
class CustomList {
	Node<T>* top_;
	unsigned numOfNodes;

public:
	CustomList() : top_(0), numOfNodes(0) {};

	~CustomList();

	void push(T object);

	const Node<T>* find(T object) const;

	unsigned sizeOfList() const { return numOfNodes; };

	const Node<T>* top() const { return top_; };
};

#endif  // MYDICT_HPP

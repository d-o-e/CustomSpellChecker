/**
 *  Deniz Erisgen ©
 */
#include "MyDict.hpp"
#include "MyString.hpp"
using namespace std;

template<typename T, unsigned int nums>
unsigned MyHash<T, nums>::hashIt(T input) const {
	int c2 = 0x27d4eb2d;  // a prime or an odd constant
	unsigned key = unsigned(input);
	key = (key ^ 61) ^ (key >> 16);
	key = key + (key << 3);
	key = key ^ (key >> 4);
	key = key * c2;
	key = key ^ (key >> 15);
	return key % size();
}

template<typename T, unsigned nums>
bool MyHash<T, nums>::find(T item) {
	unsigned key;
	key = hashIt(item);
	return myDataArray[key].find(item);
}

template<typename T, unsigned nums>
double MyHash<T, nums>::averageNonEmptyBucketSize() const {
	double average;
	double used;
	for (unsigned i = 0; i < nums; i++) {
		if (myDataArray[i].sizeOfList() != 0) {
			average += myDataArray[i].sizeOfList();
			used++;
			//			cout << i+1 <<"th bucket " << myDataArray[i].sizeOfList() << " items" << endl;
		}
	}
	return average / used;
}

template<typename T, unsigned nums>
unsigned MyHash<T, nums>::largestBucketSize() const {
	unsigned high = 0;
	for (unsigned i = 0; i < nums; i++) {
		high = (myDataArray[i].sizeOfList() > high) ? myDataArray[i].sizeOfList() : high;
	}
	return high;
}

template<typename T, unsigned int nums>
double MyHash<T, nums>::percentOfBucketsUsed() const {
	double used;
	for (unsigned i = 0; i < nums; i++) {
		if (myDataArray[i].sizeOfList() != 0) used++;
	}
	//	cout << "used buckets " << used << endl;
	return used / nums;
}

template<typename T, unsigned int nums>
void MyHash<T, nums>::insert(T item) {
	unsigned key;
	key = hashIt(item);
	//	std::cout << "key is "<<key << std::endl;

	if (myDataArray[key].find(item) != 0) {
		throw DuplicateError<T>(item);
	}
	myDataArray[key].push(item);
}

template<typename T>
CustomList<T>::~CustomList() {
	Node<T>* ptr = top_;
	while (ptr) {
		top_ = top_->next();
		delete ptr;
		ptr = top_;
	}
}

template<typename T>
void CustomList<T>::push(T object) {
	auto* ptr = new Node<T>(object, top_);
	top_ = ptr;
	numOfNodes++;
}

template<typename T>
const Node<T>* CustomList<T>::find(T object) const {
	const Node<T>* ptr = top();
	while (ptr) {
		if (ptr->data() == object) { return ptr; }
		ptr = ptr->next();
	}
	return 0;
}

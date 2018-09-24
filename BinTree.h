#ifndef BINTREE_H
#define BINTREE_H

#include <vector>
#include <iostream>
#include <cmath>
#include <string>

class BinTree {
private:
	struct Node {
		Node(double _value) {
			value = _value;
		}

		Node* parent = NULL;
		Node* childLeft = NULL;
		Node* childRight = NULL;
		int level = 0;
		double value = 0;
		double getValue() { return value; };
	};
	void addNode(Node* node,bool addToSize);
	bool binarySearch(std::vector<double> list, double target);
	int _size = 0;

	Node* root;

public:
	BinTree(double value);
	BinTree();
	virtual ~BinTree();
	void addNode(double value);
	void addNode(Node* node);
	void removeNode(double value);
	void removeNode(Node* node);
	int size();
	double findMin();
	double findMax();
	double findValue(double value);
	Node* findNode(double value);
	bool contains(double value);
	Node* findMinNode();
	Node* findMaxNode();
	std::vector<double> toVector();


};


#endif // !BINTREE_H

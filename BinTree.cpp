#include "BinTree.h"

BinTree::BinTree(double value) {
	root = new Node(value);
	_size++;
}
BinTree::BinTree(){

}
BinTree::~BinTree() {
	std::vector<double> v = toVector();

	for(int i = 0;i < _size;i++){
		Node* n = findNode(v[i]);

		delete n;
	}
}

void BinTree::addNode(double value) {
	if(value == root->getValue()) return;
	Node* current = root;
	Node* parent = current;
	while (true) {
		parent = current;
		if (value < current->getValue()) {
			current = parent->childLeft;
			if (current == NULL) {
				parent->childLeft = new Node(value);
				parent->childLeft->parent = parent;
				parent->childLeft->level = parent->level + 1;
				_size++;
				return;
			}
		}
		else {
			current = parent->childRight;
			if (current == NULL) {
				parent->childRight = new Node(value);
				parent->childRight->parent = parent;
				parent->childRight->level = parent->level + 1;
				_size++;
				return;
			}
		}
	}
}

void BinTree::addNode(Node* node){

	if(node == NULL) return;
	if(node->getValue() == root->getValue()) return;

	Node* current = root;
	Node* parent = current;

	while (true) {
		parent = current;
		if (node->getValue() < current->getValue()) {
			current = parent->childLeft;
			if (current == NULL) {
				parent->childLeft = node;
				parent->childLeft->parent = parent;
				parent->childLeft->level = parent->level + 1;
				_size++;
				if(node->childLeft != NULL){
					addNode(node->childLeft);
				}
				if(node->childRight != NULL){
					addNode(node->childRight);
				}
				return;
			}
		}
		else {
			current = parent->childRight;
			if (current == NULL) {
				parent->childRight = node;
				parent->childRight->parent = parent;
				parent->childRight->level = parent->level + 1;
				_size++;
				if(node->childLeft != NULL){
					addNode(node->childLeft);
				}
				if(node->childRight != NULL){
					addNode(node->childRight);
				}
				return;
			}
		}
	}
}

void BinTree::addNode(Node* node, bool addToSize){

	if(node == NULL) return;
	if(node->getValue() == root->getValue()) return;

	Node* current = root;
	Node* parent = current;

	while (true) {
		parent = current;
		if (node->getValue() < current->getValue()) {
			current = parent->childLeft;
			if (current == NULL) {
				parent->childLeft = node;
				parent->childLeft->parent = parent;
				parent->childLeft->level = parent->level + 1;
				if(addToSize) _size++;
				if(node->childLeft != NULL){
					addNode(node->childLeft);
				}
				if(node->childRight != NULL){
					addNode(node->childRight);
				}
				return;
			}
		}
		else {
			current = parent->childRight;
			if (current == NULL) {
				parent->childRight = node;
				parent->childRight->parent = parent;
				parent->childRight->level = parent->level + 1;
				if(addToSize) _size++;
				if(node->childLeft != NULL){
					addNode(node->childLeft);
				}
				if(node->childRight != NULL){
					addNode(node->childRight);
				}
				return;
			}
		}
	}
}

void BinTree::removeNode(double value){
	Node* n = findNode(value);
	if (n == NULL) return;

	 Node*	tempChildLeft = NULL;
	 Node* tempChildRight = NULL;
	 if(n->childLeft != NULL) tempChildLeft = n->childLeft;
	 if(n->childRight != NULL) tempChildRight = n->childRight;

	 if(n->getValue() < n->parent->getValue()){
		 n->parent->childLeft = NULL;
	 }else if(n->getValue() > n->parent->getValue()){
		 n->parent->childRight = NULL;
	 }

	delete n;
	n = NULL;
	_size--;

	addNode(tempChildLeft,false);
  addNode(tempChildRight,false);
}

void BinTree::removeNode(Node* node){
	if(node == NULL) return;
	Node* n = node;
	 Node*	tempChildLeft = NULL;
	 Node* tempChildRight = NULL;
	 if(n->childLeft != NULL) tempChildLeft = n->childLeft;
	 if(n->childRight != NULL) tempChildRight = n->childRight;

	 if(n->getValue() < n->parent->getValue()){
		 n->parent->childLeft = NULL;
	 }else if(n->getValue() > n->parent->getValue()){
		 n->parent->childRight = NULL;
	 }

	delete n;
	n = NULL;
	_size--;
	addNode(tempChildLeft,false);
  addNode(tempChildRight,false);
}

int BinTree::size() {
	return this->_size;
}

double BinTree::findMin() {
	Node* n = root;
	while (n->childLeft != NULL) {
		n = n->childLeft;
	}
	return n->getValue();
}

double BinTree::findMax() {
	Node* n = root;
	while (n->childRight != NULL) {
		n = n->childRight;
	}
	return n->getValue();
}

BinTree::Node*  BinTree::findMinNode() {
	Node* n = root;
	while (n->childLeft != NULL) {
		n = n->childLeft;
	}
	return n;
}

BinTree::Node*  BinTree::findMaxNode() {
	Node* n = root;
	while (n->childRight != NULL) {
		n = n->childRight;
	}
	return n;
}

double BinTree::findValue(double value) {
	Node* current = root;
	if (value < findMin() || value > findMax()) {
		return 0;
	}
	while (true) {
		//found the value
		if (current->getValue() == value) {
			return current->getValue();
		}
		//look left
		else if (value < current->getValue()) {
			current = current->childLeft;
		}
		//look right
		else {
			current = current->childRight;
		}
	}
}

BinTree::Node* BinTree::findNode(double value) {
	Node* current = root;
	if (value < findMin() || value > findMax()) {
		return 0;
	}
	while (true) {
		if (current->getValue() == value) {
			return current;
		}else if (current->childLeft == NULL && current->childRight == NULL){
			return 0;
		}
		//look left
		else if (value < current->getValue()) {
			current = current->childLeft;
		}
		//look right
		else if(value > current->getValue()) {
			current = current->childRight;
		}
	}
}

bool BinTree::binarySearch(std::vector<double> list, double target){

	if(list.size() == 1){

		if(list[0] == target)return true; else return false;
	}

	int low = 0;
	int high = list.size()-1;

	int center;

	while(low <= high){
		center = (int) floor(low + (high-low)/2);

		if(list[center] == target){
			return true;
			break;
		}

		if(target < list[center]){
			high = center - 1;
		}else{
			low = center + 1;
		}
	}

	return false;
}

bool BinTree::contains(double value) {
	Node* current = root;

	if (value < findMin() || value > findMax()) {
		return false;
	}
	while (true) {
		//found the value
		if (current->getValue() == value) {
			return true;
		}else if (current->childLeft == NULL && current->childRight == NULL){
			return false;
		}
		//look left
		else if (value < current->getValue()) {
			current = current->childLeft;
		}
		//look right
		else {
			current = current->childRight;
		}
	}
}

std::vector<double> BinTree::toVector() {

	Node* current = findMinNode();
	std::vector<double> list;

	while(list.size() != _size){

		if(current->getValue() < root->getValue()){
			if(current->childLeft == NULL && current->childRight == NULL){
				if(!binarySearch(list,current->getValue()))list.push_back(current->getValue());
				current = current->parent;
			}else if(current->childLeft != NULL && current->childRight != NULL && binarySearch(list,current->childLeft->getValue()) && binarySearch(list,current->childRight->getValue())){
				current = current->parent;
			}else if(current->childRight != NULL && !binarySearch(list,current->childRight->getValue())){
				list.push_back(current->getValue());
				current = current->childRight;
			}else if(current->childRight == NULL && current->childLeft != NULL && binarySearch(list,current->childLeft->getValue())){
				if(!binarySearch(list,current->getValue()))list.push_back(current->getValue());
				current = current->parent;
			}else if(current->childLeft == NULL && current->childRight != NULL && binarySearch(list,current->childRight->getValue())){
				if(!binarySearch(list,current->getValue())) list.push_back(current->getValue());
				current = current->parent;
			}
		}else {
			if(current->childLeft == NULL && current->childRight == NULL){
				if(current == findMaxNode()){
					if(!binarySearch(list,current->getValue()))list.push_back(current->getValue());
				}else{
					if(!binarySearch(list,current->getValue()))list.push_back(current->getValue());
					current = current->parent;
				}
			}else if(current->childLeft != NULL && !binarySearch(list,current->childLeft->getValue())){
				current = current->childLeft;
			}else if(current->childRight != NULL && !binarySearch(list,current->childRight->getValue())){
				list.push_back(current->getValue());
				current = current->childRight;
			}else if(current->childRight == NULL && current->childLeft != NULL && binarySearch(list,current->childLeft->getValue())){
				list.push_back(current->getValue());
				current = current->parent;
			}else if(current->childLeft == NULL && current->childRight != NULL && binarySearch(list,current->childRight->getValue())){
				list.push_back(current->getValue());
				current = current->parent;
			}
		}

	}


	return list;
}

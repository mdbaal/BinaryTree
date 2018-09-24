#include "BinTree.h"
using namespace std;
int main(void) {
	cout << endl << "creating new tree, with start value 5" << endl;
	BinTree tree =  BinTree(5);
	//cout << "adding: 3.5,7,6.9,8,8.3 and -5" << endl;
	tree.addNode(3.5);
	tree.addNode(7);
	tree.addNode(6.9);
	tree.addNode(8);
	tree.addNode(8.3);
	tree.addNode(-5);
	tree.addNode(-100);
 	tree.addNode(.3);
	tree.addNode(9.01);
	tree.addNode(6);
	tree.addNode(4);

	cout <<endl << "testing methods in tree" << endl;
	cout << "#######################" << endl;
	cout << "find min value: " << tree.findMin() << endl;
	cout << "find max value: " << tree.findMax() << endl;
	cout << "find min Node: " << tree.findMinNode() << endl;
	cout << "find max node: " << tree.findMaxNode() << endl;
	cout << "find value 5: " << tree.findValue(5) << endl;
	cout << "find Node 4: " << tree.findNode(4) << endl;

	cout << "contains -5?: " << tree.contains(-5) << endl;
	cout << "contains 3?: " << tree.contains(3) << endl;
	cout << "contains 25?: "<< tree.contains(25) << endl;
	cout << "contains 6?: "<< tree.contains(6) << endl;
	cout << "contains 7?: "<< tree.contains(7) << endl;
	cout << "contains 8?: "<< tree.contains(8) << endl;
	cout << "contains 4?: "<< tree.contains(4) << endl;
	cout << endl;

	vector<double> list = tree.toVector();

	cout << "Tree in array" << endl;
	cout << "#######################" << endl;
	for(int i = 0;i < list.size() ;i++){
		std::cout << list[i] << std::endl;
	}
	cout <<endl << "remove -5" << endl << endl;
	tree.removeNode(-5);
	cout <<endl << "remove 6.9" << endl << endl;
	tree.removeNode(6.9);
	cout <<endl << "remove 8.3" << endl << endl;
	tree.removeNode(8.3);

	list = tree.toVector();
	cout << "Tree in array after the removing of 4" << endl;
	cout << "#######################" << endl;
	for(int i = 0;i < list.size() ;i++){
		std::cout << list[i] << std::endl;
	}


	return 0;
}

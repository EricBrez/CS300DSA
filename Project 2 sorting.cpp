// The sorting and printing functions require two separate parts of the code. The first (the first 6 functions) traverse the tree while the insert() function (at the bottom)
// inserts courses into the tree in alphanumeric order.


//Traverse tree in order
void BinarySearchTree::InOrder() {
	inOrder(root);
}

//Traverse tree in post order
void BinarySearchTree::PostOrder() {
	postOrder(root);
}

//Traverse Tree in pre order
void BinarySearchTree::PreOrder() {
	preOrder(root);
}

//Traverse the tree in order
void BinarySearchTree::inOrder(Node* node) {
	PreOrder();
	if (node != nullptr) {
		inOrder(node->left);
		cout << node->course.courseNum << ": " << node->course.courseName << endl;
		inOrder(node->right);
	}
	return;
}

//Traverse the tree in post order
void BinarySearchTree::postOrder(Node* node) {
	PreOrder();
	if (node != nullptr) {
		postOrder(node->left);
		postOrder(node->right);
		cout << node->course.courseNum << ": " << node->course.courseName << endl;
	}
	return;
}

//Traverse the tree in pre order
void BinarySearchTree::preOrder(Node* node) {
	PreOrder();
	if (node != nullptr) {
		cout << node->course.courseNum << ": " << node->course.courseName << endl;
		postOrder(node->left);
		postOrder(node->right);
	}
	return;
}

//Insert course
void BinarySearchTree::insert(Course course) {
	if (root == nullptr) {
		root->course = course;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		Node* newNode = new Node(course);
		Node* currNode = root;
		while (currNode != nullptr) {
			if (course.courseNum < currNode->course.courseNum) {
				if (currNode->left == nullptr) {
					currNode->left = newNode;
					currNode = nullptr;
				}
				else {
					currNode = currNode->left;
				}
			}
			else {
				if (currNode->right == nullptr) {
					currNode->right = newNode;
					currNode = nullptr;
				}
				else {
					currNode = currNode->right;
				}
			}
		}
		newNode->left = nullptr;
		newNode->right = nullptr;
	}
}

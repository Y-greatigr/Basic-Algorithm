#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <ctime>

using namespace std;
vector<int> a(100'000); // 100,000 ũ���� ���� �����͸� ���� �������� ���� a ����
vector<int> b(100); // 100 ũ���� ���� �����͸� ���� �������� ���� b ����

void random_generate_alldata(int range) {
	random_device rd;    // �õ尪�� ��� ���� random_device ����.
	mt19937 gen(rd());  // random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	uniform_int_distribution<int> dis(0, 10'000'000);    // 0 ���� 10,000,000 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.

	for (int i = 0; i < range; i++) a[i] = dis(gen);      // 0 ���� 10,000,000 ���̿��� ������ ���� range�� ����
}
void random_generate_index(int range) {
	random_device rd;    // �õ尪�� ��� ���� random_device ����.
	mt19937 gen(rd());  // random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	uniform_int_distribution<int> dis(0, range-1);    // 0 ���� range-1 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.

	for (int i = 0; i < 100; i++) b[i] = dis(gen);      // 0 ���� range-1 ���̿��� ������ ���� 100�� ����
}


template<typename T>
struct Node { Node* left; Node* right; T value; };

template <typename T>
class BinarySearchTree {
public:
	BinarySearchTree() :root(nullptr) {};
	~BinarySearchTree() {};

	void AddNode(T _value);
	int SearchValue(T _value);
	void rem();
	void rem(Node<T>* ptr);
private:
	Node<T>* root;
	Node<T>* tail;
};

template <typename T>
int BinarySearchTree<T>::SearchValue(T _value) {
	Node<T>* ptr = root;
	Node<T>* tmpRoot = nullptr;
	
	int cnt = 0;
	while (ptr != nullptr) {
		if (ptr->value == _value) {
			return cnt;
		}
		else if (ptr->value > _value) ptr = ptr->left;
		else ptr = ptr->right;
		cnt++;
	}
	cout << _value << " ���� ã�� ���߽��ϴ�." << endl;
	return false;
}

template <typename T>
void BinarySearchTree<T>::AddNode(T _value) {
	Node<T>* node = new Node<T>();
	Node<T>* tmpRoot = nullptr;
	node->value = _value;
	if (root == nullptr) root = node;
	else {
		Node<T>* ptr = root;
		while (ptr != nullptr) {
			tmpRoot = ptr;
			if (node->value < ptr->value) { ptr = ptr->left; }
			else { ptr = ptr->right; }
		}

		//���� ��ġ�� ���� 
		if (node->value < tmpRoot->value) tmpRoot->left = node;
		else tmpRoot->right = node;
	}
}

template <typename T>
void BinarySearchTree<T>::rem() {
	Node<T>* ptr = root;
	if (ptr) {
		rem(ptr->left);
		rem(ptr->right);
		delete ptr;
	}
}


template <typename T>
void BinarySearchTree<T>::rem(Node<T>* ptr) {
	if (ptr) {
		rem(ptr->left);
		rem(ptr->right);
		delete ptr;
	}
}

// An AVL tree node
class NodeAVL
{
public:
	int key;
	NodeAVL* left;
	NodeAVL* right;
	int height;
};

// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get the
// height of the tree
int height(NodeAVL* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

/* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
NodeAVL* newNode(int key)
{
	NodeAVL* node = new NodeAVL();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					  // added at leaf
	return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
NodeAVL* rightRotate(NodeAVL* y)
{
	NodeAVL* x = y->left;
	NodeAVL* T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
NodeAVL* leftRotate(NodeAVL* x)
{
	NodeAVL* y = x->right;
	NodeAVL* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(NodeAVL* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
NodeAVL* insert(NodeAVL* node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
		height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}
int search_AVL(NodeAVL* root, int value)
{
	NodeAVL* tmp = root;
	NodeAVL* parent = NULL;
	int cnt = 0;
	/*key���� ã�ų� ���ٸ� break*/
	while (tmp != NULL && tmp->key != value)
	{
		parent = tmp;
		tmp = (value < parent->key) ? parent->left : parent->right;
		cnt++;
	}
	return cnt;
}
void postdelete(NodeAVL* root) {
	if (root) {
		postdelete(root->left);
		postdelete(root->right);
		delete root;
	}
}
enum Color
{
	RED,
	BLACK
};
struct node
{
	int key;
	node* left = nullptr;
	node* right = nullptr;
	node* parent = nullptr;
	Color color = BLACK;
};

typedef node* NodePtr;

class RBTREE
{
private:
	NodePtr root;     //��Ʈ ���
	NodePtr leafNode; //�ܸ����

	void InsertFixUp(NodePtr z)
	{
		/*root ��尡 �ƴϰ� �θ� ���� red���*/
		while (z != root && z->parent->color == RED)
		{
			NodePtr grandparent = z->parent->parent;
			NodePtr uncle = (z->parent == grandparent->left) ? grandparent->right : grandparent->left;
			bool side = (z->parent == grandparent->left) ? true : false; //if p[z]�� p[p[z]]�� ���� �ڽ��̸� 1 / �������̸� 0

			/*case 1*/
			if (uncle && uncle->color == RED)
			{
				z->parent->color = BLACK;
				uncle->color = BLACK;
				grandparent->color = RED;
				z = grandparent;
			}

			/*case 2
				side == true ) p[z]�� p[p[z]]�� ���� �ڽ� �� ����̴�.
				side == false ) p[z]�� p[p[z]]�� ������ �ڽ� �� ����̴�. */
			else
			{
				/*case 2-1*/
				if (z == (side ? z->parent->right : z->parent->left))
				{
					z = z->parent;
					side ? RotateLeft(z) : RotateRight(z);
				}
				/*case 2-2*/
				z->parent->color = BLACK;
				grandparent->color = RED;
				side ? RotateRight(grandparent) : RotateLeft(grandparent);
			}
		}
		root->color = BLACK;
	}

	/*x�� �߽����� �������� ȸ��*/
	void RotateLeft(NodePtr x)
	{
		NodePtr y;

		y = x->right;
		x->right = y->left;
		if (y->left != leafNode)
		{
			y->left->parent = x;
		}
		y->parent = x->parent;

		if (!x->parent)
		{
			root = y;
		}
		else if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
		x->parent = y;
		y->left = x;
	}
	/*x�� �߽����� ���������� ȸ��*/
	void RotateRight(NodePtr y)
	{
		NodePtr x;

		x = y->left;
		y->left = x->right;
		if (x->right != leafNode)
		{
			x->right->parent = y;
		}
		x->parent = y->parent;

		if (!y->parent)
		{
			root = x;
		}
		else if (y == y->parent->left)
		{
			y->parent->left = x;
		}
		else
		{
			y->parent->right = x;
		}
		y->parent = x;
		x->right = y;
	}

public:
	RBTREE()
	{
		leafNode = new node;
		leafNode->color = BLACK;
		leafNode->left = nullptr;
		leafNode->right = nullptr;
		leafNode->parent = nullptr;
		root = leafNode;
	}
	//key���� �ִ��� ������ �˻� ������ pointer ��, ������ nullptr
	int IsKey(int item)
	{
		NodePtr t = root;
		NodePtr parent = NULL;

		int cnt = 0;
		/*key���� ã�ų� ���ٸ� break*/
		while (t != NULL && t->key != item)
		{
			parent = t;
			t = (item < parent->key) ? parent->left : parent->right;
			cnt++;
		}
		return cnt;
	}

	void Insert(int item)
	{
		// x : ������ �� ã������ ������ | y : ������ ���� �θ���
		NodePtr x = this->root, y = nullptr;
		NodePtr z = new node();
		z->key = item;
		z->color = RED;
		z->parent = nullptr;
		z->left = leafNode;
		z->right = leafNode;

		/*BST�� �Ϲ� ���� ����*/
		while (x != leafNode)
		{
			y = x;
			if (x->key < item)
				x = x->right;
			else
				x = x->left;
		}

		z->parent = y;

		if (y == nullptr)
			root = z;
		else if (z->key > y->key)
			y->right = z;
		else
			y->left = z;

		//z�� root�����
		if (z->parent == nullptr)
		{
			z->color = BLACK;
			return;
		}
		// z�� �θ��尡 root����� Fix Up �ʿ���� red�÷��� �ٿ��ָ� �ȴ�.
		if (z->parent->parent == nullptr)
		{
			return;
		}
		InsertFixUp(z);

		return;
	}
	void postdeleteRB() {
		if (root) {
			postdeleteRB(root->left);
			postdeleteRB(root->right);
			delete root;
		}
	}
	void postdeleteRB(NodePtr ptr){
		if (ptr) {
			postdeleteRB(ptr->left);
			postdeleteRB(ptr->right);
			delete ptr;
		}
	}
};
// ��� ����
typedef struct Node_ST {
	Node_ST* parent = nullptr;
	Node_ST* leftc = nullptr;
	Node_ST* rightc = nullptr;
	int data = NULL;
} Node_ST;

// Splay Tree Class
class Splay {
	Node_ST* root;

public:
	Splay();
	Splay(int element);

	// �ٽ� �ż���
	void insertItem(int element);
	int findElement(int element);
	Node_ST* treeSearch(Node_ST* now, int element);

	// Ʈ�� �⺻ �ż���
	void expand(Node_ST* external, int element);
	int depth(Node_ST* now);
	int height(Node_ST* now);

	// Splay Ʈ�� �ż���
	void doSplay(Node_ST* now);

	// rotate
	void rightRotate(Node_ST* x, Node_ST* y);
	void leftRotate(Node_ST* x, Node_ST* y);

	// Ʈ�� boolean �ż���
	bool isRoot(Node_ST* tmp);
	bool isExternal(Node_ST* tmp);

	void postdeleteST(Node_ST* ptr) {
		if (ptr) {
			postdeleteST(ptr->leftc);
			postdeleteST(ptr->rightc);
			delete ptr;
		}
	}
	void postdeleteST() {
		if (root) {
			postdeleteST(root->leftc);
			postdeleteST(root->rightc);
			delete root;
		}
	}
	// get
	Node_ST* getRoot();
};

// ������
Splay::Splay() {}

// ��Ʈ �ʱ�ȭ ������
Splay::Splay(int element) {
	root = new Node_ST;
	root->data = element;
	root->parent = nullptr;
	root->leftc = new Node_ST;
	root->rightc = new Node_ST;

	root->leftc->parent = root;
	root->rightc->parent = root;
}

/*
** �ٽ� �޼���
*/
// ��� ����
void Splay::insertItem(int element) {
	Node_ST* tmp = treeSearch(root, element);

	if (isExternal(tmp)) {
		expand(tmp, element);
		doSplay(tmp);
	}
}

// ���� �˻�
int Splay::findElement(int element) {
	Node_ST* tmp = root;
	Node_ST* parent = NULL;
	int cnt = 0;
	/*key���� ã�ų� ���ٸ� break*/
	while (tmp != NULL && tmp->data != element)
	{
		parent = tmp;
		tmp = (element < parent->data) ? parent->leftc : parent->rightc;
		cnt++;
	}
	return cnt;
}

// Ʈ�� �˻�
// ������ ��ġ�� ��ȯ
Node_ST* Splay::treeSearch(Node_ST* now, int element) {
	if (element == now->data) return now;

	Node_ST* tmp = nullptr;
	if (element < now->data) {
		tmp = now->leftc;
	}
	else {
		tmp = now->rightc;
	}

	if (isExternal(tmp)) return tmp;
	treeSearch(tmp, element);
}


/*
** Ʈ�� �⺻ �ż���
*/
// ���� ���� Ȯ��
void Splay::expand(Node_ST* external, int element) {
	external->data = element;
	try {
		external->leftc = new Node_ST;
		external->rightc = new Node_ST;
	}
	catch (bad_alloc e) {

	}

	external->leftc->parent = external;
	external->rightc->parent = external;
}

// ���̸� ��ȯ
int Splay::depth(Node_ST* now) {
	int ret = 0;

	while (!isRoot(now)) {
		now = now->parent;
		++ret;
	}

	return ret;
}

// ����� ���̸� ��ȯ
int Splay::height(Node_ST* now) {
	int h = 0;
	int left = 0, right = 0;

	if (now->leftc->data != NULL) {
		left = height(now->leftc);
	}
	if (now->rightc->data != NULL) {
		right = height(now->rightc);
	}

	int maxHeight = max(left, right);
	h = 1 + maxHeight;

	return h;
}


/*
** Splay Ʈ��  �ż���
*/
void Splay::doSplay(Node_ST* now) {
	// ����ó��
	if (now == nullptr) return;

	// ��Ʈ�� �����ϸ� ����
	if (isRoot(now)) {
		root = now;
		return;
	}

	// �θ� ��Ʈ�ΰ�?
	if (isRoot(now->parent)) {
		if (now == now->parent->leftc) {
			rightRotate(now, root);
		}
		else {
			leftRotate(now, root);
		}
		root = now;
		return;
	}

	// ������ ���
	Node_ST* p = now->parent;
	Node_ST* gp = p->parent;

	if (now == gp->leftc->leftc) {
		rightRotate(p, gp);
		rightRotate(now, p);
	}
	else if (now == gp->rightc->rightc) {
		leftRotate(p, gp);
		leftRotate(now, p);
	}
	else if (now == gp->rightc->leftc) {
		rightRotate(now, p);
		leftRotate(now, gp);
	}
	else {
		leftRotate(now, p);
		rightRotate(now, gp);
	}

	// recur
	doSplay(now);
}

/*
** Rotate
*/
// Right
void Splay::rightRotate(Node_ST* x, Node_ST* y) {
	y->leftc = x->rightc;
	x->rightc->parent = y;

	x->parent = y->parent;
	if (y->parent != nullptr) {
		if (y == y->parent->leftc) y->parent->leftc = x;
		else y->parent->rightc = x;
	}

	x->rightc = y;
	y->parent = x;
}

// Left
void Splay::leftRotate(Node_ST* x, Node_ST* y) {
	y->rightc = x->leftc;
	x->leftc->parent = y;

	x->parent = y->parent;
	if (y->parent != nullptr) {
		if (y == y->parent->leftc) y->parent->leftc = x;
		else y->parent->rightc = x;
	}

	x->leftc = y;
	y->parent = x;
}


/*
** Ʈ�� boolean �ż���
*/
// ��Ʈ�ΰ�?
bool Splay::isRoot(Node_ST* tmp) {
	return tmp->parent == nullptr;
}

// �ܺ� ����ΰ�?
bool Splay::isExternal(Node_ST* tmp) {
	return tmp->data == NULL;
}

// get
Node_ST* Splay::getRoot() {
	return root;
}

struct TreapNod { //node declaration
	int data;
	int priority;
	TreapNod* l, * r;
	TreapNod(int d) { //constructor
		this->data = d;
		this->priority = rand() % 100;
		this->l = this->r = nullptr;
	}
};
void rotLeft(TreapNod*& root) { //left rotation
	TreapNod* R = root->r;
	TreapNod* X = root->r->l;
	R->l = root;
	root->r = X;
	root = R;
}
void rotRight(TreapNod*& root) { //right rotation
	TreapNod* L = root->l;
	TreapNod* Y = root->l->r;
	L->r = root;
	root->l = Y;
	root = L;
}
void insertNod(TreapNod*& root, int d) { //insertion
	if (root == nullptr) {
		root = new TreapNod(d);
		return;
	}
	if (d < root->data) {
		insertNod(root->l, d);
		if (root->l != nullptr && root->l->priority > root->priority)
			rotRight(root);
	}
	else {
		insertNod(root->r, d);
		if (root->r != nullptr && root->r->priority > root->priority)
			rotLeft(root);
	}
}
int searchNod(TreapNod* root, int key) {
	TreapNod* tmp = root;
	TreapNod* parent = NULL;
	int cnt = 0;
	/*key���� ã�ų� ���ٸ� break*/
	while (tmp != NULL && tmp->data != key)
	{
		parent = tmp;
		tmp = (key < parent->data) ? parent->l : parent->r;
		cnt++;
	}
	return cnt;
}
void postdeleteTR(TreapNod* root) {
	if (root) {
		postdeleteTR(root->l);
		postdeleteTR(root->r);
		delete root;
	}
}
void search_compare(int data_size) {
	cout << "<������ " << data_size << "��>" << endl;
	double cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
	for (int p = 0; p < 100; p++) {
		random_generate_alldata(data_size);
		random_generate_index(data_size);
		
		BinarySearchTree<int>* BST = new BinarySearchTree<int>();
		for (int i = 0; i < data_size; i++) BST->AddNode(a[i]);
		cnt1 += BST->SearchValue(a[b[p]]);
		BST->rem();
		delete BST;

		NodeAVL* root1 = NULL;
		for (int i = 0; i < data_size; i++) root1 = insert(root1, a[i]);
		cnt2 += search_AVL(root1, a[b[p]]);
		postdelete(root1);
	
		RBTREE RBtree;
		for (int i = 0; i < data_size; i++) RBtree.Insert(a[i]);
		cnt3 += RBtree.IsKey(a[b[p]]);

		Splay splayT(a[0]);
		for (int i = 1; i < data_size; i++) splayT.insertItem(a[i]);
		cnt4 += splayT.findElement(a[b[p]]);
		splayT.postdeleteST();

		TreapNod* root2 = nullptr;
		for (int i = 1; i < data_size; i++) insertNod(root2, a[i]);
		cnt5 += searchNod(root2, a[b[p]]);
		postdeleteTR(root2);
	}
	cout << "B.S.T�� ��� Ž�� Ƚ�� : " << cnt1 / 100 << endl;
	cout << "AVL Tree�� ��� Ž�� Ƚ�� : " << cnt2 / 100 << endl;
	cout << "Red-Black Tree�� ��� Ž�� Ƚ�� : " << cnt3 / 100 << endl;
	cout << "Splay Tree�� ��� Ž�� Ƚ�� : " << cnt4 / 100 << endl;
	cout << "Treaps�� ��� Ž�� Ƚ�� : " << cnt5 / 100 << endl << endl;
}
int main() {
	search_compare(1000);
	search_compare(5000);
	search_compare(10000);
	search_compare(50000);
	search_compare(100000);
    return 0;
}
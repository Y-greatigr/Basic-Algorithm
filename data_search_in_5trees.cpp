#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <ctime>

using namespace std;
vector<int> a(100'000); // 100,000 ũ���� ���� �����͸� ���� �������� ���� a ����
vector<int> ins_1000(100); // 1,000�� �����Ϳ� ���� 100���� �ν��Ͻ��� ���� �������� ���� ����
vector<int> ins_5000(100); // 5,000�� �����Ϳ� ���� 100���� �ν��Ͻ��� ���� �������� ���� ����
vector<int> ins_10000(100); // 10,000�� �����Ϳ� ���� 100���� �ν��Ͻ��� ���� �������� ���� ����
vector<int> ins_50000(100); // 50,000�� �����Ϳ� ���� 100���� �ν��Ͻ��� ���� �������� ���� ����
vector<int> ins_100000(100); // 100,000�� �����Ϳ� ���� 100���� �ν��Ͻ��� ���� �������� ���� ����

void random_generate() {
    random_device rd;    // �õ尪�� ��� ���� random_device ����.
    mt19937 gen(rd());  // random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
    uniform_int_distribution<int> dis(0, 10'000'000);    // 0 ���� 10,000,000 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	uniform_int_distribution<int> dis_1(0, 999);    // 0 ���� 999 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	uniform_int_distribution<int> dis_2(0, 4'999);    // 0 ���� 4,999 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	uniform_int_distribution<int> dis_3(0, 9'999);    // 0 ���� 9,999 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	uniform_int_distribution<int> dis_4(0, 49'999);    // 0 ���� 49,999 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	uniform_int_distribution<int> dis_5(0, 99'999);    // 0 ���� 99,999 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.


    for (int i = 0; i < 100'000; i++) a[i] = dis(gen);      // 0 ���� 10,000,000 ���̿��� ������ ���� 100,000�� ����
    for (int i = 0; i < 100; i++) ins_1000[i] = a[dis_1(gen)];  // 1,000�� �����Ϳ� ���� 100���� ������ �ν��Ͻ� ����
    for (int i = 0; i < 100; i++) ins_5000[i] = a[dis_2(gen)];  // 5,000�� �����Ϳ� ���� 100���� �ν��Ͻ� ����
    for (int i = 0; i < 100; i++) ins_10000[i] = a[dis_3(gen)];    // 10,000�� �����Ϳ� ���� 100���� �ν��Ͻ� ����
    for (int i = 0; i < 100; i++) ins_50000[i] = a[dis_4(gen)];    // 50,000�� �����Ϳ� ���� 100���� �ν��Ͻ� ����
    for (int i = 0; i < 100; i++) ins_100000[i] = a[dis_5(gen)];  // 100,000�� �����Ϳ� ���� 100���� �ν��Ͻ� ����
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
// ��� ����ü�� �����մϴ�.
struct nodeAVL
{
	int data;
	struct nodeAVL* left;
	struct nodeAVL* right;
} *root;

// Ŭ������ �����մϴ�.
class classAVL
{
public:
	// ����� ���̸� ��ȯ�մϴ�.
	int height(nodeAVL*);
	// �����μ�(������ ����)�� ��ȯ�մϴ�.
	int diff(nodeAVL*);
	// RR ȸ�� �Լ��Դϴ�.
	nodeAVL* rr(nodeAVL*);
	// LL ȸ�� �Լ��Դϴ�.
	nodeAVL* ll(nodeAVL*);
	// LR ȸ�� �Լ��Դϴ�.
	nodeAVL* lr(nodeAVL*);
	// RL ȸ�� �Լ��Դϴ�.
	nodeAVL* rl(nodeAVL*);
	// Ʈ���� ������ ���ߴ� �Լ��Դϴ�.
	nodeAVL* balance(nodeAVL*);
	// AVL Ʈ���� ���ο� ���Ҹ� �����մϴ�.
	nodeAVL* insert(nodeAVL*, int);
	// ������ AVL Ʈ�� ������ �����ִ� �Լ��Դϴ�.
	int search_AVL(nodeAVL*, int);
	// AVL Ʈ���� Ű���� ã���ִ� �Լ��Դϴ�.
	classAVL()
	{
		root = NULL;
	}
};
// AVL Ʈ���� ���̸� ����մϴ�.
int classAVL::height(nodeAVL* temp)
{
	int h = 0;
	if (temp != NULL)
	{
		// ��������� ���� Ȥ�� ���������� �˻��մϴ�.
		int left = height(temp->left);
		int right = height(temp->right);
		int maxHeight = max(left, right);
		h = maxHeight + 1;
	}
	return h;
}

// �����μ�(������ ����)�� ��ȯ�մϴ�.
int classAVL::diff(nodeAVL* temp)
{
	// ���� �ڽ��� ���̿� ������ �ڽ��� ���� ���̸� ��ȯ�մϴ�.
	int left = height(temp->left);
	int right = height(temp->right);
	int factor = left - right;
	return factor;
}

// RR ȸ�� �Լ��Դϴ�.
nodeAVL* classAVL::rr(nodeAVL* parent)
{
	// ���� ȸ������ �׳� �θ� ����� ������ �ڽĳ��� �����͸� ��ȯ�ϴ� ���Դϴ�.
	nodeAVL* temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

// ll ȸ�� �Լ��Դϴ�.
nodeAVL* classAVL::ll(nodeAVL* parent)
{
	// RR ȸ���� �ݴ��Դϴ�.
	nodeAVL* temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

// LR ȸ�� �Լ��Դϴ�.
nodeAVL* classAVL::lr(nodeAVL* parent)
{
	// LR ȸ���� ���� �ڽ��� �������� RR, ������ �������� LLȸ���մϴ�.
	nodeAVL* temp;
	temp = parent->left;
	parent->left = rr(temp);
	return ll(parent);
}

// RL ȸ�� �Լ��Դϴ�.
nodeAVL* classAVL::rl(nodeAVL* parent)
{
	// LR ȸ���� �ݴ��Դϴ�.
	nodeAVL* temp;
	temp = parent->right;
	parent->right = ll(temp);
	return rr(parent);
}

// AVL Ʈ���� ������ ���ߴ� �Լ��Դϴ�.
nodeAVL* classAVL::balance(nodeAVL* temp)
{
	int factor = diff(temp);
	// ���� ����Ʈ�������� ������ �Ǿ� ������ ���� ����Դϴ�.
	if (factor > 1)
	{
		// �� ���� �ڽĳ�忡 ������ �߻��߽��ϴ�.
		if (diff(temp->left) > 0)
		{
			temp = ll(temp);
		}
		// �� ������ �ڽ� ��忡 ������ �߻��߽��ϴ�.
		else
		{
			temp = lr(temp);
		}
	}
	else if (factor < -1)
	{
		if (diff(temp->right) > 0)
		{
			temp = rl(temp);
		}
		else
		{
			temp = rr(temp);
		}
	}
	return temp;
}

// Ʈ���� ���Ҹ� �����ϴ� �Լ��Դϴ�.
nodeAVL* classAVL::insert(nodeAVL* root, int value)
{
	// ���� Ʈ���� ����� ��
	if (root == NULL)
	{
		root = new nodeAVL;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value);
		root = balance(root);
	}
	// ũ�ų� ���� ��� ������ ����Ʈ���� �����մϴ�.
	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
		root = balance(root);
	}
	return root;
}

// Ʈ���� ���Ҹ� ã���ִ� �Լ��Դϴ�.
int classAVL::search_AVL(nodeAVL* root, int value)
{
	//�������� ��θ� ť�� �����ϰ� ���������� ���
	nodeAVL* ptr = root;
	bool find = false;
	int cnt = 0;
	if (value == root->data) //root�� �����͸� ã�� ���
	{
		return cnt;
	}
	while (ptr && value != root->data) //root�� �ƴ� ����� �����͸� ã�� ���
	{
		if (value < ptr->data) {
			ptr = ptr->left;
			cnt++;
		}
		else if (value > ptr->data) {
			ptr = ptr->right;
			cnt++;
		}
		else if (value == ptr->data) {
			find = true;
			return cnt;
		}
	}
	cout << "ã���ô� �����Ͱ� �����ϴ�" << endl;
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
	external->leftc = new Node_ST;
	external->rightc = new Node_ST;

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

int BST_Search(int count) {
	BinarySearchTree<int>* BST = new BinarySearchTree<int>();
	for (int i = 0; i < count; i++) BST->AddNode(a[i]);
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		if(count==1000) cnt += BST->SearchValue(ins_1000[i]);
		else if(count ==5000) cnt += BST->SearchValue(ins_5000[i]);
		else if (count == 10000) cnt += BST->SearchValue(ins_10000[i]);
		else if (count == 50000) cnt += BST->SearchValue(ins_50000[i]);
		else if (count == 100000) cnt += BST->SearchValue(ins_100000[i]);
	}
	delete BST;
	return cnt / 100;
}
int AVL_Search(int count) {
	classAVL AVL;
	for (int i = 0; i < count; i++) {
		//cout << i << " "; 
		root = AVL.insert(root, a[i]);
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		if (count == 1000) cnt += AVL.search_AVL(root, ins_1000[i]);
		else if (count == 5000) cnt += AVL.search_AVL(root, ins_5000[i]);
		else if (count == 10000) cnt += AVL.search_AVL(root, ins_10000[i]);
		else if (count == 50000) cnt += AVL.search_AVL(root, ins_50000[i]);
		else if (count == 100000) cnt += AVL.search_AVL(root, ins_100000[i]);
	}
	return cnt / 100;
}
int RBT_Search(int count) {
	RBTREE RBtree;
	for (int i = 0; i < count; i++) {
		//cout << i << " ";
		RBtree.Insert(a[i]);
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		if (count == 1000) cnt += RBtree.IsKey(ins_1000[i]);
		else if (count == 5000) cnt += RBtree.IsKey(ins_5000[i]);
		else if (count == 10000) cnt += RBtree.IsKey(ins_10000[i]);
		else if (count == 50000) cnt += RBtree.IsKey(ins_50000[i]);
		else if (count == 100000) cnt += RBtree.IsKey(ins_100000[i]);
	}
	return cnt / 100;
}
int ST_Search(int count) {
	Splay splayT(a[0]);
	for (int i = 1; i < count; i++) {
		//cout << i << " ";
		splayT.insertItem(a[i]);
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		if (count == 1000) cnt += splayT.findElement(ins_1000[i]);
		else if (count == 5000) cnt += splayT.findElement(ins_5000[i]);
		else if (count == 10000) cnt += splayT.findElement(ins_10000[i]);
		else if (count == 50000) cnt += splayT.findElement(ins_50000[i]);
		else if (count == 100000) cnt += splayT.findElement(ins_100000[i]);
	}
	return cnt / 100;
}
int Treaps_Search(int count) {
	TreapNod* root = nullptr;
	for (int i = 1; i < count; i++) {
		//cout << i << " ";
		insertNod(root, a[i]);
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		if (count == 1000) cnt += searchNod(root, ins_1000[i]);
		else if (count == 5000) cnt += searchNod(root, ins_5000[i]);
		else if (count == 10000) cnt += searchNod(root, ins_10000[i]);
		else if (count == 50000) cnt += searchNod(root, ins_50000[i]);
		else if (count == 100000) cnt += searchNod(root, ins_100000[i]);
	}
	return cnt / 100;
}
void search_compare(int data_size) {
	cout << "<������ "<<data_size<<"��>" << endl;
	cout << "B.S.T�� ��� Ž�� Ƚ�� : " << BST_Search(data_size) << endl;
	cout << "AVL Tree�� ��� Ž�� Ƚ�� : " << AVL_Search(data_size) << endl;
	cout << "Red-Black Tree�� ��� Ž�� Ƚ�� : " << RBT_Search(data_size) << endl;
	cout << "Splay Tree�� ��� Ž�� Ƚ�� : " << ST_Search(data_size) << endl;
	cout << "Treaps�� ��� Ž�� Ƚ�� : " << Treaps_Search(data_size) << endl << endl;
}
int main() {
    random_generate();
	search_compare(1000);
	search_compare(5000);
	search_compare(10000);
	search_compare(50000);
	search_compare(100000);
    return 0;
}
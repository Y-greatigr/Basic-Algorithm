#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <ctime>

using namespace std;
vector<int> a(100'000); // 100,000 크기의 난수 데이터를 담을 가변길이 벡터 a 선언
vector<int> ins_1000(100); // 1,000개 데이터에 대한 100가지 인스턴스를 담을 가변길이 벡터 선언
vector<int> ins_5000(100); // 5,000개 데이터에 대한 100가지 인스턴스를 담을 가변길이 벡터 선언
vector<int> ins_10000(100); // 10,000개 데이터에 대한 100가지 인스턴스를 담을 가변길이 벡터 선언
vector<int> ins_50000(100); // 50,000개 데이터에 대한 100가지 인스턴스를 담을 가변길이 벡터 선언
vector<int> ins_100000(100); // 100,000개 데이터에 대한 100가지 인스턴스를 담을 가변길이 벡터 선언

void random_generate() {
    random_device rd;    // 시드값을 얻기 위한 random_device 생성.
    mt19937 gen(rd());  // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    uniform_int_distribution<int> dis(0, 10'000'000);    // 0 부터 10,000,000 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis_1(0, 999);    // 0 부터 999 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis_2(0, 4'999);    // 0 부터 4,999 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis_3(0, 9'999);    // 0 부터 9,999 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis_4(0, 49'999);    // 0 부터 49,999 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis_5(0, 99'999);    // 0 부터 99,999 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.


    for (int i = 0; i < 100'000; i++) a[i] = dis(gen);      // 0 부터 10,000,000 사이에서 생성된 난수 100,000개 삽입
    for (int i = 0; i < 100; i++) ins_1000[i] = a[dis_1(gen)];  // 1,000개 데이터에 대한 100가지 임의의 인스턴스 삽입
    for (int i = 0; i < 100; i++) ins_5000[i] = a[dis_2(gen)];  // 5,000개 데이터에 대한 100가지 인스턴스 삽입
    for (int i = 0; i < 100; i++) ins_10000[i] = a[dis_3(gen)];    // 10,000개 데이터에 대한 100가지 인스턴스 삽입
    for (int i = 0; i < 100; i++) ins_50000[i] = a[dis_4(gen)];    // 50,000개 데이터에 대한 100가지 인스턴스 삽입
    for (int i = 0; i < 100; i++) ins_100000[i] = a[dis_5(gen)];  // 100,000개 데이터에 대한 100가지 인스턴스 삽입
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
	cout << _value << " 값을 찾지 못했습니다." << endl;
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

		//넣을 위치에 대입 
		if (node->value < tmpRoot->value) tmpRoot->left = node;
		else tmpRoot->right = node;
	}
}
// 노드 구조체를 정의합니다.
struct nodeAVL
{
	int data;
	struct nodeAVL* left;
	struct nodeAVL* right;
} *root;

// 클래스를 정의합니다.
class classAVL
{
public:
	// 노드의 높이를 반환합니다.
	int height(nodeAVL*);
	// 균형인수(높이의 차이)를 반환합니다.
	int diff(nodeAVL*);
	// RR 회전 함수입니다.
	nodeAVL* rr(nodeAVL*);
	// LL 회전 함수입니다.
	nodeAVL* ll(nodeAVL*);
	// LR 회전 함수입니다.
	nodeAVL* lr(nodeAVL*);
	// RL 회전 함수입니다.
	nodeAVL* rl(nodeAVL*);
	// 트리의 균형을 맞추는 함수입니다.
	nodeAVL* balance(nodeAVL*);
	// AVL 트리에 새로운 원소를 삽입합니다.
	nodeAVL* insert(nodeAVL*, int);
	// 현재의 AVL 트리 내용을 보여주는 함수입니다.
	int search_AVL(nodeAVL*, int);
	// AVL 트리의 키값을 찾아주는 함수입니다.
	classAVL()
	{
		root = NULL;
	}
};
// AVL 트리의 높이를 출력합니다.
int classAVL::height(nodeAVL* temp)
{
	int h = 0;
	if (temp != NULL)
	{
		// 재귀적으로 왼쪽 혹은 오른쪽으로 검색합니다.
		int left = height(temp->left);
		int right = height(temp->right);
		int maxHeight = max(left, right);
		h = maxHeight + 1;
	}
	return h;
}

// 균형인수(높이의 차이)를 반환합니다.
int classAVL::diff(nodeAVL* temp)
{
	// 왼쪽 자식의 높이와 오른쪽 자식의 높이 차이를 반환합니다.
	int left = height(temp->left);
	int right = height(temp->right);
	int factor = left - right;
	return factor;
}

// RR 회전 함수입니다.
nodeAVL* classAVL::rr(nodeAVL* parent)
{
	// 말이 회전이지 그냥 부모 노드의 오른쪽 자식노드와 데이터를 교환하는 것입니다.
	nodeAVL* temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

// ll 회전 함수입니다.
nodeAVL* classAVL::ll(nodeAVL* parent)
{
	// RR 회전과 반대입니다.
	nodeAVL* temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

// LR 회전 함수입니다.
nodeAVL* classAVL::lr(nodeAVL* parent)
{
	// LR 회전은 왼쪽 자식을 기준으로 RR, 본인을 기준으로 LL회전합니다.
	nodeAVL* temp;
	temp = parent->left;
	parent->left = rr(temp);
	return ll(parent);
}

// RL 회전 함수입니다.
nodeAVL* classAVL::rl(nodeAVL* parent)
{
	// LR 회전과 반대입니다.
	nodeAVL* temp;
	temp = parent->right;
	parent->right = ll(temp);
	return rr(parent);
}

// AVL 트리의 균형을 맞추는 함수입니다.
nodeAVL* classAVL::balance(nodeAVL* temp)
{
	int factor = diff(temp);
	// 왼쪽 서브트리쪽으로 삽입이 되어 균형이 깨진 경우입니다.
	if (factor > 1)
	{
		// 그 왼쪽 자식노드에 문제가 발생했습니다.
		if (diff(temp->left) > 0)
		{
			temp = ll(temp);
		}
		// 그 오른쪽 자식 노드에 문제가 발생했습니다.
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

// 트리에 원소를 삽입하는 함수입니다.
nodeAVL* classAVL::insert(nodeAVL* root, int value)
{
	// 현재 트리가 비었을 때
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
	// 크거나 같은 경우 오른쪽 서브트리에 삽입합니다.
	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
		root = balance(root);
	}
	return root;
}

// 트리의 원소를 찾아주는 함수입니다.
int classAVL::search_AVL(nodeAVL* root, int value)
{
	//지나가는 경로를 큐에 저장하고 순차적으로 출력
	nodeAVL* ptr = root;
	bool find = false;
	int cnt = 0;
	if (value == root->data) //root의 데이터를 찾을 경우
	{
		return cnt;
	}
	while (ptr && value != root->data) //root가 아닌 노드의 데이터를 찾는 경우
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
	cout << "찾으시는 데이터가 없습니다" << endl;
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
	NodePtr root;     //루트 노드
	NodePtr leafNode; //단말노드

	void InsertFixUp(NodePtr z)
	{
		/*root 노드가 아니고 부모 색이 red라면*/
		while (z != root && z->parent->color == RED)
		{
			NodePtr grandparent = z->parent->parent;
			NodePtr uncle = (z->parent == grandparent->left) ? grandparent->right : grandparent->left;
			bool side = (z->parent == grandparent->left) ? true : false; //if p[z]가 p[p[z]]의 왼쪽 자식이면 1 / 오른쪽이면 0

			/*case 1*/
			if (uncle && uncle->color == RED)
			{
				z->parent->color = BLACK;
				uncle->color = BLACK;
				grandparent->color = RED;
				z = grandparent;
			}

			/*case 2
				side == true ) p[z]는 p[p[z]]의 왼쪽 자식 인 경우이다.
				side == false ) p[z]는 p[p[z]]의 오른쪽 자식 인 경우이다. */
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

	/*x를 중심으로 왼쪽으로 회전*/
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
	/*x를 중심으로 오른쪽으로 회전*/
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
	//key값이 있는지 없는지 검사 있으면 pointer 값, 없으면 nullptr
	int IsKey(int item)
	{
		NodePtr t = root;
		NodePtr parent = NULL;

		int cnt = 0;
		/*key값을 찾거나 없다면 break*/
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
		// x : 삽입할 곳 찾기위한 포인터 | y : 삽입할 곳의 부모노드
		NodePtr x = this->root, y = nullptr;
		NodePtr z = new node();
		z->key = item;
		z->color = RED;
		z->parent = nullptr;
		z->left = leafNode;
		z->right = leafNode;

		/*BST의 일반 삽입 연산*/
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

		//z가 root노드라면
		if (z->parent == nullptr)
		{
			z->color = BLACK;
			return;
		}
		// z의 부모노드가 root노드라면 Fix Up 필요없이 red컬러로 붙여주면 된다.
		if (z->parent->parent == nullptr)
		{
			return;
		}
		InsertFixUp(z);

		return;
	}
};
// 노드 정보
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

	// 핵심 매서드
	void insertItem(int element);
	int findElement(int element);
	Node_ST* treeSearch(Node_ST* now, int element);

	// 트리 기본 매서드
	void expand(Node_ST* external, int element);
	int depth(Node_ST* now);
	int height(Node_ST* now);

	// Splay 트리 매서드
	void doSplay(Node_ST* now);

	// rotate
	void rightRotate(Node_ST* x, Node_ST* y);
	void leftRotate(Node_ST* x, Node_ST* y);

	// 트리 boolean 매서드
	bool isRoot(Node_ST* tmp);
	bool isExternal(Node_ST* tmp);

	// get
	Node_ST* getRoot();
};

// 생성자
Splay::Splay() {}

// 루트 초기화 생성자
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
** 핵심 메서드
*/
// 노드 삽입
void Splay::insertItem(int element) {
	Node_ST* tmp = treeSearch(root, element);

	if (isExternal(tmp)) {
		expand(tmp, element);
		doSplay(tmp);
	}
}

// 사전 검색
int Splay::findElement(int element) {
	Node_ST* tmp = root;
	Node_ST* parent = NULL;
	int cnt = 0;
	/*key값을 찾거나 없다면 break*/
	while (tmp != NULL && tmp->data != element)
	{
		parent = tmp;
		tmp = (element < parent->data) ? parent->leftc : parent->rightc;
		cnt++;
	}
	return cnt;
}

// 트리 검색
// 원소의 위치를 반환
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
** 트리 기본 매서드
*/
// 내부 노드로 확장
void Splay::expand(Node_ST* external, int element) {
	external->data = element;
	external->leftc = new Node_ST;
	external->rightc = new Node_ST;

	external->leftc->parent = external;
	external->rightc->parent = external;
}

// 깊이를 반환
int Splay::depth(Node_ST* now) {
	int ret = 0;

	while (!isRoot(now)) {
		now = now->parent;
		++ret;
	}

	return ret;
}

// 노드의 높이를 반환
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
** Splay 트리  매서드
*/
void Splay::doSplay(Node_ST* now) {
	// 예외처리
	if (now == nullptr) return;

	// 루트에 도착하면 종료
	if (isRoot(now)) {
		root = now;
		return;
	}

	// 부모가 루트인가?
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

	// 나머지 경우
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
** 트리 boolean 매서드
*/
// 루트인가?
bool Splay::isRoot(Node_ST* tmp) {
	return tmp->parent == nullptr;
}

// 외부 노드인가?
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
	/*key값을 찾거나 없다면 break*/
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
	cout << "<데이터 "<<data_size<<"개>" << endl;
	cout << "B.S.T의 평균 탐색 횟수 : " << BST_Search(data_size) << endl;
	cout << "AVL Tree의 평균 탐색 횟수 : " << AVL_Search(data_size) << endl;
	cout << "Red-Black Tree의 평균 탐색 횟수 : " << RBT_Search(data_size) << endl;
	cout << "Splay Tree의 평균 탐색 횟수 : " << ST_Search(data_size) << endl;
	cout << "Treaps의 평균 탐색 횟수 : " << Treaps_Search(data_size) << endl << endl;
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
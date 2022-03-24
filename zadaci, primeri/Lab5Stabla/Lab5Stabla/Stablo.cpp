#include "Stablo.h"


int Stablo::nivoMax(Node* p)
{
	return 0;
}

void Stablo::insertNoBTS(int value,Node* p) //Radi
{
	Node* tmp = new Node(value);
	if (p == root && p==NULL)
		root = tmp;
	else if (p->left == NULL)
		p->left = tmp;
	else if (p->right == NULL)
		p->right = tmp;
	else if (p->left!=NULL)
		insertNoBTS(value, p->left);
	else if (p->right!=NULL)
		insertNoBTS(value, p->right);
}

void Stablo::insert(int d)
{
	Node* pom = root;
	Node* prev = NULL;
	Node* p = new Node(d);
	while (pom)
	{
		prev = pom;
		if (pom->data < d)
			pom = pom->right;
		else
			pom = pom->left;
	}
	if (root == NULL)
		root = p;
	else if (prev->data < d)
		prev->right = p;
	else
		prev->left = p;
	numberOfElements++;

}

void Stablo::print(Node* p)
{
	if (p)
	{
		p->visit();
		print(p->left);
		print(p->right);
	}
}

Stablo* Stablo::sortedArrayToBTS(int a[], int n)
{
	Stablo* pom = new Stablo();
	int indm = 0;
	int k = 0;
	if (n % 2 != 0)
	{
		indm = n / 2;
		k = a[indm];
	}
	else
	{
		indm = n / 2 + 1;
		k = a[indm];
	}
	pom->insert(k);
	int j = indm + 1;
	int i = indm - 1;
	while (i >= 0)
	{
		pom->insert(a[i]);
		i--;
	}
	while (j < n)
	{
		pom->insert(a[j]);
		j++;
	}
	return pom;
}

int Stablo::prebrojiLeve(Node* node) {
	int sum = 0;
	if (node->left != NULL)
		sum += 1 + prebrojiLeve(node->left);

	if (node->right != NULL)
		sum += prebrojiLeve(node->right);
	return sum;
}

bool Stablo::isBTS(Node* p) //Radi
{
	if (p == NULL)
		return true;
	if (p->left != NULL && p->left->data > p->data)
		return false;
	if (p->right != NULL && p->right->data < p->data)
		return false;
	if (!isBTS(p->left) || !isBTS(p->right))
		return false;
	return true;
}

bool Stablo::search(Node* p, int value, Node* smesti)
{
	if (p)
	{
		if (p->data == value)
		{
			smesti = p;
			return true;
		}
		if (p->data > value)
		{
			if (p->left==NULL)
				return false;
			search(p->left, value, smesti);
		}
		else
		{
			if (p->right==NULL)
				return false;
			search(p->right, value, smesti);
		}
	}
	
}


int Stablo::brojEl(Node* p)  //Radi
{
	int br=0;
	if (p)
	{
		br++;
		br = br + brojEl(p->left);
		br = br + brojEl(p->right);
	}
	return br;
}

void Stablo::popuniNiz(Node*  p)
{
	if (p)
	{
		niz[trenutno++] = p->data;
		popuniNiz(p->left);
		popuniNiz(p->right);
	}
}

void Stablo::napraviNiz()
{
	niz = new int[brojEl(root)];
	popuniNiz(root);
}

void Stablo::deleteAll(Node* p)
{
	if (p!=NULL)
	{
		deleteAll(p->left);
		deleteAll(p->right);
		delete p;
		p=NULL;
	}
}

int Stablo::brojRazlicitih()
{
	napraviNiz();
	int br=0;
	int ponavlja;
	for (int i = 0; i < trenutno; i++)
	{
		ponavlja = 0;
		for (int j = 0; j < trenutno; j++)
		{
			if (j != i)
			{
				if (niz[i] == niz[j])
					ponavlja++;
			}
		}
		if (ponavlja == 0)
			br++;
	}
	return br;
}

int Stablo::findMin()
{
	if (root == NULL)
		throw "Prazno stablo";
	Node* current = root;
	while (current->left)
		current = current->left;
	return current->data;
}


int Stablo::findMax()
{
	if (root == NULL)
		throw "Prazno stablo";
	Node* current = root;
	while (current->right)
		current = current->right;
	return current->data;
}

int Stablo::findMinRec(Node* root)
{
	if (root == NULL)
		throw "Prazno stablo";
	else if (root->left == NULL)
		return root->data;
	return findMinRec(root->left);
}


int Stablo::findMaxRec(Node* root)
{
	if (root == NULL)
		throw "Prazno stablo";
	else if (root->right == NULL)
		return root->data;
	return findMaxRec(root->right);
}

int Stablo::findHight(Node* root)
{
	if (root == NULL)
		return -1;
	int leftHight = findHight(root->left);
	int rightHight = findHight(root->right);
	int max = leftHight;
	if (max < rightHight)
		max = rightHight;
	return max + 1;

}

int Stablo::tezina(Node* p)
{
	if (p == NULL)
		return 0;
	if (p->left == NULL && p->right == NULL)
		return 1;
	return tezina(p->left) + tezina(p->right);
}

Stablo::~Stablo()
{
}

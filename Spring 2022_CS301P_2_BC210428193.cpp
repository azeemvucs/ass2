#include<iostream>
using namespace std;

class Heap{
	private:
		int currentSize;
		int* array;
		int capacity;
	
	public:
		Heap(int capacity = 100)
		{
			array = new int [capacity+1];
			currentSize = 0;
		}
		void insert(const int &x)
		{
			if(isFull())
			{
				cout<<"Heap is Full"<<endl;
				return ;
			}
			int hole = ++currentSize;
			for(;hole>1 && x< array[hole/2]; hole/=2)
			{
				array[hole] = array[hole/2];
			}
			array[hole] = x;
		}
		void traverse()
		{
			for(int i=1; i<=currentSize; i++)
			{
				cout<<array[i]<<",";
			}
		}
		
		bool isEmpty()
		{
			return currentSize == 0;
		}
		
		bool isFull()
		{
			return currentSize == capacity;
			
		}

};

class BSTNode
{
	private:
		int* object;
		BSTNode* left;
		BSTNode* right;
	public:
		BSTNode()
		{
			this->object = NULL;
			this->left = this->right = NULL;
		}
		BSTNode(int* object)
		{
			this->object = object;
			this->left = this->right = NULL;
		}
		int* getInfo()
		{
			return this->object;
		}
		void setInfo(int* object)
		{
			this->object = object;
		}
		BSTNode* getLeft()
		{
			return left;
		}
		void setLeft(BSTNode* left)
		{
			this->left = left;
		}
		BSTNode* setRight()
		{
			return right;
		}
		void setRight(BSTNode* right)
		{
			this->right = right;
		}
};

BSTNode* root = new BSTNode();
Heap* h = new Heap();

void insert(BSTNode* root, int* info)
{
	BSTNode* node = new BSTNode(info);
	BSTNode * p, * q;
	p = q = root;
	while(*info !=*(p->getInfo()) && q!= NULL)
	{
		p = q;
		if(*info<*(p->getInfo()))
		{
			q = p->getLeft();
		}else{
			q = p->setRight();
		}
	}
	if(*info == *(p->getInfo()))
	{
		cout<<"Duplicate Vale";
		delete node;
	}else if(*info < *(p->getInfo())){
		p->setLeft(node);
	}else{
		p->setRight(node);
	}
}

void builtTree(int x[])
{
	root->setInfo(&x[0]);
	for(int i=1;x[i]>0;i++)
	{
		insert(root, &x[i]);
	}
}

void inorder(BSTNode* bstNode)
{
	if(bstNode!=NULL)
	{
		inorder(bstNode->getLeft());
		cout<<*(bstNode->getInfo())<<" ";
		h->insert(*(bstNode->getInfo()));
		inorder(bstNode->setRight());
	}
}
int main()
{
	int x[] = {18, 31, 82, 85, 37, 20, 23, 79, 47};
	builtTree(x);
	cout<<"In-Order Traversal of BST:";
	inorder(root);
	cout<<endl<<"Min - Heap:";
	h->traverse();
}

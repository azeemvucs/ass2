#include <iostream>
using namespace std;


class Heap{
    private:
         int currentSize;
         int* array;
         int capacity;
         
    public:
    //Now we will work on heap. Ok!
        Heap(){
        }
        Heap(int size){
            capacity = size;
            array = new int[capacity+1];
            currentSize = 0;
        }
        // insert starts here.
        
        bool insert(const int x){
            if(isFull()){
                cout<<"\nHeap is full...."<<endl;
                return 0;
            }
            currentSize = currentSize + 1;     
            int hole = currentSize;             /*           hole = hole / 2                 */
            /*for(hole; (hole > 1)&&(x < array[hole/2]); hole /= 2){
                array[hole] = array[hole / 2];
            }*/
            array[currentSize] = x;
        //that is the "insert" routine of heap.
        return 1;
        }
        bool isEmpty(){
            return currentSize == 0;
        }
        bool isFull(){
            return currentSize == capacity;
        }
        //
        //
        
        bool traverse(){
            if(isEmpty()){
                cout<<"\nHeap is Empty...."<<endl;
                return 0;
            }
            cout<<array[1]<<" ";
            currentSize--;
                // here we are deploying perculateDown to traverse the Heap in "Ascending Order". Ok!
                int hole;
				int child;
                //int temp = array[hole];
                for(hole = 1; hole*2 < currentSize+1; hole = child){
                    if(array[hole*2] < array[(hole*2)+1]){
                    	child = hole * 2;
					}
					// if (array[hole*2] > array[(hole*2)+1])
					else if (array[hole*2] > array[(hole*2)+1]){
						child = (hole * 2)+ 1;
					}
                    array[hole] = array[child];
                }
                array[hole] = array[hole+1];
                array[hole+1] = array[hole+2];
        // Now the traverse method finishes.
        return 1;
        }
};


/*                         void _func(int g= 0){
	                        cout<<endl<<g;
                            }
*/
class BSTNode{
	private:
		int *object;
		BSTNode *Left;
		BSTNode *Right;
	public:
		// default constructor no 1
		BSTNode(){
			object = NULL;
			Left= NULL;
			Right= NULL;
		}
		// constructor no 2
		BSTNode(int *obj){
			object= obj;
			Left= NULL;
			Right= NULL;
		}
		// house keeping destructor ' always 1' as usual.
		~BSTNode(){
			//Destructor: House keeping.
			delete Left;
			delete Right;
		}
// getter functions for private data members.
		int* getObject()const{
			return object;
		}
		BSTNode* getLeft()const{
			return Left;
		}
		BSTNode* getRight()const{
			return Right;
		}
// setter functions for private member functions.
        void setObject(int *n){
        	object = n;
		}
		void setLeft(BSTNode *l){
			Left= l;
		}
		void setRight(BSTNode *r){
			Right= r;
		}
};

void inorder(BSTNode *tree, Heap &heap){
			if(tree != NULL){
				// Order (Left, root, Right).
				inorder(tree->getLeft(), heap);
				cout<<*tree->getObject()<<" ";
				heap.insert(*tree->getObject());
				inorder(tree->getRight(), heap);
			}
		}

void insertNode(BSTNode *he, int &m){
	// memory allocation from heap.
	BSTNode *tree= new BSTNode();
	// pointers to move in the required BSTNode.
	BSTNode *p= NULL;
	BSTNode *q= NULL;
// assigning value to tree with setter functions.
	tree->setObject(&m);
	tree->setLeft(NULL);
	tree->setRight(NULL);
	
//
		p = q = he;
		/*if((he == NULL))
		he= tree;
		else if(he != NULL){
			// if q != NULL. continue 'while' loop.*/
			while(q != NULL){
				p =q;
				if(*tree->getObject() < *p->getObject()){
					q= p->getLeft();
					if(q == NULL)
					p->setLeft(tree);
				}
				else if(*tree->getObject() > *p->getObject()){
					q= p->getRight();
					if(q == NULL)
					p->setRight(tree);
				}
			}
	}
void buildTree(BSTNode *he, int arr[], int &m){
    for(int i=1; i < m; i++){
    // memory allocation from heap.
	BSTNode *tree= new BSTNode();
	// pointers to move in the required BSTNode.
	BSTNode *p= NULL;
	BSTNode *q= NULL;
// assigning value to tree with setter functions.
	tree->setObject(&arr[i]);
	tree->setLeft(NULL);
	tree->setRight(NULL);
	
//
		p = q = he;
		/*if((he == NULL))
		he= tree;
		else if(he != NULL){
			// if q != NULL. continue 'while' loop.*/
			while(q != NULL){
				p =q;
				if(*tree->getObject() < *p->getObject()){
					q= p->getLeft();
					if(q == NULL)
					p->setLeft(tree);
				}
				else if(*tree->getObject() > *p->getObject()){
					q= p->getRight();
					if(q == NULL)
					p->setRight(tree);
				}
			}
    }
}



int main(){
	int Data[]= {18, 31, 82, 85, 37, 20, 23, 79, 47};
	// making BSTNode with pointer.
	BSTNode *male= new BSTNode(&Data[0]);
	int element= sizeof(Data)/sizeof(int);
	Heap hp(element);

	
	    		for(int i=1; i < element; i++){
	    			insertNode(male, Data[i]);
				}
				cout<<"In-Order Traversal of BST: ";
			    inorder(male, hp);
			    cout<<endl;
			    cout<<"Min Heap constructed using inorder traversal of BST: ";
			    for(int i=0; i < element; i++){
	    			hp.traverse();
				}
			    cout<<endl;

/*
*/
//Destructors called.
/*
*/
	// freeing memeory allocated from heap.
	delete male;
	male = NULL;
	return 0;
}
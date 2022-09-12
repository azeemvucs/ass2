/*my name is Tabassum Arshad
my student id bc210428195*/ 



#include <iostream>
using namespace std;


class Heap{
    private:
         int currentSize;
         int* array;
         int capacity;
         
    public:
    
        Heap(){
        }
        Heap(int size){
            capacity = size;
            array = new int[capacity+1];
            currentSize = 0;
        }
    
        
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
        
        
        bool traverse(){
            if(isEmpty()){
                cout<<"\nHeap is Empty...."<<endl;
                return 0;
            }
            cout<<array[1]<<" ";
            currentSize--;
                
                int hole;
				int child;
                
                for(hole = 1; hole*2 < currentSize+1; hole = child){
                    if(array[hole*2] < array[(hole*2)+1]){
                    	child = hole * 2;
					}
				
					else if (array[hole*2] > array[(hole*2)+1]){
						child = (hole * 2)+ 1;
					}
                    array[hole] = array[child];
                }
                array[hole] = array[hole+1];
                array[hole+1] = array[hole+2];
       
        return 1;
        }
};


                     


class BSTNode{
	private:
		int *object;
		BSTNode *Left;
		BSTNode *Right;
	public:
		
		BSTNode(){
			object = NULL;
			Left= NULL;
			Right= NULL;
		}
		
		BSTNode(int *obj){
			object= obj;
			Left= NULL;
			Right= NULL;
		}
		
		~BSTNode(){
			
			delete Left;
			delete Right;
		}

		int* getObject()const{
			return object;
		}
		BSTNode* getLeft()const{
			return Left;
		}
		BSTNode* getRight()const{
			return Right;
		}

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
				
				inorder(tree->getLeft(), heap);
				cout<<*tree->getObject()<<" ";
				heap.insert(*tree->getObject());
				inorder(tree->getRight(), heap);
			}
		}

void insertNode(BSTNode *he, int &m){
	
	BSTNode *tree= new BSTNode();
	
	BSTNode *p= NULL;
	BSTNode *q= NULL;

	tree->setObject(&m);
	tree->setLeft(NULL);
	tree->setRight(NULL);
	

		p = q = he;
	
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
   
	BSTNode *tree= new BSTNode();

	BSTNode *p= NULL;
	BSTNode *q= NULL;

	tree->setObject(&arr[i]);
	tree->setLeft(NULL);
	tree->setRight(NULL);
	

		p = q = he;
	
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


	delete male;
	male = NULL;

	return 0;
}






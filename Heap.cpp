// ------- Heap class [insertion, deletion, Heapsort] -------
// complexity of insertion single element : O(logn)
// complexity of insertion of n elements in heap : O(nlogn)
#include <iostream>
#include <cmath>

using namespace std ;

class Heap {
    private :
      int *Arr ;
      int length ; // Total capacity 
      int size ;   // current length after deletions == capacity - size can be used to store deleted elements for heap sort
    public :
      Heap() {
          length = 0 ;
      }
      //---- Working Functions ----
      void getElements() ;
      void form_Max_Heap() ;
      void form_Min_Heap() ;
      void insert_MaxHeap(int index) ;
      void insert_MinHeap(int index) ;
      void delete_Maxheap() ;
      void delete_Minheap() ;
      void display() ;
      void Heapsort_Max() ;
      
      ~Heap() {
          delete []Arr ;
      }
};

void Heap::getElements() {
    cout<<"Enter no of elements "<<endl ; 
    cin>>length ;
    this -> size = length ;
    Arr = new int[length+1] ; // to accomodate index from 1 to length
    for(int i = 1 ; i <= length ; i++) {
        cout<<"Enter data "<<i<<" : ";
        cin>>Arr[i];
    }
    cout<<"---- Elements Inserted ----\n\n"<<endl;
}

void Heap::form_Max_Heap() {
    for(int i = 2 ; i <= length ; i++) {
        insert_MaxHeap(i) ;
    }
}

void Heap::insert_MaxHeap(int index) {
    int temp , i = index ;
    temp = Arr[i] ;
    while (i>1 && temp>Arr[i/2]) {
        Arr[i] = Arr[i/2] ;
        i /= 2 ;
    }
    Arr[i] = temp ;
}

void Heap::form_Min_Heap() {
    for(int i = 2 ; i <= length ; i++) {
        insert_MinHeap(i) ;
    }
}

void Heap::insert_MinHeap(int index) {
    int temp , i = index ;
    temp = Arr[i] ;
    while (i>1 && temp<Arr[i/2]) {
        Arr[i] = Arr[i/2] ;
        i /= 2 ;
    }
    Arr[i] = temp ;
}

void Heap::delete_Maxheap() {
    int x , i , j ;
    x = Arr[1] ;
    Arr[1] = Arr[size] ;
    Arr[size] = x ;
    i = 1 ;
    j = 2*i ;
    while ( j <= size - 1 ) {
        if (j < size - 1 && Arr[j+1] > Arr[j]) {
            j += 1 ;
        }
        if (Arr[i] < Arr[j]) {
            int var = Arr[i] ;
            Arr[i]  = Arr[j] ;
            Arr[j]  = var ;
            i = j ;
            j = 2*j ;
        }
        else {
            break ;
        }
    }
    size -- ;
} 

void Heap::Heapsort_Max() {
    for(int i = 1 ; i <= length ; i++) {
        delete_Maxheap() ;
    }
    cout<<"Heapsort_Max : ";
    for(int i = 1 ; i <= length ; i++) {
        cout<<Arr[i]<<"  ";
    }cout<<endl ;
}

void Heap::display() {
    for(int i = 1 ; i <= size ; i++) {
        cout<<Arr[i]<<"   ";
    }cout<<endl;
}

int main(void) {
    Heap H ;
    H.getElements() ;
    cout<<"Inserted elements : ";H.display() ;
    H.form_Max_Heap() ;
    cout<<"Max Heap : ";H.display() ;
    H.Heapsort_Max() ;
    
    return 0 ;
}


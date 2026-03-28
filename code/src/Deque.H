#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Node.H"

//class deque
template <typename T>
class Deque {
protected:
    Node<T>* mFrontPtr;
    Node<T>* mRearPtr;
    int mSize;


    bool pIsSingle() {
        return ((mFrontPtr!=NULL) && mFrontPtr == mRearPtr);
    }
public:
    Deque() ;//constructor for empty deque
    Deque(int n, T val) ;//constructor for deque with default values
    virtual int processDeque();
    void pushBack(T valParam);
    void pushFront(T valParam) ;
    void popFront() ;
    void popBack() ;
    T front() ;
    T back() ;
    int get_size();
    bool isempty();//checks whether the DQ is empty or not, returns true if empty
    void clear() ;
    void reSize(int newSizeParam,int sDir,T sDef = T());
    void display() ;
    T operator[](int indexParam);//operator [] overloaded to replicate array like element access in the DQ 
    virtual ~Deque();
};

template <typename T>
Deque<T> :: Deque() {
    mFrontPtr = mRearPtr = nullptr;
    mSize = 0;
    cout << "Deque created (empty)\n";
}

template <typename T>
Deque<T> :: Deque(int n, T val) {
        mFrontPtr = mRearPtr = nullptr;
        mSize = 0;
        cout << "Deque created with " << n << " elements\n";
        for (int i = 0; i < n; i++)
            pushBack(val);  
}

template <typename T>
Deque<T> :: ~Deque() {
    cout<<"Deque Destructor called";
    clear();
}

template <typename T>
void Deque<T> :: pushBack(T valParam) {  
    Node<T>* node = new Node<T>(valParam);
    if (!mRearPtr) {//last node 
        mFrontPtr = mRearPtr = node;
    } else {
        mRearPtr->mNext = node;
        node->mPrev = mRearPtr;
        mRearPtr = node;
    }
    mSize++;
}

template <typename T>
void Deque<T> :: pushFront(T valParam) {
    Node<T>* node = new Node<T>(valParam);
    if (!mFrontPtr) {//first node
        mFrontPtr = mRearPtr = node;
    } else {
        node->mNext = mFrontPtr;
        mFrontPtr->mPrev = node;
        mFrontPtr = node;
    }
    mSize++;
}

template <typename T>
void Deque<T> :: popFront() {
    if (!mFrontPtr){//if empty
        return;
    }
    Node<T>* sTemp = mFrontPtr;
    if (pIsSingle()) {//if single node 
        mFrontPtr = mRearPtr = nullptr;
    } 
    else {
        mFrontPtr = mFrontPtr->mNext;
        mFrontPtr->mPrev = nullptr;
    }
    delete sTemp;
    mSize--;
}

template <typename T>
void Deque<T> :: popBack() {
    if (!mRearPtr){
        return;
    } 

    Node<T>* sTemp = mRearPtr;

    if (pIsSingle()) {
        mFrontPtr = mRearPtr = nullptr;
    } 
    else {
        mRearPtr = mRearPtr->mPrev;
        mRearPtr->mNext = nullptr;
    }
    delete sTemp;
    mSize--;
}

template <typename T>
int Deque<T> :: processDeque(){
        cout<<"\nDefault processDeque Funtion\n";
        return 0;
}    

template <typename T>
T Deque<T> :: front() {
    if(mSize==0){
        cout<<"size is zero \n";
        return T();
    } 
    return mFrontPtr->mData; 
}

template <typename T>
T Deque<T> :: back() {
    if(mSize==0){
        cout<<"size is  zero \n";
        return T();
    } 
        return mRearPtr->mData;
}

template <typename T>
int Deque<T> :: get_size() {
    return mSize; 
}

template <typename T>
bool Deque<T> :: isempty() { 
    return mSize == 0; 
}

template <typename T>
void Deque<T> :: clear() {
    while (!isempty()){
        popFront();
    } 
}

template <typename T>
void Deque<T> :: reSize(int newSizeParam, int sDirParam, T sDefValueParam) {

    if (newSizeParam > mSize) {
        while (mSize < newSizeParam) {//if dq grows then fill the new nodes with default values
            (sDirParam == 1) ? pushBack(sDefValueParam) : pushFront(sDefValueParam);
        }
    } else {
        while (mSize > newSizeParam) {//if dq shrinkls then remove the elements from either of the end acc to the user input
            (sDirParam == 1) ? popBack() : popFront();
        }
    }
}

template <typename T>
void Deque<T> :: display() {
    if(mSize==0){
        return;
    }
    Node<T>* sTemp = mFrontPtr;
    cout << "Deque: ";
    while (sTemp) {
        cout << sTemp->mData << " <-> ";
        sTemp = sTemp->mNext;
    }
    cout << "NULL\nSize: " << mSize << endl;
}

template <typename T>
T Deque<T> :: operator[](int indexParam){//[]operator overloading function 

    if(mSize<=0){
        cout<<"the size is zero : ";
        return T();
    }
    if(indexParam >= mSize){
        return T();
    }

    if(indexParam==(mSize-1)){
            T sNthvalue =  back();
            return sNthvalue;
    }
    else if(indexParam<=(mSize/2)){//traverse from front
        Node<T>* sTemp = mFrontPtr;
        int i=0;
        for(i=1;i<=(indexParam);i++){
            sTemp = sTemp->mNext;
        }
        T sNthvalue = sTemp->mData;
        return sNthvalue;
    }
    else if(indexParam>(mSize/2)){//traverse from back
        Node<T>* sTemp = mRearPtr;
        int i=(mSize-1);
        for(int j=0;j<=(i-indexParam-1);j++){
            //Traverse from n-1th node.
            sTemp = sTemp->mPrev;
        }
        T nthvalue = sTemp->mData;
        return nthvalue;
    }
    else{
        cout<<"\nUnknown state in D[n] Method \n";
        return T();
    }
}

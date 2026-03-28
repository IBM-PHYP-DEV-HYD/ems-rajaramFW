
#include"Deque.H"
#include <string>

template <typename T>
class ExtendedDeque : public Deque<T>{
public:
    ExtendedDeque(){}
    ~ExtendedDeque(){}

    bool insertElement(uint32_t indexParm, T valParam);
    bool removeElement(uint32_t indexParm);
};

template <typename T>
bool ExtendedDeque<T>::insertElement(uint32_t indexParm, T valParam)//indexParm should start at zero
{
    if(this->mSize<=0){
        cout<<"the size is zero : ";
        return T();
    }
    if(indexParm >= this->mSize){
        return false;
    }

    if(indexParm==(this->mSize-1)){
        this->pushBack(valParam);//last element 
        return true;
    }
    else if(indexParm==0){
        this->pushFront(valParam);//first element 
        return true;
    }
    else if(indexParm <= (this->mSize/2))
    {
        Node<T>* sTemp = this->mFrontPtr;

        for(int i = 0; i < indexParm - 1; i++){
            sTemp = sTemp->mNext;
        }

        Node<T>* node = new Node<T>(valParam);

        node->mNext = sTemp->mNext;
        node->mPrev = sTemp;

        if(sTemp->mNext != nullptr){
            sTemp->mNext->mPrev = node;
        }

        sTemp->mNext = node;

        this->mSize++;
        return true;
    }
    else if(indexParm > (this->mSize/2))
    {
        Node<T>* sTemp = this->mRearPtr;

        for(int i = this->mSize - 1; i > indexParm; i--){
            sTemp = sTemp->mPrev;
        }

        Node<T>* node = new Node<T>(valParam);

        node->mPrev = sTemp->mPrev;
        node->mNext = sTemp;

        if(sTemp->mPrev != nullptr){
            sTemp->mPrev->mNext = node;
        }

        sTemp->mPrev = node;

        this->mSize++;
        return true;
    }

    else{
        cout<<"\nUnknown state in D[n] Method \n";
        return false;
    }
}


template <typename T>
bool ExtendedDeque<T>::removeElement(uint32_t indexParm)
{
    if(this->mSize == 0){
        cout << "size is zero\n";
        return false;
    }

    if(indexParm >= this->mSize){
        return false;
    }

    if(indexParm == 0){
        this->popFront();
        return true;
    }

    if(indexParm == (this->mSize - 1)){
        this->popBack();
        return true;
    }

    else if(indexParm <= (this->mSize/2)) // traverse from front
    {
        Node<T>* sTemp = this->mFrontPtr;

        for(int i = 0; i < indexParm; i++){
            sTemp = sTemp->mNext;
        }

        sTemp->mPrev->mNext = sTemp->mNext;

        if(sTemp->mNext != nullptr){
            sTemp->mNext->mPrev = sTemp->mPrev;
        }

        delete sTemp;
        this->mSize--;

        return true;
    }

    else if(indexParm > (this->mSize/2)) // traverse from rear
    {
        Node<T>* sTemp = this->mRearPtr;

        for(int i = this->mSize - 1; i > indexParm; i--){
            sTemp = sTemp->mPrev;
        }

        sTemp->mPrev->mNext = sTemp->mNext;

        if(sTemp->mNext != nullptr){
            sTemp->mNext->mPrev = sTemp->mPrev;
        }

        delete sTemp;
        this->mSize--;

        return true;
    }

    cout << "Unknown state in removeElement\n";
    return false;
}

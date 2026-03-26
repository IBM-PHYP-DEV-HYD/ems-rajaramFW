

//class for DLL nodes, must pass the data value while obj creation 
template <typename T>
class Node {
public:
    T mData;
    Node* mPrev;
    Node* mNext;

    Node(T val) : mData(val), mPrev(nullptr), mNext(nullptr) {

    }
};

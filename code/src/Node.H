

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


// void XYZEmployeeManager::headerFullTime(){

//     std::cout << std::string(165, '-') 
//     << "";
//     std::cout << std::left
//     << "\n|" << std::setw(12) << "ID"
//     << "|" << std::setw(19) << "Name"
//     << "|" << std::setw(16) << "DOB"
//     << "|" << std::setw(16) << "DOJ"
//     << "|" << std::setw(16) << "DOL"
//     << "|" << std::setw(14) << "Status"
//     << "|" << std::setw(14) << "Gender"
//     << "|" << std::setw(16) << "Type"
//     << "|" << std::setw(16) << "TotalLeaves"
//     << "|" << std::setw(16) << "LeavesAvailed"

//     << "|" << "\n";

//     std::cout << std::string(165, '-') 
//         << "";
// }

// void XYZEmployeeManager::headerIntern(){
//         std::cout << std::string(165, '-') 
//     << "";
//     std::cout << std::left
//     << "\n|" << std::setw(12) << "ID"
//     << "|" << std::setw(19) << "Name"
//     << "|" << std::setw(16) << "DOB"
//     << "|" << std::setw(16) << "DOJ"
//     << "|" << std::setw(16) << "DOL"
//     << "|" << std::setw(14) << "Status"
//     << "|" << std::setw(14) << "Gender"
//     << "|" << std::setw(16) << "Type"
//     << "|" << std::setw(16) << "Branch"
//     << "|" << std::setw(16) << "College"
//     << "|" << "\n";

//     std::cout << std::string(165, '-') 
//     << "";

// }

// void XYZEmployeeManager::headerContractor(){
//         std::cout << std::string(150, '-') 
//     << "";
//     std::cout << std::left
//     << "\n|" << std::setw(12) << "ID"
//     << "|" << std::setw(19) << "Name"
//     << "|" << std::setw(16) << "DOB"
//     << "|" << std::setw(16) << "DOJ"
//     << "|" << std::setw(16) << "DOL"
//     << "|" << std::setw(14) << "Status"
//     << "|" << std::setw(14) << "Gender"
//     << "|" << std::setw(16) << "Type"
//     << "|" << std::setw(16) << "Agency"

//     << "|" << "\n";

//     std::cout << std::string(150, '-') 
//         << "";

// }

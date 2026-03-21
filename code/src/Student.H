// -------------------- STUDENT --------------------

class Student {
public:
    int mRollNo;
    int mAge;
    int mClass;
    string mName;

    Student() : mRollNo(0), mAge(0), mClass(0), mName("") {//non-para constructpr 

    }

    Student(int r, string n) : mRollNo(r), mAge(0), mClass(0), mName(n) { //para constructor

    }

    friend istream& operator>>(istream& in, Student& s) {//cin defined for student class type
        cout << "\nEnter Roll No: ";
        in >> s.mRollNo;
        cout << "Enter Age: ";
        in >> s.mAge;
        cout << "Enter Class: ";
        in >> s.mClass;
        cout << "Enter Name: ";
        in >> s.mName;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s) { //cout for student class type 
        out <<"[ Name, Roll no, Age, class ]"<< "[" <<s.mName <<", "<< s.mRollNo << ", " << s.mAge<< ","<<s.mClass << "]";
        return out;
    }
};

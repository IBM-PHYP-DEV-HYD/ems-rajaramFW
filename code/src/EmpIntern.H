#ifndef EMPINTERN_H
#define EMPINTERN_H

#include <string>
#include "Employee.H"
using namespace std;

class EmpIntern : public Employee
{
public:
    std::string mBranch;
    std::string mUniversityName;

public:
    EmpIntern();

    virtual ~EmpIntern() {}

    virtual std::string getBranch() override;

    virtual bool setBranch(std::string branchParm) override;

    virtual bool setUniversityName(std::string univNameParm) override;

    virtual std::string getUniversityName() override;

    friend istream& operator>>(istream& in, EmpIntern& e) {
        cout << "\nEnter Employee ID: "; 
        in >> e.mID;
        cout << "\nEnter Name: ";
        in >> e.mName;
        cout << "\nEnter DOB:\n";
        in >> e.mDOB;
        cout << "\nEnter DOJ:\n"; 
        in >> e.mDOJ;
        cout << "\nEnter Status: ";
         in >> e.mStatus;
        cout << "\nEnter Gender: ";
         in >> e.mGender;
        cout << "\nEnter Type: ";
         in >> e.mType;
        cout << "\nEnter Branch: ";
         in >> e.mBranch;
        return in;
    }

void print(std::ostream& out) const override
{
        out << "\n[ID: " << mID 
            << "\n Name: " << mName 
            << "\n DOB: " << mDOB 
            << "\n DOJ: " << mDOJ 
            << "\n DOL: " << mDOL 

            << "\n Status: " << mStatus
            << "\n Gender: " << mGender
            << "\n Type: " << mType
            << "\n Branch: " << mBranch
            << "]";
}
    
};

#endif


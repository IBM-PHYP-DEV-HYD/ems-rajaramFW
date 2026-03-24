#ifndef EMPFULLTIME_H
#define EMPFULLTIME_H

#include <string>
#include "Employee.H"
#include "Random.H"

using namespace std;

class EmpFullTime : public Employee
{
private:
    int mTotalLeaves;
    int mLeavesAvailed;

public:
    EmpFullTime();
    EmpFullTime(int rFlag);

    // Destructor
    virtual ~EmpFullTime() {}

    virtual bool setUsedLeaves(int usedLeavesParm) override;

    virtual int getTotalLeaves() override;

    virtual bool setTotalLeaves(int totalLeavesParm) override;

    virtual int getUsedLeaves() override;


    friend istream& operator>>(istream& in, EmpFullTime& e) {
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
        cout << "\nEnter Total Leaves: ";
         in >> e.mTotalLeaves;
        cout << "\nEnter Leaves Availed: "; 
        in >> e.mLeavesAvailed;
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
        << "\n Total Leaves: " << mTotalLeaves
        << "\n Leaves Availed: " << mLeavesAvailed
        << "]";
}
};


#endif
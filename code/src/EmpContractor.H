#ifndef EMPCONTRACTOR_H
#define EMPCONTRACTOR_H

#include <string>
#include "Employee.H"
#include "Random.H"

using namespace std;

class EmpContractor : public Employee
{
public:
    std::string mAgency;

public:
    EmpContractor() {}
    EmpContractor(int rFlag);

    // Destructoe
    virtual ~EmpContractor() {}

    virtual std::string getAgency() override;

    virtual bool setAgency(std::string agencyParm) override;

    friend istream& operator>>(istream& in, EmpContractor& e) {
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
        cout << "\nEnter Agency: ";
         in >> e.mAgency;
        return in;
    }


void print(std::ostream& out) const override; 

void printAll(std::ostream& out) const override;


};



#endif
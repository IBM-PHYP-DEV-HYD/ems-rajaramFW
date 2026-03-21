#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "EmployeeIF.H"

class Employee : public EmployeeIF
{
public:
    std::string mID;
    std::string mName;
    Date mDOB;
    Date mDOJ;
    Date mDOL;
    std::string mStatus;
    std::string mGender;
    std::string mType;

public:
    // Default Constructor
    Employee() {}

    // Virtual Destructor (important for polymorphism)
    virtual ~Employee() {}

    // -------- Non-Virtual Functions --------
    std::string getID();
    void setID(std::string idParm);

    std::string getName();
    void setName(std::string nameParm);

    Date getDOB();
    bool setDOB(Date DOBParm);

    Date getDOJ();
    bool setDOJ(Date DOJParm);

    Date getDOL();
    bool setDOL(Date DOJParm);

    std::string getGender();
    bool setGender(std::string genderParm);

    std::string getType();
    bool setType(std::string typeParm);

    std::string getStatus();
    bool setStatus(std::string statusParm);

    // // -------- Virtual Functions --------
    virtual int getUsedLeaves();
    virtual bool setUsedLeaves(int usedLeavesParm);

    virtual int getTotalLeaves();
    virtual bool setTotalLeaves(int totalLeavesParm);

    virtual std::string getAgency();
    virtual bool setAgency(std::string agencyParm);

    virtual std::string getBranch();
    virtual bool setBranch(std::string branchParm);

    virtual bool setUniversityName(std::string univNameParm);
    virtual std::string getUniversityName();

    virtual std::string getEmpType();
    virtual bool setEmpType(std::string empTypeParm);

    virtual std::string getEmpStatus();
    virtual bool setEmpStatus(std::string empStatusParm);

    virtual std::string getLWD();

    virtual void print(std::ostream& out) const;

};

#endif
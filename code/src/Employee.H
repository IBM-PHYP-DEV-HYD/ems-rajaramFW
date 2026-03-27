#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "EmployeeIF.H"
#include "Random.H"
#include <iomanip>



class Employee : public EmployeeIF
{
protected:
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
    Employee();
    Employee(bool randParm);

    virtual ~Employee() {}

    std::string getID() override;
    void setID(std::string idParm) override;

    std::string getName() override;
    void setName(std::string nameParm) override;

    Date getDOB() override;
    bool setDOB(Date DOBParm) override; 

    Date getDOJ() override;
    bool setDOJ(Date DOJParm) override;

    Date getDOL() override;
    bool setDOL(Date DOJParm) override;

    std::string getGender() override;
    bool setGender(std::string genderParm) override;

    // -------- Virtual Functions -------------
    virtual int getUsedLeaves() override;
    virtual bool setUsedLeaves(int usedLeavesParm) override;

    virtual int getTotalLeaves() override;
    virtual bool setTotalLeaves(int totalLeavesParm) override;

    virtual std::string getAgency() override;
    virtual bool setAgency(std::string agencyParm) override;

    virtual std::string getBranch() override;
    virtual bool setBranch(std::string branchParm) override;

    virtual bool setUniversityName(std::string univNameParm) override;
    virtual std::string getUniversityName() override;

    virtual std::string getType() override;
    virtual bool setType(std::string empTypeParm) override;

    virtual std::string getStatus() override;
    virtual bool setStatus(std::string empStatusParm) override;

    virtual std::string getLWD() override;

    virtual void print(std::ostream& out) const override;

    virtual void printAll(std::ostream& out) const override;


};

#endif
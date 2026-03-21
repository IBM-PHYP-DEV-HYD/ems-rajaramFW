#ifndef EMPLOYEEIF_H
#define EMPLOYEEIF_H

#include <string>
#include "Date.H"

class EmployeeIF
{
public:
    virtual ~EmployeeIF() = default;

    virtual std::string getID() = 0;
    virtual void setID(std::string idParm) = 0;
    

    virtual std::string getName() = 0;
    virtual void setName(std::string nameParm) = 0;
    

    virtual Date getDOB() = 0;
    virtual bool setDOB(Date DOBParm) = 0;

    virtual Date getDOJ() = 0;
    virtual bool setDOJ(Date DOJParm) = 0;

    virtual Date getDOL() = 0;
    virtual bool setDOL(Date DOJParm) = 0;

    

    virtual int getUsedLeaves() = 0;
    virtual bool setUsedLeaves(int usedLeavesParm) = 0;

    virtual int getTotalLeaves() = 0;
    virtual bool setTotalLeaves(int totalLeavesParm) = 0;

    virtual std::string getAgency() = 0;
    virtual bool setAgency(std::string agencyParm) = 0;

    virtual std::string getBranch() = 0;
    virtual bool setBranch(std::string branchParm) = 0;

    virtual bool setUniversityName(std::string univNameParm) = 0;
    virtual std::string getUniversityName() = 0;

    virtual std::string getType() = 0;
    virtual bool setType(std::string empTypeParm) = 0;

    virtual std::string getGender() = 0;
    virtual bool setGender(std::string genderParm) = 0;

    virtual std::string getStatus() = 0;
    virtual bool setStatus(std::string empStatusParm) = 0;

    virtual std::string getLWD() = 0;

    virtual void print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const EmployeeIF& e);

};

inline std::ostream& operator<<(std::ostream& out, const EmployeeIF& e) {
    e.print(out);  
    return out;
}
#endif
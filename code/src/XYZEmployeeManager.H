#ifndef XYZEMPLOYEEMANAGER_H
#define XYZEMPLOYEEMANAGER_H

#include <string>
#include "EmployeeIF.H"

#include "Ems.H"
#include "Deque.H"
#include "ExtendedDeque.H"
class Employee;

class XYZEmployeeManager
{
private:

    ExtendedDeque<EmployeeIF*> mCurEmployeeQueue;
    ExtendedDeque<Employee*> mResignedEmployeeQueue;  

    int mActiveEmpCount;
    int mInactiveEmpCount;
    int mResignedEmpCount;
    int mTotalEmpCount;

public:
    bool pAddEmpRandom();
    void pAddNEmpRandom(int n);

    bool pAddEmp();
    bool pRemove(std::string IDParm);
    EmployeeIF* pSearchWithId(std::string IDParm);
    
    int pComputeDOL(std::string IDParm);
    bool makeFullTime(std::string IDParm);
    bool premoveLeaves(int leaveCountParm);
    EmployeeIF* pSearchWithName(std::string nameParm);
    bool pAddLeaves(int leaveParm);
    void pDisplayFulltime();
    void pDisplayContractor();
    void pDisplayIntern();

    void pDisplayActiveEmp();
    void pDisplayInActiveEmp();

    void pDisplayMaleEmp();
    void pDisplayFemaleEmp();

    void pDisplayEmpSummary(std::string empID);



    

public:
    // Constructor
    XYZEmployeeManager();

    // Destructor
    ~XYZEmployeeManager();

    int getActiveEmpCount();
    int getInactiveEmpCount();
    int getResignedEmpCount();
    int getTotalEmpCount();

    void displayEmpList();
    void displayInactiveEmp();
    void displayResignedEmp();
    void makeResigned(Employee* objParm);

    void headerAll();
    void headerFIC(int valParm);
    void headerResigned();




};

#endif
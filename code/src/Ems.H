#include <iostream>
#include "EmpFullTime.H"
#include "EmpContractor.H"
#include "EmpIntern.H"

using namespace std;

int getRandomNumber(int startNumParm,int endNumParm);
EmpFullTime& randomEmpFullTimefunc(EmpFullTime& obj);
EmpContractor& randomEmpContractorfunc(EmpContractor& obj);
EmpIntern& randomEmpInternfunc(EmpIntern& obj);
std::string createEmpID(uint32_t seqParm, uint8_t empType);


// Employee Status
enum EmployeeType {
    FULLTIME = 1,
    CONTRACTOR = 2,
    INTERN = 3
};

// Employee Status
enum EmployeeStatus {
    ACTIVE = 0,
    INACTIVE = 1,
    RESIGNED = 2
};

// Contractor Agencies
enum ContractorAgency {
    AVENGERS = 0,
    JUSTICE_LEAGUE = 1,
    X_MEN = 2
};

// Intern Colleges
enum InternCollege {
    IIT_DELHI = 0,
    IIT_MUMBAI = 1,
    IIT_KANPUR = 2,
    IIT_HYDERABAD = 3,
    NIT_WARANGAL = 4,
    NIT_TIRUCHI = 5,
    IIIT_HYDERABAD = 6
};

// Intern Branches
enum InternBranch {
    CSE = 0,
    CSIT = 1,
    ECE = 2
};


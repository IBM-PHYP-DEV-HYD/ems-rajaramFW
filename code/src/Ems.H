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

// string gender[] = {"Male","Female","Others"};
// string status[] = {"Active","inactive"};
// string agency[] = {"AVENGERS","JUSTICE_LEAGUE","X_MEN"};
// string branch[] = {"CSE","CSIT","ECE"};
// string collage[] = {"IIT_DELHI","IIT_MUMBAI","IIT_KANPUR","IIT_HYDERABAD","NIT_WARANGAL","NIT_TIRUCHI,IIIT_HYDERABAD"};
// string Name[] = {"RAM","ELISA","JOHN","VICTORIA","ALBERT","MARIE","ALEX","ALEXA","BOB","SIRI"};


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


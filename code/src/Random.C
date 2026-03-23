#include <iostream>
#include <random>
#include "EmpFullTime.H"
#include "EmpContractor.H"
#include "EmpIntern.H"

using namespace std;

string gender[] = {"Male","Female","Others"};
string status[] = {"Active","inactive"};
string agency[] = {"AVENGERS","JUSTICE_LEAGUE","X_MEN"};
string branch[] = {"CSE","CSIT","ECE"};
string collage[] = {"IIT_DELHI","IIT_MUMBAI","IIT_KANPUR","IIT_HYDERABAD","NIT_WARANGAL","NIT_TIRUCHI,IIIT_HYDERABAD"};
string Name[] = {"RAM","ELISA","JOHN","VICTORIA","ALBERT","MARIE","ALEX","ALEXA","BOB","SIRI"};

int getRandomNumber(int startNumParm,
                    int endNumParm)
{
    std::random_device sRandomDevice;
    std::mt19937 sRandomNumberGenerator(sRandomDevice());
    std::uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}

EmpFullTime& randomEmpFullTimefunc(EmpFullTime& obj){
    int sNameSelector = getRandomNumber(0,9);
    obj.mName = Name[sNameSelector];
    obj.mGender = (((sNameSelector%2) == 0) ? "Male" : "Female");
    obj.mStatus = status[getRandomNumber(0,1)];

    obj.mDOB.mDay = getRandomNumber(1,30);
    obj.mDOB.mMonth = getRandomNumber(1,12);
    obj.mDOB.mYear = getRandomNumber(1970,2000);
    
    obj.mDOJ.mDay = getRandomNumber(1,30);
    obj.mDOJ.mMonth = getRandomNumber(1,12);
    obj.mDOJ.mYear = getRandomNumber(2022,2026);

    obj.mDOL.mValid = false;
    
    obj.mTotalLeaves = getRandomNumber(1,22);
    obj.mLeavesAvailed = getRandomNumber(1,20);

    return obj;
}

EmpContractor& randomEmpContractorfunc(EmpContractor& obj){

    int sNameSelector = getRandomNumber(0,9);
    obj.mName = Name[sNameSelector];
    obj.mGender = (((sNameSelector%2) == 0) ? "Male" : "Female");
    obj.mStatus = status[getRandomNumber(0,1)];

    obj.mDOB.mDay = getRandomNumber(1,30);
    obj.mDOB.mMonth = getRandomNumber(1,12);
    obj.mDOB.mYear = getRandomNumber(1970,2000);
    
    obj.mDOJ.mDay = getRandomNumber(1,30);
    obj.mDOJ.mMonth = getRandomNumber(1,12);
    obj.mDOJ.mYear = getRandomNumber(2022,2026);

    obj.mDOL = addMonths(obj.mDOJ,12);

    
    obj.mAgency = agency[getRandomNumber(0,2)];
    return obj;
}

EmpIntern& randomEmpInternfunc(EmpIntern& obj){

    int sNameSelector = getRandomNumber(0,9);
    obj.mName = Name[sNameSelector];
    obj.mGender = (((sNameSelector%2) == 0) ? "Male" : "Female");
    obj.mStatus = status[getRandomNumber(0,1)];

    obj.mDOB.mDay = getRandomNumber(1,30);
    obj.mDOB.mMonth = getRandomNumber(1,12);
    obj.mDOB.mYear = getRandomNumber(1970,2000);
    
    obj.mDOJ.mDay = getRandomNumber(1,30);
    obj.mDOJ.mMonth = getRandomNumber(1,12);
    obj.mDOJ.mYear = getRandomNumber(2022,2026);

    obj.mDOL = addMonths(obj.mDOJ,6);
    
    obj.mBranch = branch[getRandomNumber(0,2)];
    obj.mUniversityName = collage[getRandomNumber(0,2)];
    return obj;
}

std::string createEmpID(uint32_t seqParm, uint8_t empType)
{
    char empTypeList[] = {'F','I','C'};
    std::string sPrefix = "XYZ";

    std::string num;

    if(seqParm < 10)
        num = "000" + std::to_string(seqParm);
    else if(seqParm < 100)
        num = "00" + std::to_string(seqParm);
    else if(seqParm<1000)
        num = "0" + std::to_string(seqParm);
    else
        num = std::to_string(seqParm);

    std::string sID = sPrefix + num + empTypeList[empType];
    return sID;
}


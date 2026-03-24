#include "EmpContractor.H"

// Getter
std::string EmpContractor::getAgency() {
    return mAgency;
}

// Setter
bool EmpContractor::setAgency(std::string agencyParm) {
    this->mAgency = agencyParm;
    return true;
}

EmpContractor::EmpContractor(int rFlag){
    int sNameSelector = Random::getRandomNumber(0,9);
    this->mName = Random::Name[sNameSelector];
    this->mGender = (((sNameSelector%2) == 0) ? "Male" : "Female");
    this->mStatus = Random::status[Random::getRandomNumber(0,1)];

    this->mDOB.mDay = Random::getRandomNumber(1,30);
    this->mDOB.mMonth = Random::getRandomNumber(1,12);
    this->mDOB.mYear = Random::getRandomNumber(1970,2000);
    
    this->mDOJ.mDay = Random::getRandomNumber(1,30);
    this->mDOJ.mMonth = Random::getRandomNumber(1,12);
    this->mDOJ.mYear = Random::getRandomNumber(2022,2026);

    this->mDOL = addMonths(this->mDOJ,12);

    
    this->mAgency = Random::agency[Random::getRandomNumber(0,2)];
 
}

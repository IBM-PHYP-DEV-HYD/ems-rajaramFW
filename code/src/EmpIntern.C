#include "EmpIntern.H"

std::string EmpIntern::getBranch() {
    return mBranch;
}

bool EmpIntern::setBranch(std::string branchParm) {
    this->mBranch = branchParm;
    return true;
}

bool EmpIntern::setUniversityName(std::string univNameParm) {
    this->mUniversityName = univNameParm;
    return true;
}

std::string EmpIntern::getUniversityName() {
    return mUniversityName;
}

EmpIntern::EmpIntern(){

}
EmpIntern::EmpIntern(int rFlag){
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

    this->mDOL = addMonths(this->mDOJ,6);
    
    this->mBranch = Random::branch[Random::getRandomNumber(0,2)];
    this->mUniversityName = Random::collage[Random::getRandomNumber(0,2)];
}

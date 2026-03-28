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
EmpIntern::EmpIntern(int rFlag) : Employee(true){

    this->mDOL = addMonths(this->mDOJ,6);
    
    this->mBranch = Random::branch[Random::getRandomNumber(0,2)];
    this->mUniversityName = Random::collage[Random::getRandomNumber(0,2)];
}

void EmpIntern::print(std::ostream& out) const 
{
        out << std::left
        << "\n|" << std::setw(12) << mID
        << "|" << std::setw(19) << mName
        << "|" << std::setw(16) << mDOB
        << "|" << std::setw(16) << mDOJ
        << "|" << std::setw(16) << mDOL
        << "|" << std::setw(14) << mStatus
        << "|" << std::setw(14) << mGender
        << "|" << std::setw(16) << mType
        << "|" << std::setw(16) << mBranch
        << "|" << std::setw(16) << mUniversityName
        << "|" << "";

}

void EmpIntern::printAll(std::ostream& out) const {
        out << std::left
        << "\n|" << std::setw(12) << mID
        << "|" << std::setw(19) << mName
        << "|" << std::setw(16) << mDOB
        << "|" << std::setw(16) << mDOJ
        << "|" << std::setw(16) << mDOL
        << "|" << std::setw(14) << mStatus
        << "|" << std::setw(14) << mGender
        << "|" << std::setw(16) << mType
        << "|" << std::setw(16) << "N/A"
        << "|" << std::setw(16) << "N/A"
        << "|" << std::setw(16) << "N/A"
        << "|" << std::setw(16) << mBranch

        << "|" << std::setw(16) << mUniversityName
        << "|" << "";

}


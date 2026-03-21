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
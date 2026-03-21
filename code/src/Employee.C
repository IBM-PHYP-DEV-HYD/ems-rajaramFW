#include "Employee.H"

std::string Employee::getID(){
    return mID;
}

void Employee::setID(std::string idParm){
    this->mID = idParm;
}

std::string Employee::getName(){
    return mName;
}
void Employee::setName(std::string nameParm){
    this->mName = nameParm;
}

Date Employee::getDOB(){
    return mDOB;
}

bool Employee::setDOB(Date DOBParm){
    this->mDOB = DOBParm;
    return true;
}

Date Employee::getDOJ(){
    return mDOJ;
}

bool Employee::setDOJ(Date DOJParm){
    this->mDOJ = DOJParm;
    return true;
}

Date Employee::getDOL() {
    return mDOL;
}

bool Employee::setDOL(Date DOJParm){
    this->mDOL = DOJParm;
    return true;
}

std::string Employee::getGender(){
    return mGender;
}

std::string Employee::getType(){
    return mType;
}

std::string Employee::getStatus(){
    return mStatus;
}

bool Employee::setGender(std::string genderParm){
    this->mGender = genderParm;
    return true;
}

bool Employee::setType(std::string typeParm){
    this->mType = typeParm;
    return true;
}

bool Employee::setStatus(std::string statusParm){
    this->mStatus = statusParm;
    return true;
}

//virtual funsitons 

int Employee::getUsedLeaves(){
    return 0;
}

bool Employee::setUsedLeaves(int usedLeavesParm){
    return true;
}

int Employee::getTotalLeaves(){
    return 0;
}

bool Employee::setTotalLeaves(int totalLeavesParm){
    return true;
}

std::string Employee::getAgency(){
    return "";
}

bool Employee::setAgency(std::string agencyParm){
    return true;
}

std::string Employee::getBranch(){
    return "";
}

bool Employee::setBranch(std::string branchParm){
    return true;
}

bool Employee::setUniversityName(std::string univNameParm){
    return true;
}

std::string Employee::getUniversityName(){
    return "";
}

std::string Employee::getEmpType(){
    return "";
}

bool Employee::setEmpType(std::string empTypeParm){
    return true;
}

std::string Employee::getEmpStatus(){
    return "";
}

bool Employee::setEmpStatus(std::string empStatusParm){
    return true;
}

// std::string getEmpGender(){
//     return 
// }
// bool setEmpGender(std::string empGenderParm){
//     mGender = empGenderParm;
// }

std::string Employee::getLWD(){
    return "";
}

void Employee::print(std::ostream& out) const{
    out << "\n[ID: " << mID 
    << "\n Name: " << mName 
    << "\n DOB: " << mDOB 
    << "\n DOJ: " << mDOJ 
    << "\n DOL: " << mDOL 
    << "\n Status: " << mStatus
    << "\n Gender: " << mGender
    << "\n Type: " << mType
    << "]";

}

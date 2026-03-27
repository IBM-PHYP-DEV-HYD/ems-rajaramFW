#include "Employee.H"


Employee::Employee(){

}

Employee::Employee(bool randParm){
    std::cout<<"Random Constrcutor - Emp base\n";
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
}

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

std::string Employee::getLWD(){
    return "";
}


void Employee::print(std::ostream& out) const {

    out << std::left
        << "|" << std::setw(12) << mID
        << "|" << std::setw(19) << mName
        << "|" << std::setw(16) << mDOB
        << "|" << std::setw(16) << mDOJ
        << "|" << std::setw(16) << mDOL
        << "|" << std::setw(14) << mStatus
        << "|" << std::setw(14) << mGender
        << "|" << std::setw(16) << mType
        << "|" << "";
}

void Employee::printAll(std::ostream& out) const {


}

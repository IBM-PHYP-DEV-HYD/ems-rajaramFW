#include "EmpFullTime.H"


bool EmpFullTime :: setUsedLeaves(int usedLeavesParm){
    if(usedLeavesParm>this->mTotalLeaves){
        return false;
    }
    this->mLeavesAvailed = usedLeavesParm;
    return true;
}

int EmpFullTime :: getUsedLeaves(){
    return mLeavesAvailed;
}

int EmpFullTime :: getTotalLeaves(){
    return mTotalLeaves;
}

bool EmpFullTime :: setTotalLeaves(int totalLeavesParm){
    if(totalLeavesParm>22){
        return false;
    }
    this->mTotalLeaves = totalLeavesParm;
    return true;
}

EmpFullTime::EmpFullTime(){
    mDOL.mValid = false;
}

EmpFullTime::EmpFullTime(int rFlag) : Employee(true){
    // headerFlag=0;
    cout<<"random constructior - FT";

    this->mDOL.mValid = false;
    
    this->mTotalLeaves = Random::getRandomNumber(1,22);
    this->mLeavesAvailed = Random::getRandomNumber(1,20);
}

void EmpFullTime::print(std::ostream& out) const {


    out << std::left
        << "\n|" << std::setw(12) << mID
        << "|" << std::setw(19) << mName
        << "|" << std::setw(16) << mDOB
        << "|" << std::setw(16) << mDOJ
        << "|" << std::setw(16) << mDOL
        << "|" << std::setw(14) << mStatus
        << "|" << std::setw(14) << mGender
        << "|" << std::setw(16) << mType
        << "|" << std::setw(16) << mTotalLeaves
        << "|" << std::setw(16) << mLeavesAvailed
        << "|" << "";
}

void EmpFullTime::printAll(std::ostream& out) const {

        out << std::left
        << "\n|" << std::setw(12) << mID
        << "|" << std::setw(19) << mName
        << "|" << std::setw(16) << mDOB
        << "|" << std::setw(16) << mDOJ
        << "|" << std::setw(16) << mDOL
        << "|" << std::setw(14) << mStatus
        << "|" << std::setw(14) << mGender
        << "|" << std::setw(16) << mType
        << "|" << std::setw(16) << mTotalLeaves
        << "|" << std::setw(16) << mLeavesAvailed
        << "|" << std::setw(16) << "N/A"
        << "|" << std::setw(16) << "N/A"
        << "|" << std::setw(16) << "N/A"

        << "|" << "";

}

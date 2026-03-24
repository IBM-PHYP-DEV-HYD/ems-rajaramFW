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

EmpFullTime::EmpFullTime(int rFlag){
    cout<<"random constructior - FT";
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

    this->mDOL.mValid = false;
    
    this->mTotalLeaves = Random::getRandomNumber(1,22);
    this->mLeavesAvailed = Random::getRandomNumber(1,20);
}

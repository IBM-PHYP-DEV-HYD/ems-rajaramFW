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

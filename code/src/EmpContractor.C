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

EmpContractor::EmpContractor(int rFlag) : Employee(true){

    this->mDOL = addMonths(this->mDOJ,12);

    this->mAgency = Random::agency[Random::getRandomNumber(0,2)];
 
}

void EmpContractor::print(std::ostream& out) const 
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
        << "|" << std::setw(16) << mAgency
        << "|" << "";

}

void EmpContractor::printAll(std::ostream& out) const {
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
        << "|" << std::setw(16) << mAgency
        << "|" << std::setw(16) << "N/A"
        << "|" << std::setw(16) << "N/A"


        << "|" << "";

}


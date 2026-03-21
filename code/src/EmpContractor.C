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
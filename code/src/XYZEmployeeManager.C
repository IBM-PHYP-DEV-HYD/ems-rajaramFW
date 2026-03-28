#include "XYZEmployeeManager.H"


using namespace std;

string empType[] = {"FULLTIME","INTERN","CONTRACTOR"};

XYZEmployeeManager :: XYZEmployeeManager(){

}

bool XYZEmployeeManager::pAddEmpRandom(){

    int sTypeSelector = Random::getRandomNumber(0,2);
    // sTypeSelector=2;


    if(sTypeSelector == 0){
        EmpFullTime* sFT = new EmpFullTime(1);//destructor of XYZEmployeeMnager should delete this heap memory
        sFT->setType(empType[0]);
        sFT->setID(createEmpID(mTotalEmpCount,sTypeSelector));
        mCurEmployeeQueue.pushBack(sFT);
    }
    else if(sTypeSelector == 1){
        EmpIntern* sIn = new EmpIntern(1);
        sIn->setType(empType[1]);
        sIn->setID(createEmpID(mTotalEmpCount,sTypeSelector));
        mCurEmployeeQueue.pushBack(sIn);
    }
    else if(sTypeSelector == 2){
        EmpContractor* sCe = new EmpContractor(1);
        sCe->setType(empType[2]);
        sCe->setID (createEmpID(mTotalEmpCount,sTypeSelector));
        mCurEmployeeQueue.pushBack(sCe);
    }
    mTotalEmpCount++;
    return true;
}

bool XYZEmployeeManager::pAddEmp(){

    int sType=0;
    cout<<"Choose Type\n";
    cout<<"1)Fulltime\n";
    cout<<"2)Intern\n";
    cout<<"3)Contractor\n";
    cout<<"Your Choice : ";
    cin>>sType;
    // cinBufferClear();
    if(sType==1){
        EmpFullTime* sFT = new EmpFullTime();//destructor of XYZEmployeeMnager should delete this heap memory
        sFT->setType(empType[0]);
        cin>>*sFT;
        mCurEmployeeQueue.pushBack(sFT);
    }
    else if(sType==2){
        EmpIntern* sIn = new EmpIntern();
        sIn->setType(empType[1]);
        cin>>*sIn;
        mCurEmployeeQueue.pushBack(sIn);
    }
    else if(sType == 3){
        EmpContractor* sCe = new EmpContractor();
        sCe->setType(empType[2]);
        cin>>*sCe;
        mCurEmployeeQueue.pushBack(sCe);

    }
    mTotalEmpCount++;
    return true;
}

bool XYZEmployeeManager::pRemove(std::string IDParm)
{
    cout << "\nIDParm is " << IDParm;

    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++)
    {
        cout << "\nID in queue " << mCurEmployeeQueue[i]->getID();

        if(mCurEmployeeQueue[i]->getID() == IDParm)
        {
            Employee* sObj = new Employee();

            sObj->setName(mCurEmployeeQueue[i]->getName());
            sObj->setID(mCurEmployeeQueue[i]->getID());
            sObj->setDOB(mCurEmployeeQueue[i]->getDOB());
            sObj->setDOJ(mCurEmployeeQueue[i]->getDOJ());
            
            if(mCurEmployeeQueue[i]->getID()[7] == 'F'){
                // Date sDOL = mCurEmployeeQueue[i]->getDOJ();
                
                sObj->setDOL(addMonths(mCurEmployeeQueue[i]->getDOJ(),36));
            }
            else{
                sObj->setDOL(mCurEmployeeQueue[i]->getDOL());
            }

            sObj->setGender(mCurEmployeeQueue[i]->getGender());

            sObj->setType("Resigned");
            sObj->setStatus(mCurEmployeeQueue[i]->getStatus());

            mResignedEmployeeQueue.pushBack(sObj);

            mCurEmployeeQueue.removeElement(i);

            return true;
        }
    }

    cout << "Employee with ID not found\n";
    return false;
}

void XYZEmployeeManager::displayEmpList(){
    this->headerAll();
    
    for(int i=0;i<mCurEmployeeQueue.get_size();i++){

        // cout<<"\nprint all function xecuted for all types  \n";
        mCurEmployeeQueue[i]->printAll(cout);


        // if(mCurEmployeeQueue[i]->getID()[7] == 'F'){
        //     // mCurEmployeeQueue[i]->printAll(cout);
        //     // cout<<"\nprint all function xecuted for fulltime \n";

        // }
        // else if(mCurEmployeeQueue[i]->getID()[7] == 'I'){

        // }
        // else if(mCurEmployeeQueue[i]->getID()[7] == 'C'){

        // }
        // else{

        // }

    }
}

void XYZEmployeeManager::displayResignedEmp(){
    this->headerResigned();
    for(int i=0;i<mResignedEmployeeQueue.get_size();i++){
        EmployeeIF* sObjPtr = ((mResignedEmployeeQueue[i]));
        std::cout << *sObjPtr << std::endl;
    }
}

bool XYZEmployeeManager::makeFullTime(std::string IDParm){
    
    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++)
    {
        cout << "\nID in queue " << mCurEmployeeQueue[i]->getID();

        if(mCurEmployeeQueue[i]->getID() == IDParm)
        {
            EmpFullTime* sObj = new EmpFullTime();

            sObj->setTotalLeaves(20);

            sObj->setName(mCurEmployeeQueue[i]->getName());
            std::string sID = mCurEmployeeQueue[i]->getID();
            sID[7] = 'F';
            sObj->setID(sID);
            sObj->setDOB(mCurEmployeeQueue[i]->getDOB());
            sObj->setDOJ(mCurEmployeeQueue[i]->getDOJ());
            sObj->setGender(mCurEmployeeQueue[i]->getGender());

            sObj->setType("FullTime");
            sObj->setStatus("Active");

            mCurEmployeeQueue.removeElement(i);

            mCurEmployeeQueue.pushBack(sObj);

            return true;
        }
    }
    
    return true;
}

bool XYZEmployeeManager::pAddLeaves(int LeaveParm){
    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++){
        if(mCurEmployeeQueue[i]->getID()[7] == 'F'){
            int newLeaves = mCurEmployeeQueue[i]->getTotalLeaves() + LeaveParm;
            if(newLeaves>22){
                newLeaves = 22;
            }
            mCurEmployeeQueue[i]->setTotalLeaves(newLeaves);            

        }
    }
    return true;
}

EmployeeIF* XYZEmployeeManager::pSearchWithId(std::string IDParm){
    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++)
    {
        // cout << "\nID in queue " << mCurEmployeeQueue[i]->getID();

        if(mCurEmployeeQueue[i]->getID() == IDParm)
        {
            return mCurEmployeeQueue[i];
        }
    }
    return nullptr;
}

EmployeeIF* XYZEmployeeManager::pSearchWithName(std::string nameParm){
    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++)
    {
        cout << "\nID in queue " << mCurEmployeeQueue[i]->getID();

        if(mCurEmployeeQueue[i]->getName() == nameParm)
        {
            return mCurEmployeeQueue[i];
        }
    }
    return nullptr;
}

void XYZEmployeeManager::pDisplayFulltime(){
    int sCtr=0;
    headerFIC(1);
   for(int i = 0; i < mCurEmployeeQueue.get_size(); i++){
        if(mCurEmployeeQueue[i]->getID()[7] == 'F'){
            cout<<*mCurEmployeeQueue[i];
            sCtr++;
        }
    }
    if(!sCtr){
        cout<<"\nNo Fulltime Employee\n";
    }
}

void XYZEmployeeManager::pDisplayContractor(){
    int sCtr = 0;
    headerFIC(2);
    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++){
        if(mCurEmployeeQueue[i]->getID()[7] == 'C'){
            cout<<*mCurEmployeeQueue[i];
            sCtr++;
        }
    }
    if(!sCtr){
        cout<<"\nNo Contractor Employee\n";
    }

}

void XYZEmployeeManager::pDisplayIntern(){
    int sCtr = 0;
    headerFIC(3);

    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++){
        if(mCurEmployeeQueue[i]->getID()[7] == 'I'){
            cout<<*mCurEmployeeQueue[i];
            sCtr++;
        }
    }
    if(!sCtr){
        cout<<"\nNo Intern Employee\n";
    }
}

void XYZEmployeeManager::pDisplayActiveEmp(){
    int sCtr = 0;
    this->headerAll();

    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++){
        if((mCurEmployeeQueue[i]->getStatus()[0] == 'A') || (mCurEmployeeQueue[i]->getStatus()[0] == 'a')){

            mCurEmployeeQueue[i]->printAll(cout);
            sCtr++;
        }
    }
    if(!sCtr){
        cout<<"\nNo Active Employee\n";
    }
}

void XYZEmployeeManager::pDisplayInActiveEmp(){
    int sCtr = 0;
    this->headerAll();

    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++){
        if((mCurEmployeeQueue[i]->getStatus()[0] == 'I') || (mCurEmployeeQueue[i]->getStatus()[0] == 'i')){
            mCurEmployeeQueue[i]->printAll(cout);
            sCtr++;
        }
    }
    if(!sCtr){
        cout<<"\nNo Active Employee\n";
    }
}


void XYZEmployeeManager::pDisplayMaleEmp(){
    int sCtr = 0;
    this->headerAll();

    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++){
        if((mCurEmployeeQueue[i]->getGender() == "Male")){
            mCurEmployeeQueue[i]->printAll(cout);
            sCtr++;
        }
    }
    if(!sCtr){
        cout<<"\nNo Male Employee\n";
    }
}

void XYZEmployeeManager::pDisplayFemaleEmp(){
    int sCtr = 0;
    this->headerAll();

    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++){
        if((mCurEmployeeQueue[i]->getGender() == "Female")){
            mCurEmployeeQueue[i]->printAll(cout);
            sCtr++;
        }
    }
    if(!sCtr){
        cout<<"\nNo Male Employee\n";
    }
}

void XYZEmployeeManager::pDisplayEmpSummary(std::string empID){
    cout<<"\nInside Employee Summary\n";
    EmployeeIF* objPtr = this->pSearchWithId(empID);

    if(objPtr->getID()[7] == 'F'){
        headerFIC(1);
    }
    if(objPtr->getID()[7] == 'I'){
        headerFIC(2);
    }
    if(objPtr->getID()[7] == 'C'){
        headerFIC(3);
    }

    cout<<*objPtr;

}

void XYZEmployeeManager::pAddNEmpRandom(int n){
    for(int sIt=0;sIt<n;sIt++){
        pAddEmpRandom();
    }
}

void XYZEmployeeManager::headerFIC(int valParm){

    std::cout << std::string(165, '-') 
    << "";
    std::cout << std::left
    << "\n|" << std::setw(12) << "ID"
    << "|" << std::setw(19) << "Name"
    << "|" << std::setw(16) << "DOB"
    << "|" << std::setw(16) << "DOJ"
    << "|" << std::setw(16) << "DOL"
    << "|" << std::setw(14) << "Status"
    << "|" << std::setw(14) << "Gender"
    << "|" << std::setw(16) << "Type";

    if(valParm == 1){
        cout<< "|" << std::setw(16) << "TotalLeaves"
            << "|" << std::setw(16) << "LeavesAvailed";
    }
    if(valParm == 2){
        cout<< "|" << std::setw(16) << "Branch"
            << "|" << std::setw(16) << "College";
    }
    if(valParm == 3){
        cout<< "|" << std::setw(16) << "Agency";
    }

    std::cout<< "|" << "\n";
    std::cout << std::string(165, '-') 
        << "";

}


void XYZEmployeeManager::headerResigned(){
    std::cout << std::left
        << "|" << std::setw(12) << "ID"
        << "|" << std::setw(19) << "Name"
        << "|" << std::setw(16) << "DOB"
        << "|" << std::setw(16) << "DOJ"
        << "|" << std::setw(16) << "DOL"
        << "|" << std::setw(14) << "Status"
        << "|" << std::setw(14) << "Gender"
        << "|" << std::setw(16) << "Type"
        << "|" << "\n";

    std::cout << std::string(132, '-') 
        << "\n";
}

void XYZEmployeeManager::headerAll(){
        cout << "+"
         << string(12, '-') << "+"
         << string(19, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(14, '-') << "+"
         << string(14, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(14, '-') << "+"
         << endl;

    // Header row
    cout << "|"
         << left << setw(12)  << "EmpID"       << "|"
         << setw(19) << "Name"        << "|"
         << setw(16) << "DOB"         << "|"
         << setw(16) << "DOJ"         << "|"
         << setw(16) << "DOL"         << "|"
         << setw(14) << "Status"      << "|"
         << setw(14)  << "Gender"      << "|"
         << setw(16) << "Type"        << "|"
         << setw(16) << "TotLeaves"   << "|"
         << setw(16) << "UsedLeaves"  << "|"
         << setw(16) << "Agency"      << "|"
         << setw(16) << "Branch"      << "|"
         << setw(16) << "University"  << ""
         << endl;


    // Header bottom border
    cout << "+"
         << string(12, '-') << "+"
         << string(19, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(14, '-') << "+"
         << string(14, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(16, '-') << "+"
         << string(14, '-') << "+"
         << endl;

}

XYZEmployeeManager::~XYZEmployeeManager()
{
    for(int i = 0; i < mCurEmployeeQueue.get_size(); i++)
    {
        delete mCurEmployeeQueue[i];
    }

    for(int i = 0; i < mResignedEmployeeQueue.get_size(); i++)
    {
        delete mResignedEmployeeQueue[i];
    }
    cout<<" XYZEmployeeManager destructor called  "<<"\n";

}


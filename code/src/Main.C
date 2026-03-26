#include "Header.H"
#include "EmpContractor.H"
#include "EmpIntern.H"
#include "XYZEmployeeManager.H"


//public variable 
bool gFlag=false;
int sChoice = 0;

int mainMenu_1()
{
    int sKey;
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "|                Employee Management System                |\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "|                                                          |\n";
    std::cout << "|   1. Add an Employee                                     |\n";
    std::cout << "|   2. Remove an Employee                                  |\n";
    std::cout << "|   3. Get Employee Details                                |\n";
    std::cout << "|   4. Do something else                                   |\n";
    std::cout << "|                                                          |\n";
    std::cout << "|   (Enter -1 to exit)                                     |\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Your Choice: ";
    cin >> sKey;
    cinBufferClear();
    return sKey;
}

int mainMenu_2()
{
    int sKey;
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "|                Employee Management System                |\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "|                                                          |\n";
    std::cout << "| Add an Employee:                                         |\n";
    std::cout << "|                                                          |\n";
    std::cout << "|      1. Add an Employee at Random                        |\n";
    std::cout << "|      2. Add an Employee (F/C/I)                          |\n";
    std::cout << "|                                                          |\n";
    std::cout << "|   (Enter -1 to go back to main menu)                     |\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Your Choice: ";
    cin >> sKey;
    cinBufferClear();
    return sKey;
}


int mainMenu_3()
{
    int sKey;
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "|                Employee Management System                |\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "|                                                          |\n";
    std::cout << "| Get Employee Details:                                    |\n";
    std::cout << "|                                                          |\n";
    std::cout << "|      1. All Employees Summary                            |\n";
    std::cout << "|      2. Employee Summary (F/C/I)                         |\n";
    std::cout << "|      3. Employee Summary (M/F)                           |\n";
    std::cout << "|      4. Employee Summary (A/I/R)                         |\n";
    std::cout << "|      5. Display Employee Details                         |\n";
    std::cout << "|                                                          |\n";
    std::cout << "|   (Enter -1 to go back to main menu)                     |\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Your Choice: ";
    cin >> sKey;
    cinBufferClear();
    return sKey;
}

int mainMenu_4()
{
    int sKey;
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "|                Employee Management System                |\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "|                                                          |\n";
    std::cout << "| Do something else:                                       |\n";
    std::cout << "|                                                          |\n";
    std::cout << "|      1. Add 'n' number of leaves to                      |\n";
    std::cout << "|         all the Full-Time employees                      |\n";
    std::cout << "|      2. Convert an Intern to Full-Time                   |\n";
    std::cout << "|         employee.                                        |\n";
    std::cout << "|      3. Search an Employee by ID                         |\n";
    std::cout << "|      4. Search an Employee by Name                       |\n";
    std::cout << "|                                                          |\n";
    std::cout << "|   (Enter -1 to go back to main menu)                     |\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Your Choice: ";
    cin >> sKey;
    cinBufferClear();
    return sKey;
}

int main(){
    bool sFlag = true;
    int sMenuCounter = 0;
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "|                Starting Employee Manager                 |\n";
    std::cout << "------------------------------------------------------------\n";

    XYZEmployeeManager sEmsObj;

    do{
        switch(sMenuCounter){
            case 0:{
                int sVal = mainMenu_1();
                if(sVal == -1){
                    sFlag = false;
                    break;
                }
                sMenuCounter = sVal;
                break;
            }
            case 1:{
                int sVal = mainMenu_2();
                if(sVal == -1){
                    sMenuCounter = 0;
                    break;
                }
                else if(sVal == 1){
                    sEmsObj.pAddEmpRandom();
                    // sEmsObj.displayEmpList();
                }
                else if(sVal == 2){
                    sEmsObj.pAddEmp();
                    sEmsObj.displayEmpList();
                }
                else{
                    cout<<"Enter a valid chpice\n";
                }
                break;
            }
            case 2:{
                cout<<"remove employee\n";
                std::string sID;
                cout<<"Enter the Employee ID: ";
                cin>>sID;
                cinBufferClear(); 
                sEmsObj.pRemove(sID);
                sEmsObj.displayResignedEmp();
                sMenuCounter = 0;
                break;
            }
            case 3:{
                int sVal = mainMenu_3();
                switch(sVal){
                    case -1:{
                        sMenuCounter = 0;
                        break;
                        }
                    case 1:{
                        sEmsObj.displayEmpList();
                        sEmsObj.displayResignedEmp();
                        break;
                    }
                    case 2:{
                        int sKey;
                        cout<<"\n1)FullTime"
                            <<"\n2)Contractor"
                            <<"\nIntern";
                        cout<<"\nYour Choice:";
                        cin>>sKey;
                        cinBufferClear();
                        if(sKey==1){//fulltime
                            sEmsObj.pDisplayFulltime();
                        }
                        else if(sKey==2){//contractor
                            sEmsObj.pDisplayContractor();
                        }
                        else if(sKey==3){//Intern
                            sEmsObj.pDisplayIntern();
                        }
                        else{
                            cout<<"\nEnter a valid choice\n";
                        }

                        break;
                    }
                    case 3:{
                        break;
                    }
                    case 4:{
                        int sKey;
                        cout<<"\n1)Active"
                            <<"\n2)Inactive"
                            <<"\nResigned";
                        cout<<"\nYour Choice:";
                        cin>>sKey;
                        cinBufferClear();
                        if(sKey==1){//Active
                            sEmsObj.pDisplayActiveEmp();
                        }
                        else if(sKey==2){//Inactive
                            sEmsObj.pDisplayInActiveEmp();
                        }
                        else if(sKey==3){//Resigned
                            sEmsObj.displayResignedEmp();
                        }
                        else{
                            cout<<"\nEnter a valid choice\n";
                        }
                        break;
                    }
                    case 5:{
                        sEmsObj.displayEmpList();
                        break;
                    }
                    default :{
                        cout<<"\nEnter a valid choice\n";
                        break;
                    }
                }
                break;
            }
            case 4:{
                int sVal = mainMenu_4();
                if(sVal == -1){
                    sMenuCounter = 0;
                    break;
                }
                else if(sVal == 1){
                    int sLeaves;
                    cout<<"Enter the Leaves";
                    cin>>sLeaves;
                    cinBufferClear();
                    sEmsObj.pAddLeaves(sLeaves);
                }
                else if(sVal==2){
                    std::string sID;
                    cout<<"Enter the ID";
                    cin>>sID;
                    cinBufferClear();
                    sEmsObj.makeFullTime(sID);
                }
                else if(sVal == 3){
                    //ID
                    std::string sID;
                    cout<<"Enter the ID : ";
                    cin>>sID;
                    cinBufferClear();
                    EmployeeIF* sObjPtr = sEmsObj.pSearchWithId(sID);
                    if(sObjPtr){
                        cout<<(*sObjPtr);
                    }
                    else{
                        cout<<"\nID not found\n";
                    }
                }
                else if(sVal == 4){
                    //name
                    std::string sName;
                    cout<<"Enter the Nmae : ";
                    cin>>sName;
                    cinBufferClear();
                    EmployeeIF* sObjPtr = sEmsObj.pSearchWithName(sName);
                    if(sObjPtr){
                        cout<<(*sObjPtr);
                    }
                    else{
                        cout<<"\nName not found\n";
                    }
                }
                else{
                    cout<<"\nEnter a valid choice\n";
                }
                break;
            }
            default:{
                sMenuCounter = 0;
                cout<<"\nEnter a Valid Choice\n";
                break;
            }
        }
    }while(sFlag);
    
    return 0;
}

void cinBufferClear(){
    cin.clear();                 // clear fail flag
    cin.ignore(10000, '\n') ;   // discard bad input

}








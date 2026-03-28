#include <iostream>
#include <random>
#include "EmpFullTime.H"
#include "EmpContractor.H"
#include "EmpIntern.H"
#include "Random.H"

using namespace std;


std::string createEmpID(uint32_t seqParm, uint8_t empType)
{
    char empTypeList[] = {'F','I','C'};
    std::string sPrefix = "XYZ";

    std::string num;

    if(seqParm < 10)
    {
        num = "000" + std::to_string(seqParm);
    }
    else if(seqParm < 100){
        num = "00" + std::to_string(seqParm);
    }
    else if(seqParm<1000){
        num = "0" + std::to_string(seqParm);
    }
    else{
        num = std::to_string(seqParm);
    }

    std::string sID = sPrefix + num + empTypeList[empType];
    return sID;
}

// Define arrays
const std::string Random::Name[10] = {"RAM","ELISA","JOHN","VICTORIA","ALBERT","MARIE","ALEX","ALEXA","BOB","SIRI"};
const std::string Random::status[2] = {"Active","Inactive"};
const std::string Random::agency[3] = {"AVENGERS","JUSTICE_LEAGUE","X_MEN"};
const std::string Random::branch[3] = {"CSE","CSIT","ECE"};
const std::string Random::collage[6] = {"IIT_DELHI","IIT_MUMBAI","IIT_KANPUR","IIT_HYDERABAD","NIT_WARANGAL","IIIT_HYDERABAD"};


int Random::getRandomNumber(int startNumParm,
                    int endNumParm)
{
    std::random_device sRandomDevice;
    std::mt19937 sRandomNumberGenerator(sRandomDevice());
    std::uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}


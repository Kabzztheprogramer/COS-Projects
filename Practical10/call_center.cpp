#include "call_center.h"
#include "exceptions.h"
#include "incoming.h"
#include "missed.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

CallCenter::CallCenter(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file)
    {
        return;
    }

    file >> numOperators;
    file >> callLimit;

    phones = new int[numOperators];
    for (int i = 0; i < numOperators; ++i)
    {

        int phoneCount;
        file >> phoneCount;
        phones[i] = phoneCount * 2;
    }

    operators = new CallHandler **[numOperators];
    for (int i = 0; i < numOperators; i++)
    {
        operators[i] = new CallHandler *[phones[i]];
        for (int j = 0; j < phones[i]; j++)
        {
            if (j % 2 == 0)
            {
                operators[i][j] = new Incoming(callLimit);
            }
            else
            {
                operators[i][j] = new Missed(callLimit);
            }
        }
    }

    file.close();
}

CallCenter::~CallCenter()
{
    for (int i = 0; i < numOperators; i++)
    {

        for (int j = 0; j < phones[i]; ++j)
        {
            delete operators[i][j];
        }
        delete[] operators[i];
    }
    delete[] operators;
    delete[] phones;
}

CallHandler ***CallCenter::getOperators()
{
    return operators;
}

int *CallCenter::getPhones()
{
    return phones;
}

int CallCenter::getNumOperators()
{
    return numOperators;
}

int CallCenter::getCallLimit()
{
    return callLimit;
}



void CallCenter::recieveCalls(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file)
    {
        return;
    }
    int TargetOperator;
    std::string line;
    std::stringstream ss;
    std::getline(file, line);
    ss<<line;
    ss>>TargetOperator;
    if (TargetOperator < 0 || TargetOperator >= numOperators)
    {
        return;
    }

    int i = 0;

    while (std::getline(file, line))
    {
       try{
        operators[TargetOperator][i]->addCall(line);
       }
       catch(const MissedCallsFull& e){

       }
       catch(const IncomingCallsFull& e){

       }
       catch(const CallTaken& e){

       }
        ++i;
        if (i >= phones[TargetOperator])
        {
            i = 0;
        }
    }
}


std::string CallCenter::takeCall(int op, int calls)
{
    if(op < numOperators && op >= 0 ){
        std::stringstream ss ;
        int j = 0;
        int i =  0;
        bool end = false ;

        while( i <= calls && j <= phones[op]-1 ){

            try{
                Call *call  = operators[op][j]->removeCall();
                ss<< call->displayDetails() <<"\n";
                delete call ;
                ++i ;
            } catch(const IncomingCallsEmpty& e){
                end = true ;
            }

            if(end == true || i == calls){
                j +=2;
                while( j < phones[op] ){
                    try{
                        Call *call  = operators[op][j]->removeCall();
                        ss<< call->displayDetails() <<"\n";
                        delete call ;
                    }catch( const IncomingCallsEmpty& e){
                    }
                    j +=2;      
                }
            }else{            
                j+=2;
                if(j>= phones[op]){
                    j = 0;
                }

            }
        

        }
        return ss.str();
    }else{
        throw OperatorNotFound() ;
    }
    
}

std::string CallCenter::callBack(int op, int calls)
{
    if(op < numOperators && op >= 0 ){
        std::stringstream ss ;
        int j = 1;
        int i =  0;
        bool end = false ;

        while( i <= calls && j <= phones[op]-1 ){

            try{
                Call *call  = operators[op][j]->removeCall();
                ss<< call->displayDetails() <<"\n";
                delete call ;
                ++i ;
            } catch(const MissedCallsEmpty& e){
                end = true ;
            }

            if(end == true || i == calls){
                j +=2;
                while( j <= phones[op]-1 ){
                    try{
                        Call *call  = operators[op][j]->removeCall();
                        ss<< call->displayDetails() <<"\n";
                        delete call ;
                    }catch( const MissedCallsEmpty& e){
                    }
                    j +=2;      
                }
            }else{            
                j+=2;
                if(j> phones[op]-1){
                    j = 1;
                }

            }
        

        }
        return ss.str();
    }else{
        throw OperatorNotFound() ;
    }
}

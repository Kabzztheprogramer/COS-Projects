#include <iostream>
#include <string>
#include <sstream>

#include "call.h"
#include "call_center.h"
#include "call_handler.h"
#include "incoming.h"
#include "missed.h"
#include "exceptions.h"

void  testIncomingQueue() {
    Incoming incomingQueue(3);
    try {
        std::cout << "Incoming queue is empty(Yes = 1 / No = 0) " << incomingQueue.isEmpty()<< std::endl;
        incomingQueue.addCall("call_1");
        incomingQueue.addCall("call_2");
        incomingQueue.addCall("call_3");
        std::cout << "Incoming queue after adding 3 calls:\n" << incomingQueue.callLog() << std::endl;
        std::cout << "Incoming queue is empty(Yes = 1 / No = 0) " << incomingQueue.isEmpty()<< std::endl;
        std::cout << "Incoming queue is full(Yes = 1 / No = 0) " << incomingQueue.isFull()<< std::endl;
        std::cout << "Trying to add to the Incoming queue sized with "<<incomingQueue.getSize()<<" call and is full :"<<std::endl <<"Outcome :"<<std::endl;
        incomingQueue.addCall("call_4");
    } catch (const IncomingCallsFull &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

      // Remove calls from the queue
    try {
        Call *removedCall1 = incomingQueue.removeCall();
        std::cout << "Removed: " << removedCall1->displayDetails() << std::endl;
        delete removedCall1;

        Call *removedCall2 = incomingQueue.removeCall();
        std::cout << "Removed: " << removedCall2->displayDetails() << std::endl;
        delete removedCall2;
    } catch (const IncomingCallsEmpty &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
void testMissedStack() {
    Missed missedStack(2);
    try {
        // Add calls to the stack
        missedStack.addCall("missed_1");
        missedStack.addCall("missed_2");
        std::cout << "Missed stack after adding 2 calls:\n" << missedStack.callLog() << std::endl;
        missedStack.addCall("missed_3");
    } catch (const MissedCallsFull &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Remove calls from the stack
    try {
        Call *removedCall = missedStack.removeCall();
        std::cout << "Removed: " << removedCall->displayDetails() << std::endl;
        delete removedCall;
    } catch (const MissedCallsEmpty &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
void printOperatorsArray(CallCenter &callCenter) {
    int numOperators = callCenter.getNumOperators();
    int *phones = callCenter.getPhones();
    CallHandler ***operators = callCenter.getOperators();
    for (int i = 0; i < numOperators; ++i) {
        std::cout << "Operator " << i << ":\n";
        for (int j = 0; j < phones[i] ; ++j) {
            std::string handlerType = (j % 2 == 0) ? "Incoming Queue" : "Missed Stack";
            std::cout << "  Phone " << (j / 2) << " - " << handlerType << ":\n";
            if (operators[i][j] != NULL) {
                std::cout << operators[i][j]->callLog() << std::endl;
            } else {
                std::cout << "    No calls in this " << handlerType << ".\n";
            }
        }
    }
}

void testCallCenter() {
    CallCenter callCenter("operators.txt");

    std::cout << "\nReceiving call at the center for operator 1 ......\n";
    try{
    callCenter.recieveCalls("call1.txt");
    } catch (const OperatorNotFound& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << "\nReceiving call at the center for operator 2 ......\n";
    try{
    callCenter.recieveCalls("call2.txt");
    } catch (const OperatorNotFound& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n Atrer receiving the calls operator logs : \n";
        printOperatorsArray(callCenter);
        std::cout << "\nTaking call at the center for operator 1 ......\n";
        try{
        std::cout<<callCenter.takeCall(0, 5);
        }catch (const OperatorNotFound& e){
        std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\nCalling back at the center for operator 1 ......\n";
        try{
            std::cout<< callCenter.callBack(0,4);
        }catch(const OperatorNotFound& e){
        std::cout << "Exception: " << e.what() << std::endl;    
        }
    

}
int main()
{
    std::cout << "Testing Incoming Queue:\n";
    testIncomingQueue();
    std::cout << std::endl <<"Testing Missed Stack:\n";
    testMissedStack();

    std::cout << "\nTesting Call Center:\n";
    testCallCenter();
    
    return 0;
}

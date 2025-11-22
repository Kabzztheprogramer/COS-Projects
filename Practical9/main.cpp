#include <cstdio>
#include <iostream>

#include "DoublyNode.h" 
#include "DoublyList.h" 
void testFirstYearInRes() {
    DoublyList<std::string> resLife;  // Create a doubly linked list to store first-year experiences

    std::cout << "First-Year in RES Experience Simulation:" << std::endl;

    // Insert some typical first-year experiences
    resLife.insert("Move into RES", 1);
    resLife.insert("Meet roommate", 2);
    resLife.insert("Attend first lecture", 3);
    resLife.insert("Forget to bring umbrella", 4);
    resLife.insert("Join a club", 5);
    resLife.insert("Late to class", -1); // Adding to the end
    resLife.insert("Party on Friday", -1); // Adding to the end
    resLife.insert("Miss dinner", -1); // Adding to the end
    resLife.insert("Sleep through alarm", 1); // Insert at the beginning

    // Print the initial list
    std::cout << "\nInitial list of experiences:\n";
    std::cout << resLife.toString() << std::endl;

    // Test: Search for specific experiences
    std::cout << "\nSearching for occurrences of 'Late to class': " << std::endl;
    std::cout << "Occurrences of 'Late to class': " << resLife.contains("Late to class") << std::endl;

    // Test: Remove specific experiences
    std::cout << "\nRemoving 'Miss dinner' from the list:" << std::endl;
    int removed = resLife.remove("Miss dinner");
    std::cout << removed << " occurrence(s) of 'Miss dinner' removed." << std::endl;

    // Print the list after removing "Miss dinner"
    std::cout << "\nList of experiences after removing 'Miss dinner':\n";
    std::cout << resLife.toString() << std::endl;

    // Insert some more experiences to see how it adjusts
    std::cout << "\nInserting more experiences:\n";
    resLife.insert("Study for midterms", 3); // Insert at position 3
    resLife.insert("Watch Netflix", -1);     // Insert at the end

    // Print the updated list
    std::cout << "Updated list of experiences:\n";
    std::cout << resLife.toString() << std::endl;

    // Test: Count how many times certain experiences occur
    std::cout << "\nCounting occurrences of 'Watch Netflix':\n";
    int netflixCount = resLife.contains("Watch Netflix");
    std::cout << "'Watch Netflix' occurs " << netflixCount << " time(s) in the list." << std::endl;

    // Final removal of an experience and print final list
    std::cout << "\nRemoving 'Sleep through alarm' from the list:\n";
    int alarmRemoved = resLife.remove("Sleep through alarm");
    std::cout << alarmRemoved << " occurrence(s) of 'Sleep through alarm' removed." << std::endl;

    // Print final list
    std::cout << "\nFinal list of experiences:\n";
    std::cout << resLife.toString() << std::endl;

    // End of test
    std::cout << "\nFirst-year in RES simulation complete!" << std::endl;
}

int main(){
    DoublyList<int>DL1;
    DL1.insert(10,1);
    DL1.insert(15,2);
    DL1.insert(20,2);
    DL1.insert(20,-2);
    DL1.insert(20,-1);
    DoublyList<int>DL2 = DL1 ;
    std::cout<<DL1.toString()<<std::endl;
    std::cout<<"Number of 1st year that are aged 20's = " << DL1.contains(20)<<std::endl;
    std::cout<<DL2.toString()<<std::endl;
    std::cout<<"Number of 1st year that are aged 20's and removed from RES = " << DL1.remove(20)<<std::endl;
    std::cout<<"Number of 1st year that are aged 15's and removed from RES = " << DL1.remove(15)<<std::endl;
     std::cout<<"Number of 1st year that are aged 15's and removed from RES = " << DL1.remove(10)<<std::endl;
    std::cout<<DL1.toString()<<std::endl;
    DL1.insert(20,-1);
    std::cout<<DL1.toString()<<std::endl;
    testFirstYearInRes() ;

    return 0 ;
}

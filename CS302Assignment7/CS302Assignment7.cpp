// CS302Assignment7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "hashMap.h"

int main()
{
    std::string fileName = "";
    std::string myString = "";
    std::ifstream myfile;

    std::cout << "Enter Filename: ";
    std::cin >> fileName;

    myfile.open(fileName);


    // checks if the file was able to be opened
    if (!myfile.is_open())
    {
        std::cout << "This file was not able to be opened.\n\n";
        return 0;
    }

    myfile >> myString;
    int testCases = stoi(myString);
    
    for (int i = 0; i < testCases; i++)
    {
        myfile >> myString;
        int numOfCandidates = stoi(myString);

        std::unordered_map<std::string, std::string> canToParty;
        std::unordered_map<std::string, int> canToVotes;
        std::vector<std::string> candidates;

        getline(myfile, myString);

        // assigns candidates to their respective parties
        for (int j = 0; j < numOfCandidates; j++)
        {
            getline(myfile, myString);
            std::string candidate = myString;
            candidates.push_back(candidate);

            getline(myfile, myString);
            std::string party = myString;

            canToParty[candidate] = party;
        }

        myfile >> myString;
        int votes = stoi(myString);

        getline(myfile, myString);

        // counts how many votes each candidate got
        for (int j = 0; j < votes; j++)
        {
            getline(myfile, myString);

            canToVotes[myString]++;
        }

        int currentVotes = 0;
        int highestVotes = 0;
        std::string winningParty = "";
        std::string tie = "Tie";

        for (int j = 0; j < numOfCandidates; j++)
        {
            currentVotes = canToVotes[candidates[j]];

            if (currentVotes > highestVotes)
            {
                highestVotes = currentVotes;
                winningParty = canToParty[candidates[j]];
            }
            else if (currentVotes == highestVotes)
            {
                winningParty = tie;
            }
        
        }

        std::cout << "Case " << i+1 << " Results: " << winningParty << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

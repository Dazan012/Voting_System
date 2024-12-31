#include <iostream>
#include <string>
#include <map>

using namespace std;

class VotingSystem
{
private:
    map<string, int> candidates; // Candidate name and their vote count
    map<string, bool> voters;    // Voter ID and their voting status
    bool isVotingOpen;

public:
    VotingSystem() : isVotingOpen(false) {}

    void openVoting()
    {
        isVotingOpen = true;
        cout << "Voting is now open!" << endl;
    }

    void closeVoting()
    {
        isVotingOpen = false;
        cout << "Voting has been closed!" << endl;
    }

    void registerCandidate(const string &candidateName)
    {
        if (candidates.find(candidateName) == candidates.end())
        {
            candidates[candidateName] = 0; // Initialize vote count to 0
            cout << "Candidate " << candidateName << " registered successfully." << endl;
        }
        else
        {
            cout << "Candidate already exists." << endl;
        }
    }

    void vote(const string &voterId, const string &candidateName)
    {
        if (!isVotingOpen)
        {
            cout << "Voting is not open!" << endl;
            return;
        }

        if (voters.find(voterId) != voters.end())
        {
            cout << "You have already voted!" << endl;
            return;
        }

        if (candidates.find(candidateName) == candidates.end())
        {
            cout << "Candidate does not exist." << endl;
            return;
        }

        // Record the vote
        candidates[candidateName]++;
        voters[voterId] = true; // Mark voter as having voted
        cout << "Vote cast successfully for " << candidateName << "." << endl;
    }

    void displayResults() const
    {
        cout << "\n--- Voting Results ---" << endl;
        for (const auto &candidate : candidates)
        {
            cout << candidate.first << ": " << candidate.second << " votes" << endl;
        }
    }
};

int main()
{
    VotingSystem votingSystem;

    int choice;
    string candidateName, voterId;

    while (true)
    {
        cout << "\n--- Voting System Menu ---" << endl;
        cout << "1. Open Voting" << endl;
        cout << "2. Close Voting" << endl;
        cout << "3. Register Candidate" << endl;
        cout << "4. Vote" << endl;
        cout << "5. Display Results" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            votingSystem.openVoting();
            break;

        case 2:
            votingSystem.closeVoting();
            break;

        case 3:
            cout << "Enter candidate name: ";
            cin >> candidateName;
            votingSystem.registerCandidate(candidateName);
            break;

        case 4:
            cout << "Enter your voter ID: ";
            cin >> voterId;
            cout << "Enter candidate name to vote for: ";
            cin >> candidateName;
            votingSystem.vote(voterId, candidateName);
            break;

        case 5:
            votingSystem.displayResults();
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

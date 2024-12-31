#include <iostream>
#include <string>
#include <map>

using namespace std;

class Voting_System
{
private:
    /* data */
public:
    Voting_System(/* args */);
    ~Voting_System();
};

Voting_System::Voting_System(/* args */)
{
}

Voting_System::~Voting_System()
{
}
VotingSystem
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

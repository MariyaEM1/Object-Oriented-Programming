#pragma once
#include "SectionVotes.hpp"
#include <iostream>
#include <fstream>
#include <vector>

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

class ElectionResultsDatabase
{
    std::vector<SectionVotes> VotesBySections;

public:

    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party PartyX) const;

    Party winningParty() const;

    friend std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& Votes);
    friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
};
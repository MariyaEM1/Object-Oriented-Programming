#include "ElectionResultsDatabase.hpp"
#include "SectionVotes.hpp"
#include<iostream>
#include <vector>

void ElectionResultsDatabase::addResultsFromFile(const char* filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        return;
    }
    inFile >> *this;
}

int ElectionResultsDatabase::numberOfSections() const {
	return VotesBySections.size();
}

int ElectionResultsDatabase::votesForParty(Party PartyX) const {
    int Allvotes = 0;
    for (unsigned int i = 0; i < VotesBySections.size(); i++) {
        Allvotes += VotesBySections[i].votesForParty(PartyX);
    }
    return Allvotes;
}

Party ElectionResultsDatabase::winningParty() const {
    if (votesForParty(PARTY3) > votesForParty(PARTY2) && votesForParty(PARTY3) > votesForParty(PARTY1)) {
        return Party::PARTY3;
    }
    else if (votesForParty(PARTY2) >= votesForParty(PARTY3) && votesForParty(PARTY2) > votesForParty(PARTY1)) {
        return Party::PARTY2;
    }
    else if(votesForParty(PARTY1) >= votesForParty(PARTY2) && votesForParty(PARTY1) >= votesForParty(PARTY3)) {
        return Party::PARTY1;
    }
    return PARTY1;
}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& Votes)
{
    for (unsigned int i = 0; i < Votes.VotesBySections.size(); i++) {
        out << Votes.VotesBySections[i].votesForParty(PARTY1) << " " << Votes.VotesBySections[i].votesForParty(PARTY2) << " " << Votes.VotesBySections[i].votesForParty(PARTY3) << '\n';
    }
    return out;
}

std::istream& operator>>(std::istream& in, ElectionResultsDatabase& Votes)
{
    SectionVotes VotesBySections;
    while (in >> VotesBySections) {
        Votes.VotesBySections.push_back(VotesBySections);
    }
    return in;
}


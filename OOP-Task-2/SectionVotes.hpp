#pragma once
#include<iostream>

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{

public:

    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;

    SectionVotes();

    int getParty1()const;
    int getParty2()const;
    int getParty3()const;

    friend std::istream& operator>>(std::istream& in, SectionVotes& OneSection);
    friend std::ostream& operator<<(std::ostream& out, const SectionVotes& OneSection);

    int party1, party2, party3;

};
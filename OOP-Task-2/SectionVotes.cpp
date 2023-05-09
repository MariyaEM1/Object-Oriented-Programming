#include "SectionVotes.hpp"
#include <iostream>
#include <vector>

using namespace std;

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes) {
	party1 = party1Votes;
	party2 = party2Votes;
	party3 = party3Votes;
}
int SectionVotes::votesForParty(Party PartyX) const {
	if (PartyX == PARTY1) {
		return party1;
	}
	else if (PartyX == PARTY2) {
		return party2;
	}
	else return party3;

}

SectionVotes::SectionVotes() {
	party1 = 0;
	party2 = 0;
	party3 = 0;
}

int SectionVotes::getParty1()const {
	return party1;
}
int SectionVotes::getParty2()const {
	return party2;
}
int SectionVotes::getParty3()const {
	return party3;
}

std::istream& operator>>(std::istream& in, SectionVotes& OneSection) {
	in >> OneSection.party1 >> OneSection.party2 >> OneSection.party3;
	return in;
}
std::ostream& operator<<(std::ostream& out, const SectionVotes& OneSection) {
	out << OneSection.party1 <<" "<< OneSection.party2 <<" "<< OneSection.party3<<endl;
	return out;
}
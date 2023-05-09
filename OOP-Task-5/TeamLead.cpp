#include"TeamLead.hpp"

TeamLead::TeamLead(const string& name, const double salary) : Developer(name, salary)
{
	teamlead = this;
}
vector<Developer*> TeamLead::getTeam()
{
	return Developers;
}
void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	developer->setTeamLead(this);
	Developers.push_back(developer);
	developer->setInitialSalary(salary);
}
void TeamLead::removeDeveloperFromTeam(const string& name) 
{
	int num = -1;
	for (unsigned int i = 0; i < Developers.size(); i++)
	{
		if (Developers[i]->getName() == name) {
			num = i;
		}
	}
	if (num >= 0) {
		Developers[num]->setTeamLead(nullptr);
		Developers.erase(Developers.begin() + num);
	}
}
void TeamLead::increaseTeamSalariesBy(double amount) 
{
	for (unsigned int i = 0; i < Developers.size(); i++) {
		Developers[i]->increaseSalary(amount);
	}
}
void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (unsigned int i = 0; i < Developers.size(); i++) {
		Developers[i]->decreaseSalary(amount);
	}
}
void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	LeavingRequests.push_back(leavingRequest);
}
void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	PromotionRequests.push_back(promotionRequest);
}
void TeamLead::fulfillLeavingRequests()
{
	for (unsigned int i = 0; i < Developers.size(); i++) {
		for (unsigned int j = 0; j < LeavingRequests.size(); j++) {
			if (Developers[i]->getName() == LeavingRequests[j].getSender()) {
				Developers[i]->setTeamLead(nullptr);
				Developers.erase(Developers.begin() + i);
				i--;
			}
		}
	}
	LeavingRequests.clear();
}
void TeamLead::fulfillPromotionRequests()
{
	for (unsigned int i = 0; i < Developers.size(); i++) {
		for (unsigned int j = 0; j < PromotionRequests.size(); j++) {
			if (Developers[i]->getName() == PromotionRequests[j].getSender()) {
				Developers[i]->increaseSalary(PromotionRequests[j].getAmount());
			}
		}
	}
	PromotionRequests.clear();
}
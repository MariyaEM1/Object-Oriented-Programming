#pragma once
#include"Request.hpp"

class PromotionRequest: public Request
{
private:
	double amount;
public:
	PromotionRequest(const string& sender, double amount);
	double getAmount() const;
};
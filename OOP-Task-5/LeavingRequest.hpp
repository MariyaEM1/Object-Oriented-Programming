#pragma once
#include<string>
#include "Request.hpp"

class LeavingRequest : public Request
{
public:
	LeavingRequest(const std::string& sender);
};
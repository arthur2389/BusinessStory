// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H
#pragma once

#include <vector>
#include <memory>
#include <string>
#include "FiscalYear.h"

static const std::string PROFILES[]{"None", "Low", "Medium", "High"}	

class TimePeriod  
{
	public:

		TimePeriod() {}; 

		// Setters 
		void set_retrun_on_capital(std::string& earnings_list);
		void set_retrun_on_capital(std::string& earnings_avarage, std::string& earnings_std_deviation);
		void set_capital_distribution_profile(std::string& capital_distribution_profile);
		void set_debt_issuance_profile(std::string& debt_issuance_profile);
		void set_debt_repayment_profile(std::string& debt_repayment_profile);
		void set_paid_in_capital_profile(std::string& paid_in_capital_profile);

		// Getters
		std::string& get_return_on_capital_list();
		std::string& get_return_on_capital_avarage();



		std::vector<std::shared_ptr<FiscalYear>> build_years();

		~TimePeriod() {}

	private:
		std::string m_retrun_on_capital_list{""};
		std::string m_return_on_capital_avarage{""};
		std::string m_return_on_capital_std_deviation{""};
		std::string m_capital_distribution_profile{PROFILES[0]};
		std::string m_debt_issuence_profile{PROFILES[0]};
		std::string m_debt_repayment{PROFILES[0]};
		std::string m_paid_in_capital{PROFILES[0]};
};
#endif
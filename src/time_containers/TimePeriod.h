// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H
#pragma once

#include <vector>
#include <memory>
#include <string>
#include <tuple>
#include "FiscalYear.h"

static const std::string PROFILES[]{"None", "Low", "Medium", "High"};	
// Taking advantage of the fact the all fiscal numbers are ammounts (positive)
static const double UNDEFINED = -1;

class TimePeriod  
{
	public:

		enum FIELD_STATUS {
			VALID = 0, 
			NOT_A_NUMBER = 1,
			NEGATIVE_NUMBER = 2, 
			BAD_PROFILE_NAME = 3								
		};

		TimePeriod() {}
		~TimePeriod() {}

		// Setters 
		FIELD_STATUS set_num_of_years(const std::string&num_of_years);
		FIELD_STATUS set_tax_rate(const std::string& tax_rate);
		FIELD_STATUS set_debt_interest_rate(const std::string& debt_interest_rate);
		FIELD_STATUS set_return_on_capital(const std::string& roc_list) {return VALID;};
		FIELD_STATUS set_return_on_capital(const std::string& roc_average,
								           const std::string& roc_std_deviation);
		FIELD_STATUS set_capital_distribution_profile(const std::string& capital_distribution_profile);
		FIELD_STATUS set_debt_issuance_profile(const std::string& debt_issuance_profile);
		FIELD_STATUS set_debt_repayment_profile(const std::string& debt_repayment_profile);
		FIELD_STATUS set_paid_in_capital_profile(const std::string& paid_in_capital_profile);

		// Getters
		// ToDo implement getters
		std::string& get_tax_rate() const;
		std::string& get_debt_interest_rate() const;
		std::string& get_return_on_capital_avarage() const;
		std::string& get_return_on_capital_std_deviation() const;
		std::string& get_capital_distribution_profile() const;
		std::string& get_debt_issuance_profile() const;
		std::string& get_debt_repayment_profile() const;
		std::string& get_paid_in_capital_profile() const;

		std::vector<std::shared_ptr<FiscalYear>> build_years();

	private:
		bool is_defined(std::tuple<std::string, double> field);
		std::tuple<FIELD_STATUS, double> convert_to_valid_numeric(const std::string& as_string);
		// ToDo implement function
		FIELD_STATUS assert_profile_name(const std::string& pname) {return VALID;};

		std::tuple<std::string, double> m_tax_rate{"", UNDEFINED};
		std::tuple<std::string, double> m_debt_interest_rate{"", UNDEFINED};
		std::tuple<std::string, int> m_num_years_in_period{"", UNDEFINED};
		std::tuple<std::string, std::vector<double>> m_retrun_on_capital_list{"", {UNDEFINED}};
		std::tuple<std::string, double> m_return_on_capital_avarage{"", UNDEFINED};
		std::tuple<std::string, double> m_return_on_capital_std_deviation{"", UNDEFINED};
		std::string m_capital_distribution_profile{PROFILES[0]};
		std::string m_debt_issuence_profile{PROFILES[0]};
		std::string m_debt_repayment_profile{PROFILES[0]};
		std::string m_paid_in_capital_profile{PROFILES[0]};
};
#endif
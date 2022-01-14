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
#include "Types.h"

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

		TimePeriod();

		// Setters 
		FIELD_STATUS set_num_of_years(const std::string&num_of_years);
		FIELD_STATUS set_tax_rate(const std::string& tax_rate);
		FIELD_STATUS set_debt_interest_rate(const std::string& debt_interest_rate);
		FIELD_STATUS set_return_on_capital_list(const std::string& roc_list) {return VALID;};
		FIELD_STATUS set_return_on_capital_average(const std::string& roc_average);
		FIELD_STATUS set_return_on_capital_range(const std::string& roc_range);
		FIELD_STATUS set_capital_distribution_profile(const std::string& capital_distribution_profile);
		FIELD_STATUS set_debt_issuance_profile(const std::string& debt_issuance_profile);
		FIELD_STATUS set_debt_repayment_profile(const std::string& debt_repayment_profile);
		FIELD_STATUS set_paid_in_capital_profile(const std::string& paid_in_capital_profile);

		// Getters
		// ToDo implement getters
		std::string& get_tax_rate() const;
		std::string& get_debt_interest_rate() const;
		std::string& get_return_on_capital_avarage() const;
		std::string& get_return_on_capital_range() const;
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
		std::map<std::string, PROFILE> m_profile_conversion =
			 {{"None",   PROFILE::P_NONE},
			  {"Low",    PROFILE::P_LOW}, 
			  {"Medium", PROFILE::P_MEDIUM}, 
			  {"High",   PROFILE::P_HIGH}}; 

		std::pair<std::string, double> m_tax_rate;
		std::pair<std::string, double> m_debt_interest_rate;
		std::pair<std::string, int> m_num_years_in_period;
		std::pair<std::string, std::vector<double>> m_retrun_on_capital_list;
		std::pair<std::string, double> m_return_on_capital_avarage;
		std::pair<std::string, double> m_return_on_capital_range;
		std::pair<std::string, PROFILE> m_capital_distribution_profile;
		std::pair<std::string, PROFILE> m_debt_issuence_profile;
		std::pair<std::string, PROFILE> m_debt_repayment_profile;
		std::pair<std::string, PROFILE> m_paid_in_capital_profile;

};
#endif
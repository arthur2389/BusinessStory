// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef FISCALYEAR_H
#define FISCALYEAR_H
#pragma once

#include <vector>
#include <memory>
#include <string>
#include <map>

#include "Assets.h"
#include "AssetFlowAction.h"
#include "CapitalDistribution.h"
#include "DebtIssuance.h"
#include "DebtRepayment.h"
#include "Earnings.h"
#include "PaidInCapital.h"

class FiscalYear  
{
	public:

		struct year_10k
		{
			double equity;
			double debt;
			double earnings;
		};

		FiscalYear(double interest_rate, double tax_rate);
		void set_return_on_capital(double return_on_capital);
		void set_debt_issuance(std::string& profile);
		void set_paid_in_capital(std::string& profile);
		void set_debt_repayment(std::string& profile);
		void set_capital_distribution(std::string& profile);

		void go_through(Assets& assets);
		year_10k& get_year_10k(); 

		~FiscalYear() {};

	private:
		std::vector<std::unique_ptr<AssetFlowAction>> m_asset_flows;
		double m_interest_rate;
		double m_tax_rate;
		bool m_earnings_set;
		year_10k m_year_10k{0};
		std::map<std::string, AssetFlowAction::PROFILE> m_profile_conversion =
			 {{"Low",    AssetFlowAction::PROFILE::P_LOW}, 
			  {"Medium", AssetFlowAction::PROFILE::P_MEDIUM}, 
			  {"High",   AssetFlowAction::PROFILE::P_HIGH}}; 
};
#endif

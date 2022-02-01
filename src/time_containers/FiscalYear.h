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
#include "Types.h"
#include "CapitalDistribution.h"
#include "DebtIssuance.h"
#include "DebtRepayment.h"
#include "Earnings.h"
#include "PaidInCapital.h"

class FiscalYear  
{
	public:

		FiscalYear(double interest_rate, double tax_rate);
		void set_return_on_capital(double return_on_capital);
		void set_debt_issuance(PROFILE profile);
		void set_paid_in_capital(PROFILE profile);
		void set_debt_repayment(PROFILE profile);
		void set_capital_distribution(PROFILE profile);

		void go_through(Assets& assets);
		year_10k& get_year_10k(); 

	private:
		std::vector<std::unique_ptr<AssetFlowAction>> m_asset_flows;
		double m_interest_rate;
		double m_tax_rate;
		bool m_earnings_set;
		year_10k m_year_10k{0};
};
#endif

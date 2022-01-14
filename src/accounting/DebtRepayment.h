// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef DEBTREPAYMENT_H
#define DEBTREPAYMENT_H
#pragma once

#include "AssetFlowAction.h"
#include <algorithm>

class DebtRepayment : public AssetFlowAction 
{

	public:
		DebtRepayment(PROFILE profile);
		virtual void update_assets(Assets& assets, year_10k& y10k) override;

	private:
		std::map<PROFILE, double> m_paid_out_of_total_debt = {{PROFILE::P_LOW,    8.0},
														      {PROFILE::P_MEDIUM, 12.0},
															  {PROFILE::P_HIGH,   25.0}};
		std::map<PROFILE, double> m_paid_out_of_equity = {{PROFILE::P_LOW,    15.0},
														  {PROFILE::P_MEDIUM, 20.0},
														  {PROFILE::P_HIGH,   30.0}};
};

#endif
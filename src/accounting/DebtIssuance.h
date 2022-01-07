// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef DEBTISSUANCE_H
#define DEBTISSUANCE_H
#pragma once

#include "AssetFlowAction.h"
#include <algorithm>


class DebtIssuance : public AssetFlowAction 
{
	public:
		DebtIssuance(PROFILE); 
		virtual void update_assets(Assets& assets) override;

	private:
		std::map<PROFILE, double> m_debt_of_equity = {{P_LOW,    15.0},
				 					                  {P_MEDIUM, 25.0},
    								  			      {P_HIGH,   50.0}};

		std::map<PROFILE, double> m_debt_of_curr_debt = {{P_LOW,    10.0},
				 						                 {P_MEDIUM, 20.0},
    								  			         {P_HIGH,   30.0}};
};
#endif
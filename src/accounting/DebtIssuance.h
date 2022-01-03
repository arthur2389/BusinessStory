#ifndef DEBTISSUANCE_H
#define DEBTISSUANCE_H
#pragma once

#include "AssetFlowAction.h"
#include <algorithm>


class DebtIssuance : public AssetFlowAction 
{
	public:

		virtual void update_assets(Assets& assets) override;

	private:
		std::map<AssetFlowAction::PROFILE, double> m_debt_of_equity = {{P_LOW,    15.0},
				 						                               {P_MEDIUM, 25.0},
    								  				                   {P_HIGH,   50.0}};

		std::map<AssetFlowAction::PROFILE, double> m_debt_of_curr_debt = {{P_LOW,    60.0},
				 						                                  {P_MEDIUM, 40.0},
    								  				                      {P_HIGH,   20.0}};
};
#endif
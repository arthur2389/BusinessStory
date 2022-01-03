#ifndef DEBTREPAYMENT_H
#define DEBTREPAYMENT_H
#pragma once

#include "AssetFlowAction.h"
#include <algorithm>

class DebtRepayment : public AssetFlowAction 
{

	public:

		virtual void update_assets(Assets& assets) override;

	private:
		std::map<AssetFlowAction::PROFILE, double> m_paid_out_of_total_debt = {{P_LOW,    8.0},
				 						                                       {P_MEDIUM, 12.0},
    								  				                           {P_HIGH,   25.0}};
		std::map<AssetFlowAction::PROFILE, double> m_paid_out_of_equity = {{P_LOW,    15.0},
				 						                                   {P_MEDIUM, 20.0},
    								  				                       {P_HIGH,   30.0}};
};

#endif
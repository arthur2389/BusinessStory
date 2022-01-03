#ifndef PAIDINCAPITAL_H
#define PAIDINCAPITAL_H
#pragma once
	
#include "AssetFlowAction.h"

class PaidInCapital : public AssetFlowAction 
{
	public:
		virtual void update_assets(Assets& assets) override;

	private:
		std::map<AssetFlowAction::PROFILE, double> m_paid_in_of_total_assets = {{P_LOW,    2.0},
				 						                                        {P_MEDIUM, 7.0},
    								  				                            {P_HIGH,   13.0}};
};
#endif
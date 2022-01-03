#ifndef CAPITALDISTRIBUTION_H
#define CAPITALDISTRIBUTION_H
#pragma once

#include "AssetFlowAction.h"

class CapitalDistribution : public AssetFlowAction 
{
	public:

		virtual void update_assets(Assets& assets) override;

	private:
		std::map<AssetFlowAction::PROFILE, double> m_paid_of_equity = {{P_LOW,    2.0},
				 						                               {P_MEDIUM, 8.0},
    								  				                   {P_HIGH,   11.0}};

};
#endif
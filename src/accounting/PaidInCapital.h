// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef PAIDINCAPITAL_H
#define PAIDINCAPITAL_H
#pragma once
	
#include "AssetFlowAction.h"

class PaidInCapital : public AssetFlowAction 
{
	public:
		PaidInCapital(PROFILE profile);
		virtual void update_assets(Assets& assets, year_10k& y10k) override;

	private:
		std::map<PROFILE, double> m_paid_in_of_total_assets = {{PROFILE::P_LOW,    2.0},
				 			                                   {PROFILE::P_MEDIUM, 7.0},
    								  				           {PROFILE::P_HIGH,   13.0}};
};
#endif
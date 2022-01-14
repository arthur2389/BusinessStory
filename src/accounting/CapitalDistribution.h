// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef CAPITALDISTRIBUTION_H
#define CAPITALDISTRIBUTION_H
#pragma once

#include "AssetFlowAction.h"

class CapitalDistribution : public AssetFlowAction 
{
	public:

		CapitalDistribution(PROFILE profile);
		virtual void update_assets(Assets& assets, year_10k& y10k) override;

	private:
		std::map<PROFILE, double> m_paid_of_equity = {{PROFILE::P_LOW,    2.0},
				 		                              {PROFILE::P_MEDIUM, 8.0},
    						 	                      {PROFILE::P_HIGH,   11.0}};

};
#endif
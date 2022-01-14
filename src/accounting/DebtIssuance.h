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
		virtual void update_assets(Assets& assets, year_10k& y10k) override;

	private:
		std::map<PROFILE, double> m_debt_of_assets = {{PROFILE::P_LOW,    5.0},
				 					                  {PROFILE::P_MEDIUM, 20.0},
    								  			      {PROFILE::P_HIGH,   35.0}};
};
#endif
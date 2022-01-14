// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef EARNINGS_H
#define EARNINGS_H
#pragma once

#include "AssetFlowAction.h"


class Earnings: public AssetFlowAction  
{
	public:

		Earnings();
		Earnings(double return_on_capital,
                 double debt_interest, 
                 double tax_perc);
		virtual void update_assets(Assets& assets, year_10k& y10k) override;

	private:
	    double m_return_on_capital;
		double m_debt_interest;
		double m_tax_perc;
};
#endif
#ifndef DEBTINTEREST_H
#define DEBTINTEREST_H
#pragma once

#include "AssetFlowAction.h"

class DebtInterest: public AssetFlowAction 
{
	public:

		DebtInterest();
		DebtInterest(double interest_rate);
		virtual void update_assets(Assets& assets) override;

	private:
		double m_interest_rate;

};
#endif
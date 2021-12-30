#ifndef SRC/ACCOUNTING/DEBTINTEREST_H
#define SRC/ACCOUNTING/DEBTINTEREST_H
#pragma once

#include "AssetFlowAction.h"

class DebtInterest: public AssetFlowAction 
{
	public:

		DebtInterest();
		DebtInterest(double interest_rate);
		void update_assets(Assets& assets);

	private:
		double m_interest_rate;

};
#endif
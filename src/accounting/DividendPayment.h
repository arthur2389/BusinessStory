#ifndef DIVIDENDPAYMENT_H
#define DIVIDENDPAYMENT_H
#pragma once
	
#include "AssetFlowAction.h"

class DividendPayment : AssetFlowAction 
{
	public:
		DividendPayment();
		DividendPayment(double percent_of_assets);
		void update_assets(Assets& assets);

	private:
		double m_percent_of_equity;

};
#endif
#ifndef DIVIDENDPAYMENT_H
#define DIVIDENDPAYMENT_H
#pragma once
	
#include "AssetFlowAction.h"

class DividendPayment :public AssetFlowAction 
{
	public:
		DividendPayment();
		DividendPayment(double percent_of_assets);
		virtual void update_assets(Assets& assets) override;

	private:
		double m_percent_of_equity;

};
#endif
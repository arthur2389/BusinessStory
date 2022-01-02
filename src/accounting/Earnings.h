#ifndef EARNINGS_H
#define EARNINGS_H
#pragma once

#include "AssetFlowAction.h"


class Earnings: public AssetFlowAction  
{
	public:

		Earnings();
		Earnings(double return_on_capital);
		virtual void update_assets(Assets& assets) override;

	private:
	    double m_return_on_capital;
};
#endif
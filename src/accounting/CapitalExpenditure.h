#ifndef CAPITALEXPENDITURE_H
#define CAPITALEXPENDITURE_H
#pragma once

#include "AssetFlowAction.h"

class CapitalExpenditure: public AssetFlowAction   
{
	public:

		CapitalExpenditure();
		CapitalExpenditure(double capex);
		virtual void update_assets(Assets& assets) override;

	private:
		double m_capex;
};
#endif
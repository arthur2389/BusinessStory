#ifndef LOANISSUANCE_H
#define LOANISSUANCE_H
#pragma once

#include "AssetFlowAction.h"

class LoanIssuance: public AssetFlowAction  
{
	public:
		LoanIssuance();
		LoanIssuance(double issued_loan);
		virtual void update_assets(Assets& assets) override;

	private:
		double m_issued_loan;
};
#endif
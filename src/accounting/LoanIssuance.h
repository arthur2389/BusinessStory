#ifndef LOANISSUANCE_H
#define LOANISSUANCE_H
#pragma once

#include "AssetFlowAction.h"

class LoanIssuance: public AssetFlowAction  
{
	public:
		LoanIssuance();
		LoanIssuance(double issued_loan);
		void update_assets(Assets& assets);

	private:
		double m_issued_loan;
};
#endif
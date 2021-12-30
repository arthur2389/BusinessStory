#ifndef LOANISSUANCE_H
#define LOANISSUANCE_H
#pragma once

#include "AssetFlowAction.h"

class LoanIssuance: public AssetFlowAction  
{
	public:
		LoanIssuance();
		LoanIssuance(int issued_loan);
		void update_assets(Assets& assets);

	private:
		int m_issued_loan;
};
#endif
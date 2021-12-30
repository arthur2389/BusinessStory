#include "LoanIssuance.h"  
	
LoanIssuance::LoanIssuance() {}

LoanIssuance::LoanIssuance(int issued_loan): m_issued_loan{issued_loan} {}

void LoanIssuance::update_assets(Assets& assets)
{
    assets.add_debt(m_issued_loan);
}

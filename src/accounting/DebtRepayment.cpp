#include "DebtRepayment.h"  
	
void DebtRepayment::update_assets(Assets& assets)
{
    double repayment = std::min(m_paid_out_of_total_debt[m_profile], 
                                m_paid_out_of_equity[m_profile]);
    assets.add_debt(-repayment);
}

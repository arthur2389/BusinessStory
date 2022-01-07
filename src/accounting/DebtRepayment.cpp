#include "DebtRepayment.h"  

DebtRepayment::DebtRepayment(PROFILE profile): AssetFlowAction{profile} {} 

void DebtRepayment::update_assets(Assets& assets)
{
    double repayment = std::min(percent_of(assets.get_debt(), m_paid_out_of_total_debt[m_profile]), 
                                percent_of(assets.get_equity(), m_paid_out_of_equity[m_profile]));
    assets.add_debt(-repayment);
}

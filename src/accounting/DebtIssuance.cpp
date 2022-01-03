#include "DebtIssuance.h"  
	
void DebtIssuance::update_assets(Assets& assets)
{
    // Debt will be a product of the equity - but also will be moderated by already
    // existing current debt level. Also - protection added in case of a negative result
    double issued_debt = percent_of(assets.get_equity(), m_debt_of_equity[m_profile]);
    issued_debt -= percent_of(assets.get_debt(), m_debt_of_curr_debt[m_profile]);
    assets.add_debt(std::max(0.0, issued_debt));
}
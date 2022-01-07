#include "DebtIssuance.h"  
	
DebtIssuance::DebtIssuance(PROFILE profile): AssetFlowAction{profile} {}

void DebtIssuance::update_assets(Assets& assets)
{
    assets.add_debt(percent_of(assets.get_equity(), m_debt_of_equity[m_profile]));
}
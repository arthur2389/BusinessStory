// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "DebtIssuance.h"  
	
DebtIssuance::DebtIssuance(PROFILE profile): AssetFlowAction{profile} {}

void DebtIssuance::update_assets(Assets& assets, year_10k& y10k)
{
    double debt_issuance = percent_of(assets.get_assests(), m_debt_of_equity[m_profile]);
    assets.add_debt(debt_issuance);
    y10k.debt_issuance = debt_issuance;
}
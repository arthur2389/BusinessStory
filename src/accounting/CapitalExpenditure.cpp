#include "CapitalExpenditure.h"  
	
CapitalExpenditure::CapitalExpenditure() {}
	
CapitalExpenditure::CapitalExpenditure(double capex): m_capex{capex} {}

void CapitalExpenditure::update_assets(Assets& assets)
{
    assets.add_equity(-m_capex);
}


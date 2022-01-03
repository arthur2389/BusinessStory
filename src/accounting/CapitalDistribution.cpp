#include "CapitalDistribution.h"  

void CapitalDistribution::update_assets(Assets& assets)
{
    assets.add_equity(-m_paid_of_equity[m_profile]);
}
#include "CapitalDistribution.h"  

CapitalDistribution::CapitalDistribution(PROFILE profile): AssetFlowAction{profile} {}

void CapitalDistribution::update_assets(Assets& assets)
{
    assets.add_equity(-m_paid_of_equity[m_profile]);
}
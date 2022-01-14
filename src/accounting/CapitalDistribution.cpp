// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "CapitalDistribution.h"  

CapitalDistribution::CapitalDistribution(PROFILE profile): AssetFlowAction{profile} {}

void CapitalDistribution::update_assets(Assets& assets, year_10k& y10k)
{
    double capital_distribution = percent_of(assets.get_equity(), m_paid_of_equity[m_profile]);
    assets.add_equity(-capital_distribution);
    y10k.capital_distribution = capital_distribution;
}
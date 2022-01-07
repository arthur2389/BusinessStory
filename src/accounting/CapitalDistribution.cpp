// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "CapitalDistribution.h"  

CapitalDistribution::CapitalDistribution(PROFILE profile): AssetFlowAction{profile} {}

void CapitalDistribution::update_assets(Assets& assets)
{
    assets.add_equity(-m_paid_of_equity[m_profile]);
}
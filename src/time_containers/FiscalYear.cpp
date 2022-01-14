// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "FiscalYear.h"  
	
FiscalYear::FiscalYear(double interest_rate, double tax_rate):
     m_interest_rate{interest_rate}, m_tax_rate{tax_rate} {}
	
void FiscalYear::set_return_on_capital(double return_on_capital)
{
    // Making sure earnings are at the beginning - mainly to reflect last years assets vs. current year 
    m_asset_flows.insert(m_asset_flows.begin(),
     std::make_unique<Earnings>(return_on_capital, m_interest_rate, m_tax_rate));
}

void FiscalYear::set_debt_issuance(PROFILE profile)
{
    if (profile == PROFILE::P_NONE)
        return;
    m_asset_flows.push_back(std::make_unique<DebtIssuance>(profile));
}

void FiscalYear::set_paid_in_capital(PROFILE profile)
{
    if (profile == PROFILE::P_NONE)
        return;
    m_asset_flows.push_back(std::make_unique<PaidInCapital>(profile));
}

void FiscalYear::set_debt_repayment(PROFILE profile)
{
    if (profile == PROFILE::P_NONE)
        return;
    m_asset_flows.push_back(std::make_unique<DebtRepayment>(profile));
}

void FiscalYear::set_capital_distribution(PROFILE profile)
{
    if (profile == PROFILE::P_NONE)
        return;
    m_asset_flows.push_back(std::make_unique<CapitalDistribution>(profile));
}

year_10k& FiscalYear::get_year_10k()
{
    return m_year_10k;
}

void FiscalYear::go_through(Assets& assets)
{
    for (auto& af: m_asset_flows)
    {
        af->update_assets(assets, m_year_10k);
        m_year_10k.end_of_year_equity = assets.get_equity();
        m_year_10k.end_of_year_debt = assets.get_debt();
    }
}

// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "FiscalYear.h"  
	
FiscalYear::FiscalYear(double interest_rate, double tax_rate):
     m_interest_rate{interest_rate}, m_tax_rate{tax_rate} {}
	
void FiscalYear::set_earnings(double return_on_capital)
{
    // Making sure earnings are at the beginning - mainly to reflect last years assets vs. current year 
    m_asset_flows.insert(m_asset_flows.begin(),
     std::make_unique<Earnings>(return_on_capital, m_interest_rate, m_tax_rate));
}

void FiscalYear::set_debt_issuance(std::string& profile)
{
    if (profile == "None")
        return;
    m_asset_flows.push_back(std::make_unique<DebtIssuance>(m_profile_conversion[profile]));
}

void FiscalYear::set_paid_in_capital(std::string& profile)
{
    if (profile == "None")    
        return;
    m_asset_flows.push_back(std::make_unique<PaidInCapital>(m_profile_conversion[profile]));
}

void FiscalYear::set_debt_repayment(std::string& profile)
{
    if (profile == "None")    
        return;
    m_asset_flows.push_back(std::make_unique<DebtRepayment>(m_profile_conversion[profile]));
}

void FiscalYear::set_capital_distribution(std::string& profile)
{
    if (profile == "None")    
        return;
    m_asset_flows.push_back(std::make_unique<CapitalDistribution>(m_profile_conversion[profile]));
}

void FiscalYear::go_through(Assets& assets)
{
    for (auto& af: m_asset_flows)
    {
        // ToDo push this for update as well
        af->update_assets(assets);
        m_year_10k.equity = assets.get_equity();
        m_year_10k.debt = assets.get_debt();
    }
}

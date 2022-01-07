#include "Earnings.h"  
	
Earnings::Earnings() {}

Earnings::Earnings(double return_on_capital,
                   double debt_interest, 
                   double tax_perc):
                   m_return_on_capital{return_on_capital},
                   m_debt_interest{debt_interest}, 
                   m_tax_perc{tax_perc} {}

void Earnings::update_assets(Assets& assests)
{
    // Calculating ebit from return on capital and reducing taxes and interest
    double ebit = percent_of(assests.total_assests(), m_return_on_capital);
    ebit -= percent_of(assests.get_debt(), m_debt_interest);
    double tax = m_return_on_capital > 0 ? percent_of(ebit, m_tax_perc) : 0;
    ebit -= tax;
    // Here - sticking with ebit term to avoid adding another varable        
    assests.add_equity(ebit);
}

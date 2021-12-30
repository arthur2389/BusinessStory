#include "Earnings.h"  
	
Earnings::Earnings() {}

Earnings::Earnings(double return_on_capital): m_return_on_capital{return_on_capital} {}

void Earnings::update_assets(Assets& assests)
{
    double earnings = percent_of(assests.total_assests(), m_return_on_capital);
    assests.add_equity(earnings);
}

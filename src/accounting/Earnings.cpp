#include "Earnings.h"  
	
Earnings::Earnings() {}

Earnings::Earnings(int return_on_capital): m_return_on_capital{return_on_capital} {}

void Earnings::update_assets(Assets& assests)
{
    int earnings = (m_return_on_capital / 100) * assests.total_assests();
    assests.add_equity(earnings);
}

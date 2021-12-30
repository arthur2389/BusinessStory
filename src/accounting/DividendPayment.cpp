#include "DividendPayment.h"  

DividendPayment::DividendPayment(double percent_of_equity) : m_percent_of_equity{percent_of_equity} {}
	
DividendPayment::DividendPayment() {}

void DividendPayment::update_assets(Assets& assets)
{
    double dividend_paid = - percent_of(assets.get_equity(), m_percent_of_equity);
    assets.add_equity(dividend_paid);
}

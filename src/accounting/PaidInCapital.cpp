#include "PaidInCapital.h"  

void PaidInCapital::update_assets(Assets& assets)
{
    // The paid in capital is corelated to the total assets of the company
    // e.g. large number of total assets in high profile will result in high 
    // paid in capital
    double paid_in_capital = percent_of(assets.total_assests(),
                                        m_paid_in_of_total_assets[m_profile]);
    assets.add_equity(paid_in_capital);
}

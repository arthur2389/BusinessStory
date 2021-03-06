// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "PaidInCapital.h"  

PaidInCapital::PaidInCapital(PROFILE profile): AssetFlowAction{profile} {}

void PaidInCapital::update_assets(Assets& assets, year_10k& y10k)
{
    // The paid in capital is corelated to the total assets of the company
    // e.g. large number of total assets in high profile will result in high 
    // paid in capital
    double paid_in_capital = percent_of(assets.get_assests(),
                                        m_paid_in_of_total_assets[m_profile]);
    assets.add_assets(paid_in_capital);
    y10k.paid_in_capital = paid_in_capital;
}

#include "DebtInterest.h"  

DebtInterest::DebtInterest() {};

DebtInterest::DebtInterest(double interest_rate): m_interest_rate{interest_rate} {}

void DebtInterest::update_assets(Assets& assests)
{
    double interest = - percent_of(assests.get_debt(), m_interest_rate);
    assests.add_equity(interest);
}

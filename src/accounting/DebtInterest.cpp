#include "DebtInterest.h"  

DebtInterest::DebtInterest() {};

DebtInterest::DebtInterest(double interest_rate): m_interest_rate{interest_rate} {}

void DebtInterest::update_assets(Assets& assests)
{
    double interest = - (m_interest_rate / 100) * assests.get_debt();
    assests.add_equity(interest);
}

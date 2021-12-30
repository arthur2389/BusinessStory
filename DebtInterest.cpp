#include "DebtInterest.hpp"

DebtInterest::DebtInterest(int interest_rate):  m_interest_rate{interest_rate} {}

DebtInterest::update_assets(Assets& assets)
{
    int interest_paid = - (m_ammount / 100) * assets.get_debt();
    assets.add_equity(interest_paid);
}
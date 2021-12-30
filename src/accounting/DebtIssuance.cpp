#include "DebtIssuance.hpp"

DebtIssuance::DebtIssuance() {}

DebtIssuance::DebtIssuance(int issued_debt): m_issued_debt{issued_debt} {}

void DebtIssuance::update_assets(Assets& assets)
{
    assets.add_debt(m_issued_debt);
}

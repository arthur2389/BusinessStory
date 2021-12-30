#ifndef DEBTISSUANCE_HPP
#define DEBTISSUANCE_HPP

#include "AssetFlowAction.hpp"

class DebtIssuance: public AssetFlowAction
{
public:
    DebtIssuance();
    DebtIssuance(int issued_debt);
    void update_assets(Assets& assets);
    
private:
    int m_issued_debt;
};

#endif // DEBTISSUANCE_HPP

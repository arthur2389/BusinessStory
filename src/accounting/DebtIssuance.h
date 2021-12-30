#ifndef DEBTISSUANCE_H
#define DEBTISSUANCE_H
#pragma once

#include "AssetFlowAction.h"

class DebtIssuance: public AssetFlowAction
{
public:
    DebtIssuance();
    DebtIssuance(int issued_debt);
    void update_assets(Assets& assets);
    
private:
    int m_issued_debt;
};

#endif // DEBTISSUANCE_H

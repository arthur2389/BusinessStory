#ifndef DEBTINTEREST_HPP
#define DEBTINTEREST_HPP

#include "AssetFlowAction.hpp"

class DebtInterest: public AssetFlowAction
{
public:
    DebtInterest(int interest_rate);
    void update_assets(Assets& assets);
    
private:
    int m_interest_rate;
    
};

#endif // DEBTINTEREST_HPP

#ifndef ASSETFLOWACTION_HPP
#define ASSETFLOWACTION_HPP

#include "Assets.hpp"

class AssetFlowAction
{
public:
    AssetFlowAction(int order)
        : m_order{order} {} 
    virtual void update_assets(Assets& assets);
    int get_order() {return m_order}

private:
    int m_order;
    
};

#endif // ASSETFLOWACTION_HPP

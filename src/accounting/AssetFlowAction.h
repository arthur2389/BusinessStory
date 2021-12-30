#ifndef ASSETFLOWACTION_H
#define ASSETFLOWACTION_H
#pragma once

#include "Assets.h"

class AssetFlowAction
{
public:
    AssetFlowAction() {};
    AssetFlowAction(int order)
        : m_order{order} {} 
    virtual void update_assets(Assets& assets)=0;
    int get_order() {return m_order;}

private:
    int m_order;
    
};

#endif // ASSETFLOWACTION_H

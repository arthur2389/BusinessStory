#ifndef ASSETFLOWACTION_H
#define ASSETFLOWACTION_H
#pragma once

#include "Assets.h"

class AssetFlowAction
{
public:
    AssetFlowAction() {};
    AssetFlowAction(int order);
    virtual void update_assets(Assets& assets)=0;
    int get_order() const; 

protected:
    double percent_of(double value, double percent) {}

private:
    int m_order{0};
    
};

#endif // ASSETFLOWACTION_H

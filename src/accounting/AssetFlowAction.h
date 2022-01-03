#ifndef ASSETFLOWACTION_H
#define ASSETFLOWACTION_H
#pragma once

#include "Assets.h"
#include <map>

class AssetFlowAction
{
public:

    typedef enum PROFILE{
        P_LOW = 0,
        P_MEDIUM = 1,
        P_HIGH = 2
    };

    AssetFlowAction(PROFILE profile);
    AssetFlowAction();
    virtual ~AssetFlowAction();
    virtual void update_assets(Assets& assets)=0;
    int get_order() const; 


protected:
    double percent_of(double value, double percent);
    PROFILE m_profile;

private:
    int m_order{0};
    
};

#endif // ASSETFLOWACTION_H

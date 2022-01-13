// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef ASSETFLOWACTION_H
#define ASSETFLOWACTION_H
#pragma once

#include "Assets.h"
#include "Types.h"
#include <map>

class AssetFlowAction
{
public:

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

#include "AssetFlowAction.h"

AssetFlowAction::AssetFlowAction() {}

AssetFlowAction::AssetFlowAction(AssetFlowAction::PROFILE profile): m_profile{profile} {}

int AssetFlowAction::get_order() const
{
    return m_order;
}

double AssetFlowAction::percent_of(double value, double percent)
{
    return (percent / 100.0) * value;
}

AssetFlowAction::~AssetFlowAction() {}

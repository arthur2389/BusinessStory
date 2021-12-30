#include "AssetFlowAction.h"

AssetFlowAction::AssetFlowAction(int order): m_order{order} {} 

int AssetFlowAction::get_order() const
{
    return m_order;
}

double AssetFlowAction::percent_of(double value, double percent)
{
    return (percent / 100) * value;
}

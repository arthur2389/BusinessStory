// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "Assets.h"

Assets::Assets(double equity, double debt)
    : m_equity{equity}, m_debt{debt}, m_total_assets{equity + debt} {}

Assets::Assets(Assets& source) : Assets{source.get_equity(), source.get_debt()} {}

double Assets::get_equity() const
{
    return m_equity;
}

double Assets::get_debt() const
{
    return m_debt;
}

double Assets::total_assests() const 
{
    return m_total_assets;
}

double Assets::equity_to_debt_ratio() const 
{
    return m_equity / m_debt;
}

double Assets::add_equity(double add_to_equity)
{
    m_equity += add_to_equity;
    m_total_assets += add_to_equity;
    return m_equity;
}

double Assets::add_debt(double add_to_debt)
{
    m_debt += add_to_debt;
    m_total_assets += add_to_debt;
    return m_debt;
}

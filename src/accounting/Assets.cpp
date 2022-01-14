// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "Assets.h"

Assets::Assets(double assets, double debt)
    : m_assets{assets}, m_debt{debt} {}

Assets::Assets(Assets& source) : Assets{source.get_assests(), source.get_debt()} {}

double Assets::get_debt() const
{
    return m_debt;
}

double Assets::get_assests() const 
{
    return m_assets;
}

double Assets::get_equity() const
{
    return m_assets - m_debt;
}

double Assets::add_assets(double add_to_assets)
{
    m_assets += add_to_assets;
    return m_assets;
}

double Assets::add_debt(double add_to_debt)
{
    m_debt += add_to_debt;
    add_assets(add_to_debt);
    return m_debt;
}

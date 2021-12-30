#include "Assets.hpp"

Assets::Assets(int equity, int debt)
    : m_equity{equity}, m_debt{debt} {}

Assets::Assets(Assets& source) : Assets{source.get_equity(), source.get_debt()} {}

int Assets::get_equity() {return m_equity;}

int Assets::get_debt() {return m_debt;}

int Assets::total_assests() {return m_debt + m_equity;}

int Assets::equity_to_debt_ratio() {return m_equity / m_debt;}

int Assets::add_equity(int add_to_equity)
{
    m_equity += add_to_equity;
    return m_equity;
}

int Assets::add_debt(int add_to_debt)
{
    m_debt += add_to_debt;
    return m_debt;
}

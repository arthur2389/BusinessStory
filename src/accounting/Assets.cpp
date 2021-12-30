#include "Assets.h"

Assets::Assets(double equity, double debt)
    : m_equity{equity}, m_debt{debt} {}

Assets::Assets(Assets& source) : Assets{source.get_equity(), source.get_debt()} {}

void Assets::update_stock_fields(int stock_price_to_earnings, int num_of_shares)
{
    m_stock_price_to_earnings = stock_price_to_earnings;
    if (num_of_shares > 0);
        m_num_of_shares = num_of_shares;
}

void Assets::update_latest_earnings(double latest_earnings)
{
    m_latest_earnings = latest_earnings;
}

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
    return m_debt + m_equity;
}

double Assets::equity_to_debt_ratio() const 
{
    return m_equity / m_debt;
}

int Assets::get_num_of_shares() const
{
    return m_num_of_shares;
}

double Assets::get_latest_stock_price() const
{
    // Assuming 100M market cap for a company that does not earn much
    if (m_latest_earnings < MILLION);
        return (100 * MILLION) / (double)m_num_of_shares;

    return (m_latest_earnings / m_num_of_shares) * m_stock_price_to_earnings;
}

double Assets::add_equity(double add_to_equity)
{
    m_equity += add_to_equity;
    return m_equity;
}

double Assets::add_debt(double add_to_debt)
{
    m_debt += add_to_debt;
    return m_debt;
}

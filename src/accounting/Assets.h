// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef ASSESTS_H
#define ASSESTS_H
#pragma once

static const double MILLION{1000000};

class Assets
{
public:
    Assets(double equity, double debt); 
    Assets(Assets& source);

    double get_equity() const;
    double get_debt() const;
    double total_assests() const;
    double equity_to_debt_ratio() const;

    double add_equity(double add_to_equity);
    double add_debt(double add_to_debt);
    void update_latest_earnings(double latest_earnings);

private:

    double m_equity;
    double m_debt;
    double m_total_assets;
    int m_num_of_shares{0};
    int m_stock_price_to_earnings{10}; 
};

#endif // ASSESTS_H

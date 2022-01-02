#ifndef ASSESTS_H
#define ASSESTS_H
#pragma once

static const double MILLION{1000000};

class Assets
{
public:
    Assets(double equity, double debt); 
    Assets(Assets& source);

    void update_stock_fields(int stock_price_to_earnings, int num_of_shares=-1);
    void update_latest_earnings(double latest_earnings);

    double get_equity() const;
    double get_debt() const;
    int get_num_of_shares() const;
    double total_assests() const;
    double equity_to_debt_ratio() const;
    double get_latest_stock_price() const;
    double get_latest_earnings() const;

    double add_equity(double add_to_equity);
    double add_debt(double add_to_debt);
    int add_num_of_shares(int num_of_shares);

private:

    double m_equity;
    double m_debt;
    double m_total_assets;
    int m_num_of_shares{0};
    int m_stock_price_to_earnings{10}; 
    double m_latest_earnings{0.0};
};

#endif // ASSESTS_H

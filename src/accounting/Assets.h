#ifndef ASSESTS_H
#define ASSESTS_H
#pragma once

class Assets
{
public:
    Assets(double equity, double debt=0); 
    Assets(Assets& source);

    double get_equity() const;
    double get_debt() const;
    double total_assests() const;
    double equity_to_debt_ratio() const;

    double add_equity(double add_to_equity);
    double add_debt(double add_to_debt);
    
private:
    double m_equity;
    double m_debt;
};

#endif // ASSESTS_H

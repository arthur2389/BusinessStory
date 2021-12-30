#ifndef ASSESTS_H
#define ASSESTS_H
#pragma once

class Assets
{
public:
    Assets(int equity, int debt=0); 
    Assets(Assets& source);

    int get_equity() const;
    int get_debt() const;
    int total_assests() const;
    int equity_to_debt_ratio() const;

    int add_equity(int add_to_equity);
    int add_debt(int add_to_debt);
    
private:
    int m_equity;
    int m_debt;
};

#endif // ASSESTS_H

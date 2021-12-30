#ifndef ASSESTS_HPP
#define ASSESTS_HPP

class Assets
{
public:
    Assets(int equity, int debt=0); 
    Assets(Assets& source);

    # Getters
    int get_equity();
    int get_debt();
    int total_assests();
    int equity_to_debt_ratio();

    # Setters
    int add_equity(int add_to_equity);
    int add_debt(int add_to_debt);
    
private:
    int m_equity;
    int m_debt;
};

#endif // ASSESTS_HPP

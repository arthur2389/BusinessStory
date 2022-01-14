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

    double get_assests() const;
    double get_equity() const;
    double get_debt() const;

    double add_assets(double add_to_assets);
    double add_debt(double add_to_debt);
    void update_latest_earnings(double latest_earnings);

private:

    double m_assets;
    double m_debt;
};

#endif // ASSESTS_H

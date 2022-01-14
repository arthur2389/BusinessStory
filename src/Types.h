// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#ifndef TYPES_H
#define TYPES_H
#pragma once

enum class PROFILE {
    P_NONE, 
    P_LOW,
    P_MEDIUM,
    P_HIGH
};

struct year_10k
{
    double end_of_year_equity;
    double end_of_year_debt;
    double ebit;
    double earnings;
    double paid_in_capital;
    double debt_issuance;
    double debt_repayment;
    double capital_distribution;
};

#endif
#ifndef DEBTREPAYMENT_H
#define DEBTREPAYMENT_H
#pragma once

#include "AssetFlowAction.h"

class DebtRepayment : public AssetFlowAction 
{

	public:

		DebtRepayment();
		DebtRepayment(double repayment_ammount);
		virtual void update_assets(Assets& assets) override;

	private:
		double m_repayment_ammount;
};
#endif
#ifndef SHAREBUYBACK_H
#define SHAREBUYBACK_H
#pragma once

#include "AssetFlowAction.h"

class ShareBuyBack : public AssetFlowAction 
{
	public:

		ShareBuyBack();
		ShareBuyBack(int numer_of_shares);
		virtual void update_assets(Assets& assets) override;

	private:
		int m_number_of_shares;
};
#endif
#pragma once
#include "UpdateStrategy.h"

class WinLoseUpdateStrategy : public UpdateStrategy {

public:

	Screen* update(Screen &screen) override;

};
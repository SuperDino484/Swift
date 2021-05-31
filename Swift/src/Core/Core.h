#pragma once
#include <memory>

#define BIT(amount) (1 << amount)

#define SF_BIND_FN(function) std::bind(&function, this, std::placeholders::_1)
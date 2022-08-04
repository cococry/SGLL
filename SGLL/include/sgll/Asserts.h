#pragma once

#include "Logging.h"

#define SGLL_ASSERT_NO_MSG(cond) {if(cond) {} else {SGLL_INTERNAL_CRITICAL("Assertion Failed '{0}' in file {1} on line {1}", #cond, __FILE__, __LINE__);}}

#define SGLL_ASSERT_MSG(cond, msg) {if(cond) {} else {SGLL_INTERNAL_CRITICAL("Assertion Failed '{0}' in file {1} on line {1} : '{2}'", #cond, __FILE__, __LINE__, msg);}}
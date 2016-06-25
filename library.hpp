#pragma once

#include <map>
#include <string>
#include <vector>

/**
 * @defgroup sample_library
 * @brief A set of incoherent functions that waste CPU with no real goal other than just showing how we can use OProfile
 * in Linux.
 *
 * You can also use this code to check a few features of C++11, but nothing else.
 *
 * @{
 */

float process(std::vector<float> &data, const std::string &name);
const std::map<float, std::string> get_results();
void clear_results();

/**
 * @}
 */

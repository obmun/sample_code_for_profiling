#include <algorithm>
#include <cassert>
#include "library.hpp"

constexpr unsigned int N_ITERS = 24;

std::map<float, std::string> results;

static void scale(std::vector<float> &d, float s)
{
     std::transform(d.begin(), d.end(), d.begin(), [=](float c) { return s*c; });
}

static float scalar_prod(const std::vector<float> &a, const std::vector<float> &b)
{
    assert(a.size() == b.size());
    float res = 0;
    for (unsigned int j = 0; j < a.size(); ++j)
    {
        res += a[j]*b[j];
    }
    return res;
}

/**
 * Yes, this is not a real self-correlation.
 */
static std::vector<float> self_correlation(const std::vector<float> &v)
{
     auto v_dupl{v};
     auto res = std::vector<float>(v.size());
     for (unsigned int i = 0; i < v.size(); ++i)
     {
         if (i != 0)
             std::rotate(std::begin(v_dupl), std::next(std::begin(v_dupl)), std::end(v_dupl));
         scale(v_dupl, -1.0f);
         res[i] = scalar_prod(v_dupl, v);
     }
    return res;
}

float process(std::vector<float> &data, const std::string &name)
{
    auto tmp{data};
    scale(data, 2.0);
    auto corr = self_correlation(data);
    results[*std::max_element(std::begin(corr), std::end(corr))] = name;
    return *std::min_element(std::begin(corr), std::end(corr));
}

const std::map<float, std::string> get_results()
{
    return results;
}

void clear_results()
{
    results.clear();
}
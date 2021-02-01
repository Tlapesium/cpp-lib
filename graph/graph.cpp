#pragma once
#include <vector>
#include <utility>

/**
 * @title グラフ用テンプレート
 */

using UnWeightedGraph = std::vector<std::vector<int>>;
using WeightedGraph = std::vector<std::vector<std::pair<int, long long>>>;
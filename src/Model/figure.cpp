#include "figure.h"

namespace awfl {

void Figure::SetParameters(Params& param) { param_ = param; }

Params& Figure::GetParameters() { return param_; }

std::size_t Figure::GetVerticesNumbers() const noexcept {
  return vertices_.size();
}

std::size_t Figure::GetEdgesNumbers() const noexcept { return edges_.size(); }

std::vector<double>& Figure::GetVertices() { return vertices_; }

std::vector<int>& Figure::GetEdges() { return edges_; }

void Figure::ClearData() {
  initial_.clear();
  vertices_.clear();
  edges_.clear();
}

void Figure::ToInitial() { vertices_ = initial_; }

double Figure::Normalization() const noexcept {
  auto maxSize = std::minmax_element(initial_.begin(), initial_.end());
  return std::max(std::abs(*maxSize.first), *maxSize.second);
}

}  // namespace awfl
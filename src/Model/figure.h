#ifndef VIEWER_SRC_MODEL_FIGURE_H_
#define VIEWER_SRC_MODEL_FIGURE_H_

#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace awfl {
struct Params {
  double angleX = 0.0, angleY = 0.0, angleZ = 0.0;
  double offsetX = 0.0, offsetY = 0.0, offsetZ = 0.0;
  double scale = 1.0;
};

class Figure {
  friend class FileReader;

 public:
  Figure() = default;
  ~Figure() = default;

  void SetParameters(Params& param) { param_ = param; }

  Params& GetParameters() { return param_; }

  std::size_t GetVerticesNumbers() const noexcept { return vertices_.size(); }

  std::size_t GetEdgesNumbers() const noexcept { return edges_.size(); }

  std::vector<double>& GetVertices() { return vertices_; }

  std::vector<int>& GetEdges() { return edges_; }

  void ClearData() {
    initial_.clear();
    vertices_.clear();
    edges_.clear();
  }

  void ToInitial() { vertices_ = initial_; }

  double Normalization() {
    auto maxSize = std::minmax_element(initial_.begin(), initial_.end());
    return std::max(std::abs(*maxSize.first), *maxSize.second);
  }

 private:
  Params param_;
  std::vector<double> initial_;
  std::vector<double> vertices_;
  std::vector<int> edges_;
};
}  // namespace awfl

#endif  // VIEWER_SRC_MODEL_FIGURE_H_

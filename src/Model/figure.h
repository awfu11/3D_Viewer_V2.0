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

  void SetParameters(Params& param);
  Params& GetParameters();

  std::size_t GetVerticesNumbers() const noexcept;
  std::size_t GetEdgesNumbers() const noexcept;

  std::vector<double>& GetVertices();
  std::vector<int>& GetEdges();

  void ClearData();

  void ToInitial();

  double Normalization() const noexcept;

 private:
  Params param_;
  std::vector<double> initial_;
  std::vector<double> vertices_;
  std::vector<int> edges_;
};
}  // namespace awfl

#endif  // VIEWER_SRC_MODEL_FIGURE_H_

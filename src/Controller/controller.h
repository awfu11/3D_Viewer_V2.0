#ifndef VIEWER_SRC_CONTROLLER_CONTROLLER_H_
#define VIEWER_SRC_CONTROLLER_CONTROLLER_H_

#include "../Model/model.h"

namespace awfl {
class Controller {
 public:
  Controller() = default;
  Controller(Model* m) : model_(m) {}
  ~Controller() = default;

  std::size_t GetVerticesNumbers() const noexcept;

  double* GetVertices() const noexcept;

  std::size_t GetEdgesNumbers() const noexcept;

  int* GetEdges() const noexcept;

  double Normalization();

  void Transform(Params& param);

  void ReadData(const std::string& path);

  void ClearData();

 private:
  Model* model_;
};
}  // namespace awfl

#endif  // VIEWER_SRC_CONTROLLER_CONTROLLER_H_

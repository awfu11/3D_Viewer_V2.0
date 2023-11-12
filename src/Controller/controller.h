#ifndef VIEWER_SRC_CONTROLLER_CONTROLLER_H_
#define VIEWER_SRC_CONTROLLER_CONTROLLER_H_

#include "../Model/model.h"

namespace awfl {
class Controller {
 public:
  Controller() = default;
  Controller(Model* m) : model_(m) {}
  ~Controller() = default;

  std::size_t GetVerticesNumbers() const {
    return model_->GetVerticesNumbers();
  }

  double* GetVertices() { return model_->GetVertices().data(); }

  std::size_t GetEdgesNumbers() const { return model_->GetEdgesNumbers(); }

  int* GetEdges() { return model_->GetEdges().data(); }

  double Normalization() { return model_->Normalization(); }

  void Transform(Params& param) { model_->Transform(param); }

  void ReadData(const std::string& path) { model_->ReadFile(path); }

  void ClearData() { model_->ClearData(); }

 private:
  Model* model_;
};
}  // namespace awfl

#endif  // VIEWER_SRC_CONTROLLER_CONTROLLER_H_

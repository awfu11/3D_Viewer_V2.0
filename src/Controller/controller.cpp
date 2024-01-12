#include "controller.h"

namespace awfl {
  std::size_t Controller::GetVerticesNumbers() const noexcept {
    return model_->GetVerticesNumbers();
  }

  double* Controller::GetVertices() const noexcept { return model_->GetVertices().data(); }

  std::size_t Controller::GetEdgesNumbers() const noexcept { return model_->GetEdgesNumbers(); }

  int* Controller::GetEdges() const noexcept { return model_->GetEdges().data(); }

  double Controller::Normalization() { return model_->Normalization(); }

  void Controller::Transform(Params& param) { model_->Transform(param); }

  void Controller::ReadData(const std::string& path) { model_->ReadFile(path); }

  void Controller::ClearData() { model_->ClearData(); }
}  // namesapce awfl

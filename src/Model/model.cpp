#include "model.h"

namespace awfl {
Model::Model() {
  exec_.push_back(new RotateCommand(&figure_, new RotateStrategy()));
  exec_.push_back(new MoveCommand(&figure_, new MoveStrategy()));
  exec_.push_back(new ScaleCommand(&figure_, new ScaleStrategy()));
}

Model::~Model() {
  for (std::size_t i = 0; i < exec_.size(); ++i) {
    delete exec_[i];
  }
}

std::size_t Model::GetVerticesNumbers() const noexcept {
  return figure_.GetVerticesNumbers();
}

std::size_t Model::GetEdgesNumbers() const noexcept {
  return figure_.GetEdgesNumbers();
}

std::vector<double>& Model::GetVertices() { return figure_.GetVertices(); }

std::vector<int>& Model::GetEdges() { return figure_.GetEdges(); }

double Model::Normalization() const noexcept { return figure_.Normalization(); }

void Model::ClearData() { figure_.ClearData(); }

void Model::ReadFile(const std::string& path) {
  ClearData();
  reader_.GetDataFromFile(figure_, path);
  figure_.ToInitial();
}

void Model::Transform(Params& param) {
  figure_.SetParameters(param);
  figure_.ToInitial();
  for (std::size_t i = 0; i < exec_.size(); ++i) {
    exec_[i]->Execute();
  }
}
}  // namespace awfl
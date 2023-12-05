#ifndef VIEWER_SRC_MODEL_MODEL_H_
#define VIEWER_SRC_MODEL_MODEL_H_

#include "command.h"
#include "figure.h"
#include "filereader.h"
#include "strategy.h"

namespace awfl {
class Model {
 public:
  Model() {
    exec_.push_back(new RotateCommand(&figure_, new RotateStrategy()));
    exec_.push_back(new MoveCommand(&figure_, new MoveStrategy()));
    exec_.push_back(new ScaleCommand(&figure_, new ScaleStrategy()));
  }

  ~Model() {
    for (std::size_t i = 0; i < exec_.size(); ++i) {
      delete exec_[i];
    }
  }

  std::size_t GetVerticesNumbers() const {
    return figure_.GetVerticesNumbers();
  }

  std::size_t GetEdgesNumbers() const noexcept { return figure_.GetEdgesNumbers(); }

  std::vector<double>& GetVertices() { return figure_.GetVertices(); }

  std::vector<int>& GetEdges() { return figure_.GetEdges(); }

  double Normalization() { return figure_.Normalization(); }

  void ClearData() { figure_.ClearData(); }

  void ReadFile(const std::string& path) {
    ClearData();
    reader_.GetDataFromFile(figure_, path);
    figure_.ToInitial();
  }

  void Transform(Params& param) {
    figure_.SetParameters(param);
    figure_.ToInitial();
    for (std::size_t i = 0; i < exec_.size(); ++i) {
      exec_[i]->Execute();
    }
  }

 private:
  Figure figure_;
  FileReader reader_;
  std::vector<Command*> exec_;
};

}  // namespace awfl

#endif  // VIEWER_SRC_MODEL_MODEL_H_

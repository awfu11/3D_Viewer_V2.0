#ifndef VIEWER_SRC_MODEL_MODEL_H_
#define VIEWER_SRC_MODEL_MODEL_H_

#include "command.h"
#include "figure.h"
#include "filereader.h"
#include "strategy.h"

namespace awfl {
class Model {
 public:
  Model();
  ~Model();

  std::size_t GetVerticesNumbers() const noexcept;
  std::size_t GetEdgesNumbers() const noexcept;

  std::vector<double>& GetVertices();
  std::vector<int>& GetEdges();

  void ReadFile(const std::string& path);

  void ClearData();

  double Normalization() const noexcept;

  void Transform(Params& param);

 private:
  Figure figure_;
  FileReader reader_;
  std::vector<Command*> exec_;
};

}  // namespace awfl

#endif  // VIEWER_SRC_MODEL_MODEL_H_

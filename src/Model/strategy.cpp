#include "strategy.h"

namespace awfl {
void RotateStrategy::Modify(std::vector<double>& vertices, Params& param) {
  // rotation X
  for (std::size_t i = 0; i < vertices.size(); i += 3) {
    double y = vertices[i + 1], z = vertices[i + 2];
    vertices[i + 1] = cos(param.angleX) * y + sin(param.angleX) * z;
    vertices[i + 2] = -sin(param.angleX) * y + cos(param.angleX) * z;
  }
  // rotation Y
  for (std::size_t i = 0; i < vertices.size(); i += 3) {
    double x = vertices[i], z = vertices[i + 2];
    vertices[i] = cos(param.angleY) * x + sin(param.angleY) * z;
    vertices[i + 2] = -sin(param.angleY) * x + cos(param.angleY) * z;
  }
  // rotation Z
  for (std::size_t i = 0; i < vertices.size(); i += 3) {
    double x = vertices[i], y = vertices[i + 1];
    vertices[i] = cos(param.angleZ) * x + sin(param.angleZ) * y;
    vertices[i + 1] = -sin(param.angleZ) * x + cos(param.angleZ) * y;
  }
}

void MoveStrategy::Modify(std::vector<double>& vertices, Params& param) {
  // translation
  for (std::size_t i = 0; i < vertices.size(); i += 3) {
    vertices[i] += param.offsetX;
    vertices[i + 1] += param.offsetY;
    vertices[i + 2] += param.offsetZ;
  }
}

void ScaleStrategy::Modify(std::vector<double>& vertices, Params& param) {
  // scaling
  for (std::size_t i = 0; i < vertices.size(); ++i) {
    vertices[i] *= param.scale;
  }
}
}  // namespace awfl

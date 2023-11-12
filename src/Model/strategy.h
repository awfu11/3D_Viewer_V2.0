#ifndef VIEWER_SRC_MODEL_STRATEGY_H_
#define VIEWER_SRC_MODEL_STRATEGY_H_

#include "figure.h"

namespace awfl {
class Strategy {
 public:
  virtual ~Strategy() = default;
  virtual void Modify(std::vector<double>& vertices, Params& param) = 0;
};

class RotateStrategy : public Strategy {
 public:
  void Modify(std::vector<double>& vertices, Params& param) override;
};

class MoveStrategy : public Strategy {
 public:
  void Modify(std::vector<double>& vertices, Params& param) override;
};

class ScaleStrategy : public Strategy {
 public:
  void Modify(std::vector<double>& vertices, Params& param) override;
};
}  // namespace awfl

#endif  // VIEWER_SRC_MODEL_STRATEGY_H_
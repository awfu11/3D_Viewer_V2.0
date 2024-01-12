#ifndef VIEWER_SRC_MODEL_COMMAND_H_
#define VIEWER_SRC_MODEL_COMMAND_H_

#include "figure.h"
#include "strategy.h"

namespace awfl {
class Command {
 public:
  virtual ~Command() = default;
  virtual void Execute() = 0;
};

class RotateCommand : public Command {
 public:
  RotateCommand(Figure* figure, Strategy* strategy);
  ~RotateCommand();

  void Execute() override;

 private:
  Figure* figure_;
  Strategy* strategy_;
};

class MoveCommand : public Command {
 public:
  MoveCommand(Figure* figure, Strategy* strategy);
  ~MoveCommand();

  void Execute() override;

 private:
  Figure* figure_;
  Strategy* strategy_;
};

class ScaleCommand : public Command {
 public:
  ScaleCommand(Figure* figure, Strategy* strategy);
  ~ScaleCommand();

  void Execute() override;

 private:
  Figure* figure_;
  Strategy* strategy_;
};
}  // namespace awfl

#endif  // VIEWER_SRC_MODEL_COMMAND_H_
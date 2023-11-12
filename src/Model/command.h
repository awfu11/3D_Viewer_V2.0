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
  RotateCommand(Figure* figure, Strategy* strategy) {
    figure_ = figure;
    strategy_ = strategy;
  }

  ~RotateCommand() { delete strategy_; }

  void Execute() override {
    strategy_->Modify(figure_->GetVertices(), figure_->GetParameters());
  }

 private:
  Figure* figure_;
  Strategy* strategy_;
};

class MoveCommand : public Command {
 public:
  MoveCommand(Figure* figure, Strategy* strategy) {
    figure_ = figure;
    strategy_ = strategy;
  }

  ~MoveCommand() { delete strategy_; }

  void Execute() override {
    strategy_->Modify(figure_->GetVertices(), figure_->GetParameters());
  }

 private:
  Figure* figure_;
  Strategy* strategy_;
};

class ScaleCommand : public Command {
 public:
  ScaleCommand(Figure* figure, Strategy* strategy) {
    figure_ = figure;
    strategy_ = strategy;
  }

  ~ScaleCommand() { delete strategy_; }

  void Execute() override {
    strategy_->Modify(figure_->GetVertices(), figure_->GetParameters());
  }

 private:
  Figure* figure_;
  Strategy* strategy_;
};
}  // namespace awfl

#endif  // VIEWER_SRC_MODEL_COMMAND_H_
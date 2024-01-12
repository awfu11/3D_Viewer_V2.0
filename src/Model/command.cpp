#include "command.h"

namespace awfl {
RotateCommand::RotateCommand(Figure* figure, Strategy* strategy) {
  figure_ = figure;
  strategy_ = strategy;
}

RotateCommand::~RotateCommand() { delete strategy_; }

void RotateCommand::Execute() {
  strategy_->Modify(figure_->GetVertices(), figure_->GetParameters());
}

MoveCommand::MoveCommand(Figure* figure, Strategy* strategy) {
  figure_ = figure;
  strategy_ = strategy;
}

MoveCommand::~MoveCommand() { delete strategy_; }

void MoveCommand::Execute() {
  strategy_->Modify(figure_->GetVertices(), figure_->GetParameters());
}

ScaleCommand::ScaleCommand(Figure* figure, Strategy* strategy) {
  figure_ = figure;
  strategy_ = strategy;
}

ScaleCommand::~ScaleCommand() { delete strategy_; }

void ScaleCommand::Execute() {
  strategy_->Modify(figure_->GetVertices(), figure_->GetParameters());
}

}  // namespace awfl

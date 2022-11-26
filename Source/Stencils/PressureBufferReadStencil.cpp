#include "StdAfx.hpp"

#include "PressureBufferReadStencil.hpp"

#include "Definitions.hpp"
#include "StencilFunctions.hpp"

Stencils::PressureBufferReadStencil::PressureBufferReadStencil(
  const Parameters&     parameters,
  std::vector<RealType> Left,
  std::vector<RealType> Right,
  std::vector<RealType> Top,
  std::vector<RealType> Bottom,
  std::vector<RealType> Front,
  std::vector<RealType> Back
):
  BoundaryStencil<FlowField>(parameters),
  Left_(Left),
  Right_(Right),
  Top_(Top),
  Bottom_(Bottom),
  Front_(Front),
  Back_(Back) {}

void Stencils::PressureBufferReadStencil::applyLeftWall(FlowField& flowField, int i, int j) {
  flowField.getPressure().getScalar(i + 1, j) = Left_[j];
}
void Stencils::PressureBufferReadStencil::applyRightWall(FlowField& flowField, int i, int j) {
  flowField.getPressure().getScalar(i, j) = Right_[j];
}
void Stencils::PressureBufferReadStencil::applyBottomWall(FlowField& flowField, int i, int j) {
  flowField.getPressure().getScalar(i, j + 1) = Bottom_[i];
}
void Stencils::PressureBufferReadStencil::applyTopWall(FlowField& flowField, int i, int j) {
  flowField.getPressure().getScalar(i, j) = Top_[i];
}

void Stencils::PressureBufferReadStencil::applyLeftWall(FlowField& flowField, int i, int j, int k) {
  flowField.getPressure().getScalar(i + 1, j, k) = Left_[j * (parameters_.geometry.sizeZ + 3) + k];
}
void Stencils::PressureBufferReadStencil::applyRightWall(FlowField& flowField, int i, int j, int k) {
  flowField.getPressure().getScalar(i, j, k) = Right_[j * (parameters_.geometry.sizeZ + 3) + k];
}
void Stencils::PressureBufferReadStencil::applyBottomWall(FlowField& flowField, int i, int j, int k) {
  (flowField.getPressure().getScalar(i, j + 1, k)) = Bottom_[i * (parameters_.geometry.sizeZ + 3) + k];
}
void Stencils::PressureBufferReadStencil::applyTopWall(FlowField& flowField, int i, int j, int k) {
  flowField.getPressure().getScalar(i, j, k) = Top_[i * (parameters_.geometry.sizeZ + 3) + k];
}
void Stencils::PressureBufferReadStencil::applyFrontWall(FlowField& flowField, int i, int j, int k) {
  flowField.getPressure().getScalar(i, j, k + 1) = Front_[i * (parameters_.geometry.sizeY + 3) + j];
}
void Stencils::PressureBufferReadStencil::applyBackWall(FlowField& flowField, int i, int j, int k) {
  flowField.getPressure().getScalar(i, j, k) = Back_[i * (parameters_.geometry.sizeY + 3) + j];
}
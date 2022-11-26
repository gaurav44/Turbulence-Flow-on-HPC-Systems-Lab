#pragma once

#include <vector>

#include "BoundaryStencil.hpp"
#include "FieldStencil.hpp"
#include "FlowField.hpp"
#include "Iterators.hpp"
#include "Parameters.hpp"

namespace Stencils {

  class VelocityBufferReadStencil: public BoundaryStencil<FlowField> {
  private:
    std::vector<std::vector<RealType>> Left_;
    std::vector<std::vector<RealType>> Right_;
    std::vector<std::vector<RealType>> Top_;
    std::vector<std::vector<RealType>> Bottom_;
    std::vector<std::vector<RealType>> Front_;
    std::vector<std::vector<RealType>> Back_;

  public:
    VelocityBufferReadStencil(const Parameters&, std::vector<std::vector<RealType>>, std::vector<std::vector<RealType>>, std::vector<std::vector<RealType>>, std::vector<std::vector<RealType>>);
    VelocityBufferReadStencil(const Parameters&, std::vector<std::vector<RealType>>, std::vector<std::vector<RealType>>, std::vector<std::vector<RealType>>, std::vector<std::vector<RealType>>, std::vector<std::vector<RealType>>, std::vector<std::vector<RealType>>);

    ~VelocityBufferReadStencil() override = default;

    void applyLeftWall(FlowField& flowField, int i, int j) override;
    void applyRightWall(FlowField& flowField, int i, int j) override;
    void applyBottomWall(FlowField& flowField, int i, int j) override;
    void applyTopWall(FlowField& flowField, int i, int j) override;

    void applyLeftWall(FlowField& flowField, int i, int j, int k) override;
    void applyRightWall(FlowField& flowField, int i, int j, int k) override;
    void applyBottomWall(FlowField& flowField, int i, int j, int k) override;
    void applyTopWall(FlowField& flowField, int i, int j, int k) override;
    void applyFrontWall(FlowField& flowField, int i, int j, int k) override;
    void applyBackWall(FlowField& flowField, int i, int j, int k) override;
  };
} // namespace Stencils
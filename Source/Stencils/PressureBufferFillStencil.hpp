#pragma once

#include <vector>

#include "BoundaryStencil.hpp"
#include "FlowField.hpp"
#include "Parameters.hpp"

namespace Stencils {

  class PressureBufferFillStencil: public BoundaryStencil<FlowField> {
  private:
    std::vector<RealType>& Left_;
    std::vector<RealType>& Right_;
    std::vector<RealType>& Top_;
    std::vector<RealType>& Bottom_;
    std::vector<RealType>& Front_;
    std::vector<RealType>& Back_;

  public:
    PressureBufferFillStencil(const Parameters&, std::vector<RealType>&, std::vector<RealType>&, std::vector<RealType>&, std::vector<RealType>&, std::vector<RealType>&, std::vector<RealType>&);
    ~PressureBufferFillStencil() override = default;

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
#include "nuTStencil.hpp"

Stencils::nuTStencil::nuTStencil(const Parameters& parameters):
  FieldStencil<FlowField>(parameters) {}

void Stencils::nuTStencil::apply(FlowField& flowField, int i, int j) {}

void Stencils::nuTStencil::apply(FlowField& flowField, int i, int j, int k) {}
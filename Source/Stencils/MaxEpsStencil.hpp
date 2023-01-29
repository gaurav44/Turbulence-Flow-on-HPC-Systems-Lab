#pragma once

#include "FieldStencil.hpp"
#include "Parameters.hpp"
#include "TurbulentFlowFieldKE.hpp"

namespace Stencils {

  /** Computes the maximum value of max(velocity)/meshsize for all grid cells.
   *
   * Originally, one would compute the max. velocity only and adapt it with the meshsize afterwards.
   * This, however, becomes inconsistent when dealing with non-uniform, e.g. stretched, meshes, since
   * the meshsize may be different for every grid cell. We therefore determine the max(velocity)/meshsize
   * and synchronise this value over whole computational domain.
   */
  class MaxEpsStencil: public FieldStencil<TurbulentFlowFieldKE> {
  private:
    RealType maxValues_; //! Stores the maximum module of every component

    /** Sets the maximum value arrays to the value of the cell if it surpasses the current one.
     *
     * 2D version of the function
     * @param flowField Flow field
     * @param i Position in the X direction.
     * @param j Position in the Y direction.
     */
    void cellMaxValue(TurbulentFlowFieldKE& flowField, int i, int j);

    /** Sets the maximum value arrays to the value of the cell if it surpasses the current one.
     *
     * 3D version of the function
     * @param flowField Flow field
     * @param i Position in the X direction.
     * @param j Position in the Y direction.
     * @param k Position in the Z direction.
     */
    void cellMaxValue(TurbulentFlowFieldKE& flowField, int i, int j, int k);

  public:
    MaxEpsStencil(const Parameters& parameters);
    ~MaxEpsStencil() override = default;

    void apply(TurbulentFlowFieldKE& flowField, int i, int j) override;
    void apply(TurbulentFlowFieldKE& flowField, int i, int j, int k) override;

    /** Resets the maximum values to zero before computing the timestep.
     */
    void reset();

    /** Returns the array with the maximum modules of the components of the velocity,
     *  divided by the respective local meshsize.
     */
    const RealType getMaxValues() const;
  };

} // namespace Stencils
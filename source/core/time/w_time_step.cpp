#include "w_time_step.h"

namespace engine
{

WTimeStep::WTimeStep(WTime step)
    : m_step(step)
{
}

WTime WTimeStep::getStep() const
{
    return m_step;
}

} // namespace engine

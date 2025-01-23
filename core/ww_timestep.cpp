#include "ww_timestep.h"

namespace engine
{

TimeStep::TimeStep(float step)
    : m_step(step)
{
}

float TimeStep::getStep() const
{
    return m_step;
}

float TimeStep::getStepMillis() const
{
    return m_step * 1000.0f;
}

} // namespace engine

#include "w_time_step.h"

namespace engine
{

WTimeStep::WTimeStep(float step)
    : m_step(step)
{
}

float WTimeStep::getStep() const
{
    return m_step;
}

float WTimeStep::getStepMillis() const
{
    return m_step * 1000.0f;
}

} // namespace engine

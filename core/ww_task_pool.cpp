#include "ww_task_pool.h"

namespace engine
{

TaskPool::TaskPool()
    : m_taskQueue(), m_taskQueueMutex()
{ // 默认构造任务池
}

TaskPool::TaskPool(std::size_t size)
    : m_taskQueue(), m_taskQueueMutex()
{
    // 指定size构造任务池
    m_taskQueue.reserve(size);
}

void TaskPool::submitTask(std::function<void()> task)
{
    std::lock_guard<std::mutex> lock(m_taskQueueMutex);
    m_taskQueue.emplace_back(task);
}

void TaskPool::executeTasks()
{
    std::lock_guard<std::mutex> lock(m_taskQueueMutex);
    // 同步执行任务，后续再考虑是否改为异步
    for (auto & func : m_taskQueue) {
        func();
    }
    m_taskQueue.clear();
}

} // namespace engine

#pragma once

#include <mutex>
#include <functional>
#include <ww_vector.h>

namespace engine
{

/**
 * @brief 任务池
 */
class TaskPool
{
protected:
    wwstl::vector<std::function<void()>> m_taskQueue;   // 任务队列
    std::mutex m_taskQueueMutex;                        // 互斥锁

public:
    TaskPool();

    explicit TaskPool(std::size_t size);

public:
    /**
     * @brief 提交任务
     */
    void submitTask(std::function<void()> task);

    /**
     * @brief 执行所有任务
     */
    void executeTasks();
};

} // namespace engine

#pragma once

#include <glm/glm.hpp>
#include "ww_key_code.h"
#include "ww_mouse_code.h"

namespace engine
{

/**
 * @brief 输入
 */
class Input
{
public:
    /**
     * @brief 按键是否按下
     */
    static bool isKeyPressed(KeyCode code);

    /**
     * @brief 鼠标是否按下
     */
    static bool isMouseButtonPressed(MouseCode code);

    /**
     * @brief 获取鼠标位置
     */
    static glm::vec2 getMousePosition();

    /**
     * @brief 获取鼠标位置 X
     */
    static float getMouseX();

    /**
     * @brief 获取鼠标位置 Y
     */
    static float getMouseY();
};

} // namespace engine

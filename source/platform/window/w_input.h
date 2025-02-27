#pragma once

#include <w_math.h>
#include <w_key_code.h>
#include <w_mouse_code.h>

namespace engine
{

/**
 * @brief 全局输入
 */
class WInput
{
public:
    /**
     * @brief 按键是否按下
     */
    static bool isKeyPressed(WKeyCode code);

    /**
     * @brief 鼠标是否按下
     */
    static bool isMouseButtonPressed(WMouseCode code);

    /**
     * @brief 获取鼠标位置
     */
    static vec2 getMousePosition();

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
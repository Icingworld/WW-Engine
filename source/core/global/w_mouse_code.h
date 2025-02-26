#pragma once

namespace engine
{

/**
 * @brief 鼠标码储存类型
 */
using mouse_code_type = unsigned char;

/**
 * @brief 鼠标码
 */
enum class WMouseCode
    : mouse_code_type
{
    // From glfw3.h
    Button0                = 0,
    Button1                = 1,
    Button2                = 2,
    Button3                = 3,
    Button4                = 4,
    Button5                = 5,
    Button6                = 6,
    Button7                = 7,

    ButtonLast             = Button7,
    ButtonLeft             = Button0,
    ButtonRight            = Button1,
    ButtonMiddle           = Button2
};

} // namespace engine

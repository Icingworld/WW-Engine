#pragma once

#include <w_shader.h>
#include <w_texture.h>

/**
 * @brief 方块
 */
class Cube
{
public:
    virtual ~Cube() = default;

public:
    virtual void init() = 0;

    virtual void draw() = 0;
};

/**
 * @brief 沙子
 */
class SandCube
    : public Cube
{
public:
    unsigned int m_sandVAO;      // 所有沙子类型应该共用一个VAO
    unsigned int m_sandVBO;

    engine::WShader m_sandCubeShader;
    engine::WTexture2D m_sandCubeTexture;

    float m_cubeVertices[180] = {
        // positions          // texture Coords
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

public:
    SandCube();

    ~SandCube() override;

public:
    void init() override;

    void draw() override;
};

/**
 * @brief 泥土方块
 */
class DirtCube
    : public Cube
{
public:
    unsigned int m_dirtVAO;      // 所有泥土类型应该共用一个VAO
    unsigned int m_dirtVBO;

    engine::WShader m_dirtCubeShader;
    engine::WTexture2DArray m_dirtCubeTexture;

    float m_cubeVertices[216] = {
        // positions          // texture Coords // texture index
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,       1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,       1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,       1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,       1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,       1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,       1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,       1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,       1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,       1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,       1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,       1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,       1.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,       1.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,       1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,       1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,       1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,       1.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,       1.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,       1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,       1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,       1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,       1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,       1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,       1.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,       2.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,       2.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,       2.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,       2.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,       2.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,       2.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,       0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,       0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,       0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,       0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,       0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,       0.0f
    };

public:
    DirtCube();

    ~DirtCube() override;

public:
    void init() override;

    void draw() override;
};
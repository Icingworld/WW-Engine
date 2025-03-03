#include "cube.h"

SandCube::SandCube()
    : m_sandVAO(0)
    , m_sandVBO(0)
    , m_sandCubeShader("assets/shader/cube/cube1.vs", "assets/shader/cube/cube1.fs")
    , m_sandCubeTexture("assets/texture/cube/sand.png")
{
}

SandCube::~SandCube()
{
    glDeleteVertexArrays(1, &m_sandVAO);
    glDeleteBuffers(1, &m_sandVBO);
}

void SandCube::init()
{
    // 加载方块顶点
    glGenVertexArrays(1, &m_sandVAO);
    glGenBuffers(1, &m_sandVBO);
    glBindVertexArray(m_sandVAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_sandVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_cubeVertices), &m_cubeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    // 绑定方块贴图
    m_sandCubeShader.use();
    m_sandCubeShader.setInt("texture0", 0);

    // 设置贴图参数
    m_sandCubeTexture.setTextureParams(GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST);
}

void SandCube::draw()
{
    glBindVertexArray(m_sandVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_sandCubeTexture.getTextureId());
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

DirtCube::DirtCube()
    : m_dirtVAO(0)
    , m_dirtVBO(0)
    , m_dirtCubeShader("assets/shader/cube/cube2.vs", "assets/shader/cube/cube2.fs")
    , m_dirtCubeTexture(std::vector<std::string>({
        "assets/texture/cube/moss_block.png",
        "assets/texture/cube/grass_block_side.png",
        "assets/texture/cube/dirt.png"
    }))
{
}

DirtCube::~DirtCube()
{
    glDeleteVertexArrays(1, &m_dirtVAO);
    glDeleteBuffers(1, &m_dirtVBO);
}

void DirtCube::init()
{
    // 加载方块顶点
    glGenVertexArrays(1, &m_dirtVAO);
    glGenBuffers(1, &m_dirtVBO);
    glBindVertexArray(m_dirtVAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_dirtVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_cubeVertices), &m_cubeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(5 * sizeof(float)));

    // 绑定方块贴图
    m_dirtCubeShader.use();
    m_dirtCubeShader.setInt("texture0", 0);

    // 设置贴图参数
    m_dirtCubeTexture.setTextureParams(GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST);
}

void DirtCube::draw()
{
    glBindVertexArray(m_dirtVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_dirtCubeTexture.getTextureId());
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}
#include "skybox.h"

Skybox::Skybox()
    : m_skyBoxVAO(0)
    , m_skyBoxVBO(0)
    , m_skyBoxShader("assets/shader/skybox/skybox.vs", "assets/shader/skybox/skybox.fs")
    , m_skyBoxTexture(std::array<std::string, 6>({
        "assets/texture/skybox/right.jpg",
        "assets/texture/skybox/left.jpg",
        "assets/texture/skybox/top.jpg",
        "assets/texture/skybox/bottom.jpg",
        "assets/texture/skybox/front.jpg",
        "assets/texture/skybox/back.jpg",
    }))
{
}

Skybox::~Skybox()
{
    glDeleteVertexArrays(1, &m_skyBoxVAO);
    glDeleteBuffers(1, &m_skyBoxVBO);
}

void Skybox::init()
{
    // 加载天空盒顶点
    glGenVertexArrays(1, &m_skyBoxVAO);
    glGenBuffers(1, &m_skyBoxVBO);
    glBindVertexArray(m_skyBoxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_skyBoxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_skyBoxVertices), &m_skyBoxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // 绑定天空盒贴图
    m_skyBoxShader.use();
    m_skyBoxShader.setInt("skybox", 0);
}

void Skybox::draw()
{
    glBindVertexArray(m_skyBoxVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_skyBoxTexture.getTextureId());
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}
#pragma once
#include <GL/glew.h>
#include "Shader.h"
#include "VertexArray.h"
#include "Snake.h"
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError(); x; ASSERT(GLLogCall())

void GLClearError();
bool GLLogCall();

class Renderer 
{
private:
public:
	void clear() const;
	void drawGrid(const VertexArray& va, Shader& shader, const glm::vec3 pos[][20], const int& size, const glm::mat4& pv) const;
	void drawSnake(const VertexArray& va, Shader& shader, const Snake& snake, const glm::mat4& pv, Bait& bait);
};
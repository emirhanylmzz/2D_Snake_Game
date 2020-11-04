#include <GL/glew.h>
#include <iostream>
#include "Renderer.h"
#include "gtc/matrix_transform.hpp"
#include "glm.hpp"
#include "Snake.h"
using namespace std;
void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall()
{
	while (GLenum error = glGetError())
	{
		cout << "[OpenGL Error] (" << error << ")" << endl;
		return false;
	}
	return true;
}
void Renderer::clear() const 
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
void Renderer::drawGrid(const VertexArray& va, Shader& shader, const glm::vec3 pos[][20], const int& size, const glm::mat4& pv) const
{
	shader.Bind();
	va.Bind();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (int i = 0; i < 20; ++i) 
	{
		for (int j = 0; j < 20; ++j)
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), pos[i][j]);
			glm::mat4 mvp = pv * model;

			shader.SetUniformMat4f("u_MVP", mvp);
			shader.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
			GLCall(glDrawArrays(GL_QUADS, 0, 4));
		}	
	}
}

void Renderer::drawSnake(const VertexArray& va, Shader& shader, const Snake& snake, const glm::mat4& pv, Bait& bait)
{
	va.Bind();
	shader.Bind();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	for(unsigned int i = 0; i < snake.getPos().size(); ++i)
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), snake.getPos(i));
		glm::mat4 mvp = pv * model;
		shader.SetUniformMat4f("u_MVP", mvp);
		shader.SetUniform4f("u_Color", 0.0f, 1.0f, 0.0f, 1.0f);
		GLCall(glDrawArrays(GL_QUADS, 0, 4));
	}
	//drawing bait
	glm::mat4 model = glm::translate(glm::mat4(1.0f), bait.pos);
	glm::mat4 mvp = pv * model;
	shader.SetUniformMat4f("u_MVP", mvp);
	shader.SetUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);
	GLCall(glDrawArrays(GL_QUADS, 0, 4));
}


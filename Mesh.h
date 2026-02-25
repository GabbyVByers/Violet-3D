
#pragma once

#include "Core.h"
#include "Vertex.h"
#include "Camera.h"
#include "Window.h"
#include "Transformation.h"

class Violet::Mesh : public Violet::Transformation {
public:
	// Mesh.Lifetime.cpp
	Mesh() = default;
	~Mesh() = default;
	void init(std::string path = "default", int primativeType = GL_TRIANGLES);
	void destroy();

	// Mesh.Accessors.cpp
	int getPrimativeType() const;
	uint getVAO() const;
	uint getVBO() const;
	uint getShaderProgram() const;
	void setColor(const Color& color);
	void setRandomColors();
	
	// Deletions
	const Matrix calculateViewMatrix() const = delete;

private:
	// Mesh.Private.cpp
	void assertVertexShader(uint vertProgram) const;
	void assertFragmentShader(uint fragProgram) const;
	void assertShaderProgram() const;
	static std::string loadFileAsString(std::string path);

public:
	// Members
	std::vector<Vertex> vertices;
private:
	bool m_uninitialized = false;
	int m_primativeType = GL_TRIANGLES;
	uint m_VAO = 0;
	uint m_VBO = 0;
	uint m_shaderProgram = 0;
};


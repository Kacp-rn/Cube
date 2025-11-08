#pragma once

#include "../glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <stdlib.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
    private:
    unsigned int VertexShader;
    unsigned int FragmentShader;
    unsigned int Program_ID;

    std::string _shader_path;

    public:
    ~Shader();
    const char* ReadShader(const std::string& shader_path);
    void VertexShaderCompile(const char* CompilingShaderSource);
    void FragmentShaderCompile(const char* CompilingShaderSource);
    void createProgram();
    void use();
    unsigned int getProgramID() const;
    void setProgramID();
};
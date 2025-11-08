#include "shader.h"

const char* Shader::ReadShader(const std::string& shader_path)
{
    this->_shader_path = shader_path;
    
    
    std::ifstream PathFile(_shader_path);
    

    if(!PathFile.is_open())
    {
        std::cerr<<"Failed to open Shader-file"<<std::endl;
    }
    std::stringstream Pathed_Shader;
    
    Pathed_Shader << PathFile.rdbuf();
    
    PathFile.close();
    
    std::string com_shader_path = Pathed_Shader.str();
    
    const char* CompilingPath= com_shader_path.c_str();

    return CompilingPath;
}

void Shader::VertexShaderCompile(const char* CompilingShaderSource)
{
    VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShader, 1, &CompilingShaderSource, nullptr);
    glCompileShader(VertexShader);
}

void Shader::FragmentShaderCompile(const char* CompilingShaderSource)
{
    VertexShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader, 1, &CompilingShaderSource, nullptr);
    glCompileShader(FragmentShader);
}

void Shader::createProgram()
{
    Program_ID = glCreateProgram();
    glAttachShader(Program_ID, VertexShader);
    glAttachShader(Program_ID, FragmentShader);
    glLinkProgram(Program_ID);
    glDeleteShader(FragmentShader);
    glDeleteShader(VertexShader);
}

void Shader::use()
{
    glUseProgram(Program_ID);

    int vertexColorLocation = glGetUniformLocation(Program_ID, "ourColor");
    glUniform4f(vertexColorLocation, 1.0f, (rand()%360)*glfwGetTime(), 0.0f, 1.0f);
}

Shader::~Shader()
{
    glDeleteProgram(Program_ID);
}
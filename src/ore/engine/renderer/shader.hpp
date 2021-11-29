#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <ore/libs/glad/glad.h>

using namespace std;

namespace Ore
{
  class Shader
  {
  public:
    GLuint id = 0;

    Shader();
    Shader(string shaderName);

    static Shader *acquire(string shaderName);
    void use();

    void setInt(const char *name, int value) const;
    void setBool(const char *name, bool value) const;
    void setFloat(const char *name, float value) const;

  private:
    static map<string, Shader *> shaders;

    static bool compiledStatus(GLint shaderID);
    static GLuint makeVertexShader(const char *shaderSource);
    static GLuint makeFragmentShader(const char *shaderSource);
    static GLuint makeShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID);
    static GLuint makeShaderProgram(string vertexShaderSource, string fragmentShaderSource);
  };
} // namespace Ore

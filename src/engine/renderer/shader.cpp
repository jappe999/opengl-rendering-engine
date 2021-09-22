#include <engine/renderer/shader.hpp>
#include <engine/utils/filesystem.hpp>

map<string, Shader *> Shader::shaders;

Shader::Shader()
{
  id = 0;
}

Shader::Shader(string shaderName)
{
  Shader *&shader = shaders[shaderName];

  if (shader != nullptr)
  {
    id = shader->id;
  }
  else
  {
    string vertexShaderSource = getPath("assets/shaders/" + shaderName + ".vert");
    string fragmentShaderSource = getPath("assets/shaders/" + shaderName + ".frag");

    id = Shader::makeShaderProgram(vertexShaderSource, fragmentShaderSource);
    shader = this;
  }
}

void Shader::use()
{
  if (id != 0)
    glUseProgram(id);
}

Shader *Shader::acquire(string shaderName)
{
  Shader *&shader = shaders[shaderName];

  if (shader == nullptr)
    shader = new Shader(shaderName);

  return shader;
}

void Shader::setInt(const char *name, int value) const
{
  if (id != 0)
    glUniform1i(glGetUniformLocation(id, name), value);
}

void Shader::setBool(const char *name, bool value) const
{
  if (id != 0)
    glUniform1i(glGetUniformLocation(id, name), (int)value);
}

void Shader::setFloat(const char *name, float value) const
{
  if (id != 0)
    glUniform1f(glGetUniformLocation(id, name), value);
}

bool Shader::compiledStatus(GLint shaderID)
{
  GLint compiled = 0;
  glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);
  if (compiled)
  {
    return true;
  }
  else
  {
    GLint logLength;
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
    char *msgBuffer = new char[logLength];
    glGetShaderInfoLog(shaderID, logLength, NULL, msgBuffer);
    printf("%s\n", msgBuffer);
    delete (msgBuffer);
    return false;
  }
}

GLuint Shader::makeVertexShader(const char *shaderSource)
{
  GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShaderID, 1, (const GLchar **)&shaderSource, NULL);
  glCompileShader(vertexShaderID);
  bool compiledCorrectly = compiledStatus(vertexShaderID);

  if (compiledCorrectly)
    return vertexShaderID;

  return -1;
}

GLuint Shader::makeFragmentShader(const char *shaderSource)
{
  GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShaderID, 1, (const GLchar **)&shaderSource, NULL);
  glCompileShader(fragmentShaderID);
  bool compiledCorrectly = compiledStatus(fragmentShaderID);

  if (compiledCorrectly)
    return fragmentShaderID;

  return -1;
}

GLuint Shader::makeShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
{
  GLuint shaderID = glCreateProgram();
  glAttachShader(shaderID, vertexShaderID);
  glAttachShader(shaderID, fragmentShaderID);
  glLinkProgram(shaderID);
  return shaderID;
}

GLuint Shader::makeShaderProgram(string vertexShaderPath, string fragmentShaderPath)
{
  cout << "Compiling shader " << vertexShaderPath << endl;
  char *vertexShaderContent = readFile(vertexShaderPath);
  GLuint vertexShaderId = Shader::makeVertexShader(vertexShaderContent);
  delete[] vertexShaderContent;

  cout << "Compiling shader " << fragmentShaderPath << endl;
  char *fragmentShaderContent = readFile(fragmentShaderPath);
  GLuint fragmentShaderId = Shader::makeFragmentShader(fragmentShaderContent);
  delete[] fragmentShaderContent;

  return Shader::makeShaderProgram(vertexShaderId, fragmentShaderId);
}
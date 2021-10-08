#version 450 core

in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
   vec4 PositionRelativeToCamera = view * vec4(position, 1.0);

   // Calculate the clip-space position of each vertex
   gl_Position = projection * PositionRelativeToCamera;
}
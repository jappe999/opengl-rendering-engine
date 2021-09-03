#version 450 core

in vec3 position;

uniform mat4 view;
uniform mat4 projection;

void main()
{
   // Calculate the clip-space position of each vertex
   vec4 pos = projection * view * vec4(position, 1.0);
   gl_Position = pos.xyzw;
}
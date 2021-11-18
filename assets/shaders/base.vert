#version 410 core

in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
   // Calculate light vector
   vec3 Position = vec3(model * vec4(position, 1.0));

   vec4 PositionRelativeToCamera = view * vec4(Position, 1.0);

   // Calculate the clip-space position of each vertex
   gl_Position = projection * PositionRelativeToCamera;
}
#version 150 core

uniform sampler2D tex;

uniform float scaleFactor;

in Vertex {
	smooth vec4 colour;
	smooth vec2 texCoord;
} IN;

out vec4 gl_FragColor;

void main(void){
	gl_FragColor = texture(tex, IN.texCoord * 100);
}
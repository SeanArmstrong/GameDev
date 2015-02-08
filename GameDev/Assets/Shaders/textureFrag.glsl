#version 330 core
//Perform a non-trivial blend between two textures

uniform sampler2D smileyTex;
uniform sampler2D staticTex;
uniform sampler2D brickTex;

uniform float scaleFactor;

in Vertex {
	smooth vec4 colour;
	smooth vec2 texCoord;
} IN;

//int vec2 texCoord;

out vec4 gl_FragColor;

void main(void){
	vec4 t0 = texture(smileyTex, IN.texCoord);
	vec4 t1 = texture(staticTex, IN.texCoord);
	vec4 t2 = texture(brickTex, IN.texCoord);
	
	float avg = (t2.r + t2.g + t2.b)/3;

	gl_FragColor = mix(t0, t1, avg);
}
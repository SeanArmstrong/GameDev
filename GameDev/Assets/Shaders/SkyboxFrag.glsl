# version 150 core

uniform samplerCube tex;
uniform vec3 cameraPos;

in Vertex {
	vec3 normal;
} IN;

 out vec4 gl_FragColor;

void main ( void ) {
	gl_FragColor = texture(tex, normalize(IN.normal));
	//gl_FragColor = vec4(IN.normal, 1.0);
}
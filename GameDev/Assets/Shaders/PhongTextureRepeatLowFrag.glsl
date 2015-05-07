# version 330 core
// Lighting
uniform sampler2D tex0;

uniform vec3 cameraPos;

uniform vec3 lightColour3;
uniform vec3 lightPos;
uniform float lightRadius;

in Vertex {
	vec3 worldPos;
	vec2 texCoord;
	vec3 normal;
} IN; 

out vec4 gl_FragColor;

void main ( void ) {
	vec3 incident = normalize( lightPos - IN.worldPos );
	vec3 viewDir = normalize( cameraPos - IN.worldPos );
	vec3 halfDir = normalize( incident + viewDir );

	float dist = length(lightPos - IN.worldPos);
	float atten = 1.0 - clamp(dist / lightRadius , 0.0 , 1.0);

	float lambert = max(0.0, dot(incident, IN.normal));

	float rFactor = max(0.0, dot(halfDir, IN.normal));
	float sFactor = pow(rFactor, 50.0);

	vec4 texCol = texture(tex0, IN.texCoord * 10);
	vec3 ambient = texCol.rgb * lightColour3 * 0.1;
	vec3 diffuse = texCol.rgb * lightColour3 * lambert * atten;
	vec3 specular = lightColour3 * sFactor * atten;
	gl_FragColor = vec4(ambient + diffuse + specular , 1.0);
}

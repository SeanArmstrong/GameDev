# version 330 core
// Lighting

const int MAX_POINT_LIGHTS = 4;

struct PointLight
{
	vec3 colour;
	float intensity;
	vec3 position;
}

uniform sampler2D tex0;

uniform vec3 cameraPos;

uniform vec3 lightColour;
uniform vec3 lightPos;
uniform float lightRadius;

uniform PointLight pointLights[NUM_POINT_LIGHTS];

in Vertex {
	vec3 worldPos;
	vec2 texCoord;
	vec3 normal;
} IN; 

out vec4 gl_FragColor;

vec4 calcPointLight(PointLight pl, vec3 normal)
{
	vec3 lightDirection = worldPos - pl.position;
	float distanceToPoint = length(lightDirection);
	lightDirection = normalize(lightDirection);
}

void main ( void ) {
	vec3 incident = normalize( lightPos - IN.worldPos );
	vec3 viewDir = normalize( cameraPos - IN.worldPos );
	vec3 halfDir = normalize( incident + viewDir );

	float dist = length(lightPos - IN.worldPos);
	float atten = 1.0 - clamp(dist / lightRadius , 0.0 , 1.0);

	float lambert = max(0.0, dot(incident, IN.normal));

	float rFactor = max(0.0, dot(halfDir, IN.normal));
	float sFactor = pow(rFactor, 50.0);

	vec4 texCol = texture(tex0, IN.texCoord);
	vec3 ambient = texCol.rgb * lightColour * 0.1;
	vec3 diffuse = texCol.rgb * lightColour * lambert * atten;
	vec3 specular = lightColour * sFactor * atten;
	gl_FragColor = vec4(ambient + diffuse + specular , 1.0);
}

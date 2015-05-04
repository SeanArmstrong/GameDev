#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer(){
	glEnable(GL_DEPTH_TEST);
}


SFMLRenderer::~SFMLRenderer(void){
	for (vector<RenderObject*>::iterator i = renderObjects.begin(); i != renderObjects.end(); ++i) {
		delete *i;
	}
}

void SFMLRenderer::RenderScene(){
	if (skybox){
		RenderSkybox(*skybox->getRenderObject());
	}
	for (vector<RenderObject*>::iterator i = renderObjects.begin(); i != renderObjects.end(); ++i) {
		Render(*(*i));
	}
}

void SFMLRenderer::Render(const RenderObject &o) {
	modelMatrix = o.GetWorldTransform();

	if (o.GetShader() && o.GetMesh()) {
		GLuint program = o.GetShader()->GetShaderProgram();

		glUseProgram(program);

		UpdateShaderMatrices(program);
		ApplyShaderLight(program);

		o.Draw();
	}

	for (vector<RenderObject*>::const_iterator i = o.GetChildren().begin(); i != o.GetChildren().end(); ++i) {
		Render(*(*i));
	}
}

void SFMLRenderer::RenderSkybox(const RenderObject& o){
	if (o.GetShader() && o.GetMesh()) {
		GLuint program = o.GetShader()->GetShaderProgram();

		glUseProgram(program);

		UpdateShaderMatrices(program);
		ApplyShaderLight(program);

		o.DrawSkybox();
	}
}

void SFMLRenderer::UpdateScene(float msec) {
	for (vector<RenderObject*>::iterator i = renderObjects.begin(); i != renderObjects.end(); ++i) {
			(*i)->Update(msec);
	}
}

/*
Updates the uniform matrices of the current shader. Assumes that
the shader has uniform matrices called modelMatrix, viewMatrix,
projMatrix, and textureMatrix. Updates them with the relevant
matrix data. Sanity checks currentShader, so is always safe to
call.
*/
void SFMLRenderer::UpdateShaderMatrices(GLuint program)	{
	glUniformMatrix4fv(glGetUniformLocation(program, "modelMatrix"), 1, false, (float*)&modelMatrix);
	glUniformMatrix4fv(glGetUniformLocation(program, "viewMatrix"), 1, false, (float*)&viewMatrix);
	glUniformMatrix4fv(glGetUniformLocation(program, "projMatrix"), 1, false, (float*)&projMatrix);
	glUniformMatrix4fv(glGetUniformLocation(program, "textureMatrix"), 1, false, (float*)&textureMatrix);
	glUniform1f(glGetUniformLocation(program, "time"), GameTimer::getTime() * 0.0001f);
}

void SFMLRenderer::ApplyShaderLight(GLuint program){
	Matrix3 rotation = Matrix3(viewMatrix);
	Vector3 invCamPos = viewMatrix.GetPositionVector();
	Vector3 camPos = rotation * -invCamPos;

	glUniform3f(glGetUniformLocation(program, "cameraPos"), camPos.x, camPos.y, camPos.z);
	glUniform4f(glGetUniformLocation(program, "lightColour4"), currentLight.colour.x, currentLight.colour.y, currentLight.colour.z, 1.0f);
	glUniform3f(glGetUniformLocation(program, "lightColour3"), currentLight.colour.x, currentLight.colour.y, currentLight.colour.z);
	glUniform3f(glGetUniformLocation(program, "lightPos"), currentLight.position.x, currentLight.position.y, currentLight.position.z);
	glUniform1f(glGetUniformLocation(program, "lightRadius"), currentLight.radius);
}
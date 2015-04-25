#include "RenderObject.h"


RenderObject::RenderObject(void)	{
	mesh	= NULL;
	shader	= NULL;
	tex		= NULL;
	parent  = NULL;
}

RenderObject::RenderObject(Mesh*m, Shader*s, GLuint t) {
	Intialize(m, s, t);
}

void RenderObject::Intialize(Mesh*m, Shader*s, GLuint t) {
	mesh = m;
	shader = s;
	tex = t;
	parent = NULL;
}





RenderObject::~RenderObject(void)
{
	glDeleteTextures(1, &tex);
}


void RenderObject::Update(float msec) {
	if(parent) {
		worldTransform = parent->modelMatrix * modelMatrix;
		//worldTransform = modelMatrix * parent->modelMatrix;
	}
	else {
		worldTransform = modelMatrix;
	}

	for(vector<RenderObject*>::const_iterator i = children.begin(); i != children.end(); ++i ) {
		(*i)->Update(msec);
	}
}

void RenderObject::Draw() const {
	if(mesh) {
		/* Textures */
		GLuint program = GetShader()->GetShaderProgram();

		glUseProgram(program);

		glEnable(GL_TEXTURE_2D);

		glUniform1i(glGetUniformLocation(program, "tex"), 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		mesh->Draw();
	}
}

void RenderObject::DrawSkybox() const{
	/*if (mesh) {
		GLuint program = GetShader()->GetShaderProgram();

		glUseProgram(program);

		glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

		mesh->Draw();
	}*/
	if (mesh) {
		glDepthMask(GL_FALSE);
		GLuint program = GetShader()->GetShaderProgram();
		glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

		glUseProgram(program);

		glEnable(GL_TEXTURE_2D);

		glUniform1i(glGetUniformLocation(program, "tex"), 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, tex);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		mesh->Draw();
		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);		glDepthMask(GL_TRUE);

	}
}

#pragma once
#include "../NCLGL/OGLRenderer.h"

class Camera;
class Mesh;
class HeightMap;

class Renderer : public OGLRenderer	{
public:
	Renderer(Window &parent);
	 ~Renderer(void);

	 void RenderScene()				override;
	 void UpdateScene(float msec)	override;

	 inline void SetRotation(float r) { rotation = r; }
protected:
	//Mesh*	triangle;

	void PresentScene();
	void DrawPostProcess();
	void DrawScene();

	void DrawShadowScene();
	void DrawMainScene();
	void DrawSkybox();
	void DrawMirrors();

	GLuint shadowTex;
	GLuint shadowFBO;

	GLuint sceneDiffuse;
	GLuint sceneBump;
	float sceneTime;

	GLuint cubeMap;
	GLuint mirrorTex;


	GLuint bufferFBO;
	GLuint processFBO;
	GLuint bufferColourTex[2];
	GLuint bufferDepthTex;


	Shader* sceneShader;
	Shader* shadowShader;
	Shader* skyboxShader;
	Shader* reflectShader;
	Shader* pprocessShader;

	Mesh* quad;
	HeightMap* heightMap;
	Mesh* skyboxQuad;
	Mesh* mirrorQuad;
	vector<Mesh*> sceneMeshes;
	vector<Matrix4> sceneTransforms;

	vector<Matrix4> mirrorTransforms;


	Camera* camera;
	Light* light;

	float rotation;
};


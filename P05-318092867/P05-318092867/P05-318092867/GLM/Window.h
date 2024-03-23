#pragma once
#include<stdio.h>
#include<glew.h>
#include<glfw3.h>

class Window
{
public:
	Window();
	Window(GLint windowWidth, GLint windowHeight);
	int Initialise();
	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }
	bool getShouldClose() {
		return  glfwWindowShouldClose(mainWindow);
	}
	bool* getsKeys() { return keys; }
	GLfloat getXChange();
	GLfloat getYChange();
	void swapBuffers() { return glfwSwapBuffers(mainWindow); }
	GLfloat getmueve() { return mueve; }
	GLfloat getangulocola() { return angulocola; }
	GLfloat getangulocabeza() { return angulocabeza; }
	GLfloat getangulomandibula() { return angulomandibula; }
	GLfloat getangulopata1() { return angulopata1; }
	GLfloat getangulopata2() { return angulopata2; }
	GLfloat getangulopata3() { return angulopata3; }
	GLfloat getangulopata4() { return angulopata4; }
	GLfloat getangulollantas() { return angulollantas; }
	GLfloat getangulocofre() { return angulocofre; }

	~Window();
private:
	GLFWwindow* mainWindow;
	GLint width, height;
	bool keys[1024];
	GLint bufferWidth, bufferHeight;
	void createCallbacks();
	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
	GLfloat rotax, rotay, rotaz;
	GLfloat mueve;
	GLfloat angulocola = 0.0f;
	GLfloat angulocabeza = 0.0f;
	GLfloat angulomandibula = 0.0f;
	GLfloat angulopata1 = 0.0f;
	GLfloat angulopata2 = 0.0f;
	GLfloat angulopata3 = 0.0f;
	GLfloat angulopata4 = 0.0f;
	GLfloat angulollantas = 0.0f;
	GLfloat angulocofre = 0.0f;
	bool mouseFirstMoved;
	static void ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode);
	static void ManejaMouse(GLFWwindow* window, double xPos, double yPos);

};


#include <stdio.h>
#include <glew.h>
#include <glfw3.h>
//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;  // Es el tamaño d elas ventanas (numero de pixeles 800x600)
float rojo, verde, azul = 0; // para los colores 
int contaRGB = 1;

int main()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");		// No estan bien las propiedades del proyecto (manual)
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana // avaisa que esta usando el API de OpenGL y version //se deben de comentar en caso de error o que la consola no la soporte 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);   // Sirve para las versiones 3 y 4 para usar mejores versiones 

	//CREAR VENTANA
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1", NULL, NULL); // Indica el modo ventana en un monitor a la vez 

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	int BufferWidth, BufferHeight;     // Una vez es creado el contenedor este tamaño de pixles lo va a almacenar en memoria (pixeles de anchox alto) sirve para indicar datos o para redimensionar posteriormente (desde programa o manuelmente en la ventana)
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);  // La ventana activa es la ventana que creemos y no reaccione con otra

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE; 

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");	// Algo no se agrego correctamente
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas	//Inicia el lenguage OpenGL
	//Asignar Viewport
	glViewport(0, 0, BufferWidth, BufferHeight);	// Ajusta relacion entre el tamaño de memoria para la cantidad de pixeles
	printf("Version de Opengl: %s \n",glGetString(GL_VERSION));
	printf("Marca: %s \n", glGetString(GL_VENDOR));
	printf("Renderer: %s \n", glGetString(GL_RENDERER));
	printf("Shaders: %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	//Loop mientras no se cierra la ventana		//Mientras la ventana esta activa entra en este ciclo
	while (!glfwWindowShouldClose(mainWindow))	// Cuando se cierra manda TRUE
	{
		//Recibir eventos del usuario
		glfwPollEvents();	// Se queda 'escuchando' ordenes del usuario y recibir datos
		
		//Limpiar la ventana
		glClearColor(rojo, verde, azul, 1.0f);	// Establece el fondo de la ventana RGBA (A= transparencia, generalmente A=1)
		glClear(GL_COLOR_BUFFER_BIT);
		switch (contaRGB)
		{
		case 1:
			rojo = 1.0;
			verde = 0.0;
			azul = 0.0;
			break;
		case 2:
			rojo = 0.0;
			verde = 1.0;
			azul = 0.0;
			break;
		case 3:
			rojo = 0.0;
			verde = 1.0;
			azul = 0.0;
			break;

			glfwSwapBuffers(mainWindow); // Cambia cada ciclo de reloj
			// NO ESCRIBIR NADA

		default:
			break;
		}
		
		if (contaRGB < 4)
		{
			contaRGB++;
		}else
		{
			contaRGB = 1;
		}


		
	}
	glfwDestroyWindow(mainWindow); //Se borra toda la memoria/informacion asignada 

	return 0;
}// Esta parte del programa 

#include <stdio.h>
#include <glew.h>
#include <glfw3.h>
//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;  // Es el tamaño d elas ventanas (numero de pixeles 800x600)
float rojo=0, verde=0, azul = 0; // para los colores 
int contaTime = 0;

int main()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");		// No estan bien las propiedades del proyecto (manual)
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana // avaisa que esta usando el API de OpenGL y version //se deben de comentar en caso de error o que la consola no la soporte 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);   // Sirve para las versiones 3 y 4 para usar mejores versiones 

	//CREAR VENTANA
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Ejercicio 01 pt1", NULL, NULL); // Indica el modo ventana en un monitor a la vez 

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	int BufferWidth, BufferHeight;     // Una vez es creado el contenedor este tamaño de pixles lo va a almacenar en memoria (pixeles de anchox alto) sirve para indicar datos o para redimensionar posteriormente (desde programa o manuelmente en la ventana)
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);  // La ventana activa es la ventana que creemos y no reaccione con otra

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");	// Algo no se agrego correctamente
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas	//Inicia el lenguage OpenGL
	//Asignar Viewport
	glViewport(0, 0, BufferWidth, BufferHeight);	// Ajusta relacion entre el tamaño de memoria para la cantidad de pixeles
	printf("Version de Opengl: %s \n", glGetString(GL_VERSION));
	printf("Marca: %s \n", glGetString(GL_VENDOR));
	printf("Renderer: %s \n", glGetString(GL_RENDERER));
	printf("Shaders: %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	//Loop mientras no se cierra la ventana		//Mientras la ventana esta activa entra en este ciclo
	
	while (!glfwWindowShouldClose(mainWindow)) // Cuando se cierra manda TRUE
	{
		//Recibir eventos del usuario
		glfwPollEvents();	// Se queda 'escuchando' ordenes del usuario y recibir datos

		if (contaTime<4000)
		{	rojo = 1;
			verde = 0;
			azul = 0;
		}
		else if (contaTime < 8000)
		{	rojo = 0;
			verde = 1;
			azul = 0;
		}
		else if (contaTime < 12000)
		{	rojo = 0;
			verde = 0;
			azul = 1;
		}
		else
		{	contaTime = 0;
		}
		contaTime++;

		//Limpiar la ventana
		glClearColor(rojo, verde, azul, 1.0f); // Establece el fondo de la ventana RGBA (A= transparencia, generalmente A=1)
		glClear(GL_COLOR_BUFFER_BIT); 

		glfwSwapBuffers(mainWindow);
		// NO ESCRIBIR NADA

	}
	glfwDestroyWindow(mainWindow); //Se borra toda la memoria/informacion asignada 

	return 0;
}
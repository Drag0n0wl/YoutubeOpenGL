#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main()
{
    //Initialize glfw to create a window
	glfwInit();

	//Hint to tell GLFW what version to use
	//In this case we're using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Tell GLFW we're using the CORE profile
	//So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//This is the data type for the window  object in GLFW, name it window with a createwindow func.
	//Create a GLFwindow object of 800 x 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	//error checking in case the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//Need to tell GLFW to use the created window; to make the current window part of the current context
	//Intoduce the window into the current context
	glfwMakeContextCurrent(window);

	//Use Glad to load needed configs for OpenGL
	//Load GLAD so it configures OpenGL
	gladLoadGL();

	//Tell OpenGL the viewport of our window
	//Specify the viewport of OpenGL in the window
	//In this case the viewport goes from x=0, y=0, to x=800, y=800
	glViewport(0, 0, 800, 800);

	//Tell OpenGL to prepare to clear the color of the buffer and give it another color
	//Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	//Tell OpenGL to execute the command it prepared for the color buffer
	//Clean the back buffer and assign new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	//Swap back buffer with the front buffers
	glfwSwapBuffers(window);

	//prevent window from automatically closing
	//Main while loop
	while (!glfwWindowShouldClose(window))
	{
		//ask glfw to poll all events
		// Take care of all GLFW events
		glfwPollEvents();
	}

	//Would like to destroy the window after using
	// Delete window before ending the program
	glfwDestroyWindow(window);
	//Terminate glfw before it ends
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}
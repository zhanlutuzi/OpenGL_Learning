
/*
-----------------------------------------------
������ʵ��������ɫ�����������
2022/3/24
-----------------------------------------------
GLAD��ͷ�ļ���������ȷ��OpenGLͷ�ļ�������GL/gl.h��
������Ҫ������������OpenGL��ͷ�ļ�֮ǰ����GLAD��
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/*-----------------��������---------------------
1.�������ڵĻص�����
2.���봦��...
---------------------------------------------*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{
	glfwInit();
	//���ð汾��Ϊ3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//��֪Ϊ����ģʽ
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//MacOS������·����
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//�������ڶ���
	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Windows", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//��ʼ��GLAD,Э������OpenGL�ĺ���ָ��
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//�����ӿ�
	glViewport(0, 0, 800, 600);
	//���õ������ڵĲ������ص��Զ��庯��
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//��Ⱦѭ��
	while (!glfwWindowShouldClose(window))
	{
		//�������
		processInput(window);

		//�����ɫ����
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//״̬����
		glClear(GL_COLOR_BUFFER_BIT);//״̬ʹ��

		glfwSwapBuffers(window);//���������Ի���
		glfwPollEvents();//����¼�
	}

	//�ͷ���Դ
	glfwTerminate();
	return 0;
}

//����ʵ��------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	//����Esc���رմ���
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
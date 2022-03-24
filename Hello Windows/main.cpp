
/*
-----------------------------------------------
本程序实现了深绿色窗口体的生成
2022/3/24
-----------------------------------------------
GLAD的头文件包含了正确的OpenGL头文件（例如GL/gl.h）
所以需要在其它依赖于OpenGL的头文件之前包含GLAD。
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/*-----------------函数声明---------------------
1.调整窗口的回调函数
2.输入处理...
---------------------------------------------*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{
	glfwInit();
	//设置版本号为3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//告知为核心模式
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//MacOS需包含下方语句
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//创建窗口对象
	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Windows", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//初始化GLAD,协助管理OpenGL的函数指针
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//设置视口
	glViewport(0, 0, 800, 600);
	//设置调整窗口的操作，回调自定义函数
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//渲染循环
	while (!glfwWindowShouldClose(window))
	{
		//检查输入
		processInput(window);

		//清空颜色缓冲
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//状态设置
		glClear(GL_COLOR_BUFFER_BIT);//状态使用

		glfwSwapBuffers(window);//交换缓冲以绘制
		glfwPollEvents();//检查事件
	}

	//释放资源
	glfwTerminate();
	return 0;
}

//函数实现------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	//按下Esc键关闭窗口
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
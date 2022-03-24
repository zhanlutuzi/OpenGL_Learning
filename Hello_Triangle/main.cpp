/*
-----------------------------------------------

-----------------------------------------------
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//数据
//----

//顶点集合
float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};


//---------------------------------------------


/*-----------------函数声明---------------------
1.调整窗口的回调函数
2.输入处理
---------------------------------------------*/


int main()
{
	//生成缓冲对象
	GLuint VBO;
	glGenBuffers(1, &VBO);
	//绑定缓冲对象
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//传入顶点数据
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}
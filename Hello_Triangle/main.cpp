/*
-----------------------------------------------

-----------------------------------------------
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//����
//----

//���㼯��
float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};


//---------------------------------------------


/*-----------------��������---------------------
1.�������ڵĻص�����
2.���봦��
---------------------------------------------*/


int main()
{
	//���ɻ������
	GLuint VBO;
	glGenBuffers(1, &VBO);
	//�󶨻������
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//���붥������
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}
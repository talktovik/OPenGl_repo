/* variable dec specs: 
*/
//Do read the txt file, If I miss some theory here then I'll put it there. 


#include <stdio.h>
#include <GL/glew.h>// has to be included first
#include <GLFW/glfw3.h>
#include <iostream>
#include <string.h>
#include<stdlib.h>
#include<glm/glm.hpp>//glm included, relative path !
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<vector>
#include "Window.h"

#include "Mesh.h"
#include "Shader.h"


//Window Dimensions 
const GLint WIDTH = 800, HEiGHT = 600;
Window window;

const float toRadians = 3.14159265f/ 180.0f ;
std::vector<Mesh*>meshList;
std::vector<Shader>shaderList;

bool direction = true;
float trioffset = 0.0f;
float triMAXoffset = 0.7f;
float triIncriment = 0.00005f;//defines the speed.(Translation speed )

float curAngle = 0.0f;
bool sizeDirection = true;
float curSize = 0.4f;
float maxSize = 0.8;
float minSize = 0.1f;
//Vertex Shader
// Version 330 is glsl version
// vec3 holds 3 position where vec4 holds 4 values.
static const char* vshader = "Shaders/shader.vert";

//Fragment shader
static const char* fshader = "Shaders/shader.frag";

void CreateObjects() {

    unsigned int indices[] =
    {
        0,3,1,
        1,3,2,
        2,3,0,
        0,1,2,
    };
    GLfloat vertices[] = {
        -1.0f ,-1.0f ,0.0f , //index 1
        0.0f, -1.0f, 1.0f, //(moving in z axis)  index 2
        1.0f ,-1.0f ,0.0f , //index 2
        0.0f ,1.0f ,0.0f ,  //index 3
            };
    
 // Creating Objects of triangle
    Mesh* obj1 = new Mesh();
    obj1->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj1);

// Creating the Second Object on Screen
    Mesh* obj2 = new Mesh();
    obj2->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj2);



}

void CreateShader() {
    Shader* shader1 = new Shader();
    shader1->createFromFiles(vshader, fshader);
    shaderList.push_back(*shader1);

}
int main(void)
{
    window = Window(800, 600);
    window.Initialise();

    CreateObjects();
    CreateShader();

    GLuint uniformProjection = 0, uniformModel = 0;
     
    glm::mat4 projection = glm::perspective(45.0f,window.getBufferWidth() / window.getBufferHeight() ,0.1f,100.0f); 

    //Loop untill window closesd
    while (!window.getShouldClose())
    {
        //get+ Handle input events
        // this will care about user interactivity.
        glfwPollEvents();

        if (direction) {
        
            trioffset += triIncriment;
        }
        else {
            trioffset -= triIncriment;
        }
        if (abs(trioffset) >= triMAXoffset) {
            direction = !direction;
        }

        curAngle += 0.1f;
        if (curAngle >= 360); {
        
            curAngle -= 360;
        }
        if (sizeDirection) {
        
            curSize += 0.0001f;
        }
        else {
            curSize -= 0.0001f;
        }

        if (curSize >= maxSize || curSize <= minSize) {
            sizeDirection = !sizeDirection;
        }


        //Clear window
        //color values in float
        //alpha last parameter is about transparancy.
        glClearColor(0.0f,0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear the color actually // Clear the depth Buffer Bit

        shaderList[0].UseShader();
        uniformModel = shaderList[0].GetModelLocation();
        uniformProjection = shaderList[0].GetProjectionLocation();


        
         glm::mat4 model; // mat4 = 4x4 matrix (Identity Matrix)

        //The way we place this three statement will create different outcomes.
        model = glm::translate(model, glm::vec3(trioffset,0.0f, -2.5f));
       // model = glm::rotate(model, curAngle * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));


        //UNIFORM

        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

        //Draw Call
        meshList[0]->RenderMesh();

        //I guess This is the way to call for second obj
        model = glm::mat4(1.0f); //This Is actually a new Identity Matrix, And you can't redifine it like we did earlier.
        model = glm::translate(model, glm::vec3(-trioffset, 1.0f, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        meshList[1]->RenderMesh();
        
        glUseProgram(0);

        window.swapBuffers();
    
        
    }
    return 0;// don't put this fucking return inside the gameloop





















}//main function ends here.
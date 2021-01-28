/* variable dec specs: 
*/
//Do read the txt file, If I miss some theory here then I'll put it there. 


#include <stdio.h>
#include <GL/glew.h>// has to be included first
#include <GLFW/glfw3.h>
#include <iostream>
#include <string.h>



//Window Dimensions 
const GLint WIDTH = 800, HEiGHT = 600;
GLuint VAO, VBO, shader;

//Vertex Shader
// Version 330 is glsl version
// vec3 holds 3 position where vec4 holds 4 values.
static const char* vshader = "                    \n\
#version 330                                       \n\
layout(location = 0) in vec3 pos;                   \n\
  void main (){                                     \n\
    gl_Position = vec4(0.4 *pos.x, 0.4 * pos.y, pos.z ,1.0);   \n\
";

//Fragment shader
static const char* fshader = "                    \n\
#version 330                                       \n\
out vec4 colour ;                                   \n\
  void main (){                                     \n\
   colour = vec4(0.0,0.0,0.0,1.0);   \n\
";


void compileshader() {

    shader = glCreateProgram();
    printf("Error Creating Shader program");
    return;

}

void CreateTriange() {
    GLfloat vertices[] = {
        -1.0f ,-1.0f ,0.0f , 
        1.0f ,-1.0f ,0.0f ,
        0.0f ,1.0f ,0.0f ,
            };
    glGenVertexArrays(1, &VAO); //Creating VAO
    glBindVertexArray(VAO); // binding vertex array

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //binding buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);//unbinding buffer

    glBindVertexArray(0); //Unbinding vertex array 
}
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "GLFW linking Failed" << std::endl;
        glfwTerminate();
        return -1;
    }
    //Setting GLFW windows Property, OPenGL Versions 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //Core profile = No Backward Compactibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //Window is pointer to GLFWwindow. (Variable)
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIDTH, HEiGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout << "GLFW WINDOW CREATION FAILED" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Get Buffer Size Information
    int bufferwidth, bufferheight;
    glfwGetFramebufferSize(window, &bufferwidth, &bufferheight);
    // set context for GLEW to use.
    // Means if you have multiple windows the you can choose the....  
    //....working window like that
    glfwMakeContextCurrent(window);

    //Allow modern extension the features
    //This glewExperimental unleashes the power to use more exiciting things
    //.... to use in opengl.
    glewExperimental  = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        printf("the linking failed of Glew");
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }
    //Set Viewport
    glViewport(0, 0, bufferwidth, bufferheight);
    
    //Loop untill window closesd
    while (!glfwWindowShouldClose(window)) {
        //get+ Handle input events
        // this will care about user interactivity.
        glfwPollEvents();


        //Clear window
        //color values in float
        //alpha last parameter is about transparancy.
        glClearColor(0.0f,1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);// Clear the color actually

        glfwSwapBuffers(window);
    
        
    }
    return 0;// don't put this fucking return inside the gameloop





















}//main function ends here.
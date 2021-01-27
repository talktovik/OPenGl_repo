/* variable dec specs: 
*/
//Do read the txt file, If I miss some theory here then I'll put it there. 


#include <stdio.h>
#include <GL/glew.h>// has to be included first
#include <GLFW/glfw3.h>
#include <iostream>


//Window Dimensions 
const GLint WIDTH = 800, HEiGHT = 600;
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
    //Core profile = No Backwork Compactibility
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
        glClearColor(0.5f,1.0f, 1.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT);// Clear the color actually

        glfwSwapBuffers(window);
    
        
    }
    return 0;// don't put this fucking return inside the gameloop





















}//main function ends here.
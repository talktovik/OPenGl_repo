#include "Mesh.h"

Mesh::Mesh()
{
	VAO = 0;
	IBO = 0;
	IBO = 0;
	indexcout = 0;

}

void Mesh::CreateMesh(GLfloat* vertices, unsigned  int* indices, unsigned int numofVertices, unsigned int numofIndices)
{
	indexcout = numofIndices; // Number of Indices is INDEXES 
    glGenVertexArrays(1, &VAO); //Creating VAO
    glBindVertexArray(VAO); // binding vertex array


    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * numofIndices, indices, GL_STATIC_DRAW); // Doing the comman thing by  sizeof(indices[0]) * numofIndices



    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //binding buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numofVertices, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);//unbinding buffer

    glBindVertexArray(0); //Unbinding vertex array 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::RenderMesh() { // Its actually a draw Call 
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glDrawElements(GL_TRIANGLES, indexcout, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


}
void Mesh::ClearMesh() {
    if (IBO != 0)
    {
        glDeleteBuffers(1, &IBO);
        IBO = 0;
    }
    if (VBO != 0)
    {
        glDeleteBuffers(1, &VBO);
        VBO = 0;
    }
    if (VAO != 0)
    {
        glDeleteVertexArrays(1, &VAO);
        VAO = 0;
    }
    indexcout = 0;
}
Mesh::~Mesh() {
    ClearMesh();
}


#include "Mesh.h"

Mesh::Mesh()
{
	VAO = 0;
	IBO = 0;
	IBO = 0;
	indexcout = 0;

}
void Mesh::CreateMesh(GLfloat* vertices, unsigned int* indices, unsigned int numofVertices, unsigned int numofIndices)
{
	indexcout = numofIndices;
}
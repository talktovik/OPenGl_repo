#include "Shader.h"

Shader::Shader() {

	shaderID = 0;
	uniformModel = 0;
	uniformProjection = 0;
}
void Shader::CreateFromString(const char* vertexCode, const char* fragmentCode) {

	CompileShader(vertexCode, fragmentCode);

}

void Shader::createFromFiles(const char* vertexLocation, const char* fragmentLocation) {

    std::string vertexstring = Readfile(vertexLocation);
    std::string fragmentstring = Readfile(fragmentLocation);
    const char* vertexCode = vertexstring.c_str();
    const char* fragmentCode = fragmentstring.c_str();

    CompileShader(vertexCode, fragmentCode);
}


std::string Shader::Readfile(const char* fileLocation) {
    std::string content;
    std::ifstream filestream(fileLocation, std::ios::in);

    if (!filestream.is_open()) {
        std::cout << "File didn't opened" << std::endl;
        printf("Failed to rad %s file dodn't exist", fileLocation);
        return "";
    }
    std::string line = "";
    while(!filestream.eof()){
        std::getline(filestream, line);
        content.append(line + "\n");

    }
    filestream.close();
    return content;


}
void Shader::CompileShader(const char* vertexCode, const char* fragmentCode) {

    shaderID = glCreateProgram();
    if (!shaderID) {
        printf("Error Creating Shader program");
        return;
    }

    //calling the shader with parameters
    // clearly GL_VERTEX_SHADER is an enum !
    AddShader(shaderID, vertexCode, GL_VERTEX_SHADER);
    AddShader(shaderID, fragmentCode, GL_FRAGMENT_SHADER);


    GLint result = 0;
    GLchar  elog[1024] = { 0 };


    //Linking the shader code.
    glLinkProgram(shaderID);
    //Check the Error (Linking)
    glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
    if (!result) {
        glGetProgramInfoLog(shaderID, sizeof(elog), NULL, elog);
        printf("ERROR LINKING PROGRAM '%s'\n", elog);

    }


    //validating the shader code 
    glValidateProgram(shaderID);
    //checking the error (Validation)
    glGetProgramiv(shaderID, GL_VALIDATE_STATUS, &result);
    if (!result) {
        glGetProgramInfoLog(shaderID, sizeof(elog), NULL, elog);
        printf("ERROR VALIDATING PROGRAM '%s'\n", elog);
        return;

    }
    uniformProjection = glGetUniformLocation(shaderID, "projection"); //Loaction 
    uniformModel = glGetUniformLocation(shaderID, "model"); //Loaction 
   

}

void Shader::UseShader() {
    glUseProgram(shaderID);
}


void Shader::ClearShader() {
    if (shaderID != 0) {
        glDeleteProgram(shaderID);
        shaderID = 0;
    }
    uniformModel = 0;
    uniformProjection = 0;
}

GLuint Shader::GetProjectionLocation() {
    return uniformProjection;
}
GLuint Shader::GetModelLocation() {
    return uniformModel;
}



void Shader::AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType) {
    GLuint theShader = glCreateShader(shaderType);

    const GLchar* theCode[1];
    theCode[0] = shaderCode;
    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);

    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);

    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
    if (!result) {
        glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
        printf("ERROR COMPILING THE %d shader: '%s'\n", shaderType, eLog);
        return;
    }

    glAttachShader(theProgram, theShader);

}

Shader::~Shader() {
    ClearShader();

}

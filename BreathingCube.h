class Entity;

//===========================================================
// Class : BreathingCube
//===========================================================

class BreathingCube : public Entity
{

public:
    bool spinningCube = false;
    bool isPaused = false;
    bool spinningLocal = false;
    static GLuint staticVBO;
    static GLuint staticContainerVAO;

    BreathingCube(Shader * shader, glm::vec3 initial_pos, glm::vec4 initial_color) {
        m_type = ET_CUBE;

        m_shader = shader;
        m_initial_pos = initial_pos;
        m_pos = initial_pos;



        m_total_time = 0.0;

        m_initial_color = initial_color;
        m_color = m_initial_color;

        // Set up data for OpenGL: vertex data, buffers, and attribute pointers
        // Note that part 5 of your assignment will have you alter way that the
        // remainder of this method is set up such that we avoid repeat work.
        if (staticVBO == 0) {
        GLfloat vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
             0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
             0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
             0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
             0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

             0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
             0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
             0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
             0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
        };

        // First, set the container's VAO (and VBO)
        glGenVertexArrays(1, &staticContainerVAO);
        glGenBuffers(1, &staticVBO);

        glBindBuffer(GL_ARRAY_BUFFER, staticVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(staticContainerVAO);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        // Normal attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
        glBindVertexArray(0);
    }
    }

    ~BreathingCube() {
        //glDeleteBuffers(1, &staticVBO);
        //glDeleteVertexArrays(1, &staticContainerVAO);
    }

    void render() const {

        // Make sure always to set the current shader before setting uniforms/drawing objects
        if (m_shader) {
            m_shader->Use();

            // set cube's color
            GLint objectColorLoc = glGetUniformLocation(m_shader->Program, "objectColor");
            glUniform3f(objectColorLoc, m_color[0], m_color[1], m_color[2]);

            // Do matrix transformations
            //glm::mat4 translatedCubeModel = glm::translate(glm::mat4(), glm::vec3(m_pos));

            glm::mat4 translatedCubeModel;

            if (!isPaused) {
                if(spinningCube) translatedCubeModel = glm::rotate(translatedCubeModel, (float)(.5*glfwGetTime()), glm::vec3(0.0, 1.0 , 0.0));
            }
            translatedCubeModel = glm::translate(translatedCubeModel, glm::vec3(m_pos.x , m_pos.y, m_pos.z));
            if (!isPaused) {
                if(spinningLocal) translatedCubeModel = glm::rotate(translatedCubeModel, (float)(.5*glfwGetTime()), glm::vec3(0.0, 1.0 , 0.0));
            }
            translatedCubeModel = glm::scale(translatedCubeModel, glm::vec3(m_current_breath_amt));
            GLint modelLoc = glGetUniformLocation(m_shader->Program, "model"); // Get the locations of uniforms for the shader

            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(translatedCubeModel)); // Pass the transformed model matrix to the shader

        }

        // Draw the cube from its VAO
        glBindVertexArray(staticContainerVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
    }

    void update(double time_since_last_update) {
        m_delta =  0.5 * (m_pos.x + m_pos.y + m_pos.z);
        m_current_breath_amt = .56 + .36 * sin(m_total_time + m_delta) + .001;
        //glm::mat4 rotatingMatrix = glm::rotate(5, 0, 1, 0);

        m_color[0] = .8 * m_current_breath_amt;
        m_color[1] = m_initial_color[1];
        m_color[2] = 1- m_color[0];
        m_pos.z = m_initial_pos.z + (m_current_breath_amt * 1.28);
        m_total_time += time_since_last_update;
    }

protected:
    float m_current_breath_amt;
    GLfloat m_delta;
    glm::vec4 m_initial_color;
    glm::vec3 m_initial_pos;

    GLuint VBO;
    GLuint containerVAO;
};

GLuint BreathingCube::staticVBO = 0;
GLuint BreathingCube::staticContainerVAO = 0;

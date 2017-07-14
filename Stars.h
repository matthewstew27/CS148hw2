class Entity;

//===========================================================
// Class : Stars, creates star cubes in the sky
//===========================================================

class Star : public Entity
{
public:
    bool falling = false;
    static GLuint staticVBOStars;
    static GLuint staticContainerVAOStars;

	Star(Shader * shader, glm::vec3 initial_pos, glm::vec4 initial_color) {


		m_type = ET_STAR;
		m_shader = shader;
		m_initial_pos = initial_pos;
		m_pos = initial_pos;

		m_total_time = 0.0;

		m_initial_color = initial_color;
        m_color = m_initial_color;
        if (staticVBOStars == 0) {
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
        glGenVertexArrays(1, &staticContainerVAOStars);
        glGenBuffers(1, &staticVBOStars);

        glBindBuffer(GL_ARRAY_BUFFER, staticVBOStars);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(staticContainerVAOStars);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        // Normal attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
        glBindVertexArray(0);
    }
    }

	~Star () {
		//glDeleteBuffers(1, &VBO);
		//glDeleteVertexArray(0);
	}

	void render() const {

        // Make sure always to set the current shader before setting uniforms/drawing objects
        if (m_shader) {
            m_shader->Use();
            GLint objectColorLoc = glGetUniformLocation(m_shader->Program, "objectColor");
            glUniform3f(objectColorLoc, m_color[0], m_color[1], m_color[2]);

			glm::mat4 translatedCubeModel;
            translatedCubeModel = glm::translate(glm::mat4(), glm::vec3(m_pos));
            translatedCubeModel = glm::scale(translatedCubeModel, glm::vec3(.2, .2, .2));
            translatedCubeModel = glm::scale(translatedCubeModel, glm::vec3(m_current_breath_amt));
            GLint modelLoc = glGetUniformLocation(m_shader->Program, "model"); // Get the locations of uniforms for the shader
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(translatedCubeModel)); // Pass the transformed model matrix to the shader

        }

        // Draw the cube from its VAO
        glBindVertexArray(staticContainerVAOStars);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
    }
    void update(double time_since_last_update) {
    		m_delta =  0.5 * (m_pos.x + m_pos.y + m_pos.z);
            m_current_breath_amt = .56 + .36 * sin(m_total_time + m_delta) + .001;
            m_total_time += time_since_last_update;
            if (falling) {
                  m_pos.y = m_pos.y - 1;
            }
    }

protected:
    float m_current_breath_amt;
    GLfloat m_delta;
    glm::vec4 m_initial_color;
    glm::vec3 m_initial_pos;

    GLuint VBO;
    GLuint containerVAO;
};
GLuint Star::staticVBOStars = 0;
GLuint Star::staticContainerVAOStars = 0;
#include "shader_reader.h"
#include <stdio.h>
#include <stdlib.h>
char *shadsrc(const char* filename) {
    FILE *hndle = fopen(filename, "r");
    if (hndle == NULL) {
        printf("FNF\n");
        return NULL;
    }
    fseek(hndle, 0, SEEK_END);
    int size = ftell(hndle);
    rewind(hndle);
    char *buf = calloc(size, sizeof(char)*size);
    fread(buf, sizeof(char), size, hndle);
    return buf;
}

void init_shader(shader_t* shad_p, char *vertloc, char *fragloc) {
    shad_p->vert_shad = glCreateShader(GL_VERTEX_SHADER);
    const char *src = shadsrc(vertloc);
    glShaderSource(shad_p->vert_shad, 1, &src, NULL);
    glCompileShader(shad_p->vert_shad);

    shad_p->frag_shad = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fsrc = shadsrc(fragloc); 
    glShaderSource(shad_p->frag_shad, 1, &fsrc, NULL);
    glCompileShader(shad_p->frag_shad);

    shad_p->shad_prog = glCreateProgram();
    glAttachShader(shad_p->shad_prog, shad_p->vert_shad);
    glAttachShader(shad_p->shad_prog, shad_p->frag_shad);
    glLinkProgram(shad_p->shad_prog);
}

// Probably just use a macro
void shad_use(shader_t *shad) {
    glUseProgram(shad->shad_prog);
}

void shad_uni(shader_t *shad, char* uniform, float val) {
    int uniloc = glGetUniformLocation(shad->shad_prog, uniform);
    glUniform1f(uniloc, val);
}

void shad_uni4f(shader_t *shad, char* uniform, float f1, float f2, float f3, float f4) {
    int uniloc = glGetUniformLocation(shad->shad_prog, uniform);
    glUniform4f(uniloc, f1, f2, f3, f4);
}

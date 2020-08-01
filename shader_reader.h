#ifndef __shadread_head
#define __shadread_head
#include "glad/glad.h"
#include <GLFW/glfw3.h>
typedef struct {
    unsigned int vert_shad;
    unsigned int frag_shad;
    unsigned int shad_prog;
} shader_t;
char *shadsrc(const char* filename);
void init_shader(shader_t*, char*, char*);
void shad_use(shader_t*);
void shad_uni(shader_t *shad, char* uniform, float val);
void shad_uni4f(shader_t *shad, char* uniform, float f1, float f2, float f3, float f4);
#endif

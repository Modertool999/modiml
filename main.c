#include <stdio.h>



typedef struct {
    uint32_t rows;
    uint32_t cols;
    float data;
} matrix;

matrix* create_matrix(mg_arena* arena, uint32_t rows, uint32_t cols) {
    matrix* mat = 
}
void clear_matrix(matrix* matrix);
void copy_matrix(matrix* destination, matrix* source);
void fill_matrix(matrix* matrix, float x);
void scale_matrix(matrix* matrix, float const);

int32_t matrix_add(matrix* out, const matrix* a, const matrix* b);
int32_t matrix_subtract(matrix* out, const matrix* a, const matrix* b);
int32_t matrix_multiply(matrix* out, const matrix* a, matrix* b, int8_t zero_out, int8_t transpose_a, int8_t transpose_b);
int32_t matrix_relu(matrix* out, const matrix* in);
int32_t matrix_softmax(matrix* out, const matrix* in);

// cost (loss) function
int32_t matrix_cross_entropy(matrix* out, const matrix* p, const matrix* q);
int32_t matrix_relu_add_graident(matrix* out, const matrix* in);
int32_t matrix_softmax_add_gradient(matrix* out, const matrix* softmax_out);
int32_t matrix_cross_entropy_add_gradeint(matrix* out, const matrix* p, const matrix* q);




int main(void) {
    printf("hello world\n");


    return 0;
}

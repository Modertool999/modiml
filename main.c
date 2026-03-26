#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    size_t rows;
    size_t cols;
    float* data;   // pointer to rows*cols floats
} matrix;

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

/* Allocates a (rows, cols) matrix on the heap, returning a pointer to the matrix
* Returns NULL if
 * - rows or cols is 0
 * - rows * cols would overflow
 * - malloc/calloc fails
*
* data is a contiguous 1D array of rows * cols floats, zero-initialized by calloc.
* Caller must free the returned matrix with free_matrix()
*/
matrix* create_matrix(size_t rows, size_t cols) {
    if ((rows == 0 || cols == 0) || (rows > SIZE_MAX / cols)) return NULL;

    size_t count = rows * cols;

    matrix* m = malloc(sizeof(matrix));
    if (m == NULL) return NULL;

    m->rows = rows;
    m->cols = cols;
    m->data = calloc(count, sizeof(float));

    if (m->data == NULL) {
        free(m);
        return NULL;
    }

    return m;
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

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
*
* Requires: rows * cols to not overflow
* Caller must free the returned matrix with free_matrix()
* 
* Returns: pointer to created matrix on success, NULL on failure
*
* note: data of returned matrix is a contiguous 1D array of rows * cols floats, zero-initialized by calloc
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


/* Frees the matrix data and the matrix struct itself
 * Does nothing if matrix is NULL
 */
void free_matrix(matrix* matrix) {
    if (matrix == NULL) return;

    free(matrix->data);
    free(matrix);

}

/* Copies all entries from source matrix into destination matrix
 *
 * Requires: both matrices have the same rows and cols values and were created with create_matrix()
 * 
 * Returns: 0 on success, -1 if either matrix is NULL or if their dimensions do not match
 */
int copy_matrix(matrix* destination, const matrix* source) {
    if (destination == NULL || source == NULL) return -1;
    if (destination->rows != source->rows || destination->cols != source->cols) return -1;
        
    // overflow pretected from defensive programming and calloc in create_matrix()
    memcpy(destination->data, source->data, destination->rows * destination->cols * sizeof(float));

    return 0;
}

/* Sets every entry in the matrix to x
 * Does nothing if matrix or matrix->data is NULL
 */
void fill_matrix(matrix* matrix, float x) {
    if (matrix == NULL || matrix->data == NULL) return;

    size_t count = matrix->rows * matrix->cols;
    for (size_t i = 0; i < count; i++) {
        matrix->data[i] = x;
    }
}


/* Multiplies every entry in the matrix by x.
 * Does nothing if matrix or matrix->data is NULL.
 */
void scale_matrix(matrix* matrix, float x) {
    if (matrix == NULL || matrix->data == NULL) return;

    size_t count = matrix->rows * matrix->cols;
    for (size_t i = 0; i < count; i++) {
        matrix->data[i] *= x;
    }
}


int32_t matrix_add(matrix* out, const matrix* a, const matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) return -1;
    if (out->rows != a->rows || out->cols != a->cols) return -1;

    size_t size = out->rows * out->cols;
    for (size_t i = 0; i < size; i++) {
        out->data[i] *= a->data[i] + b->data[i];
    }

    return 0;

}


int32_t matrix_subtract(matrix* out, const matrix* a, const matrix* b) {
     if (a->rows != b->rows || a->cols != b->cols) return -1;
    if (out->rows != a->rows || out->cols != a->cols) return -1;

    size_t size = out->rows * out->cols;
    for (size_t i = 0; i < size; i++) {
        out->data[i] *= a->data[i] - b->data[i];
    }

    return 0;

}




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

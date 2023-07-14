#ifndef _3D_VIEWER_H_
#define _3D_VIEWER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { OK, NO_SUCH_FILE } Errors;

#define BUFF_SIZE 1000

typedef struct {
  int numbersF;
  int numbersV;

  double* vertices;
  double* initialVertices;
  int numbersOfVertices;

  int* lines;
  int numbersOfLines;
} dataModel;

void affineTransformation(dataModel* model, double scale, double translation[],
                          double rotation[]);
void readOBJ(const char* fileName, dataModel* model);
int getNumbers(const char* fileName, dataModel* model);
void freeData(dataModel* model);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // _3D_VIEWER_H_

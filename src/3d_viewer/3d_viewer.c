#include "3d_viewer.h"

void affineTransformation(dataModel* model, double scale, double translation[],
                          double rotation[]) {
  for (int i = 0; i < model->numbersOfVertices; i++) {
    model->vertices[i] = model->initialVertices[i];
  }
  // rotation X
  for (int i = 0; i < model->numbersOfVertices; i += 3) {
    double tempY = model->vertices[i + 1];
    double tempZ = model->vertices[i + 2];
    model->vertices[i + 1] =
        cos(rotation[0]) * tempY + sin(rotation[0]) * tempZ;
    model->vertices[i + 2] =
        -sin(rotation[0]) * tempY + cos(rotation[0]) * tempZ;
  }
  // rotation Y
  for (int i = 0; i < model->numbersOfVertices; i += 3) {
    double tempX = model->vertices[i];
    double tempZ = model->vertices[i + 2];
    model->vertices[i] = cos(rotation[1]) * tempX + sin(rotation[1]) * tempZ;
    model->vertices[i + 2] =
        -sin(rotation[1]) * tempX + cos(rotation[1]) * tempZ;
  }
  // rotation Z
  for (int i = 0; i < model->numbersOfVertices; i += 3) {
    double tempX = model->vertices[i];
    double tempY = model->vertices[i + 1];
    model->vertices[i] = cos(rotation[2]) * tempX + sin(rotation[2]) * tempY;
    model->vertices[i + 1] =
        -sin(rotation[2]) * tempX + cos(rotation[2]) * tempY;
  }

  for (int i = 0; i < model->numbersOfVertices; i++) {
    // translation
    model->vertices[i] += translation[i % 3];
    // scaling
    model->vertices[i] *= scale;
  }
}

int getNumbers(const char* fileName, dataModel* model) {
  int error = OK;
  char buffer[BUFF_SIZE];
  int nV = 0, nF = 0, nL = 0;
  FILE* file = fopen(fileName, "r");
  if (file != NULL) {
    while (fgets(buffer, BUFF_SIZE, file) != NULL) {
      if (!strncmp(buffer, "v ", 2)) {
        nV++;
      } else if (!strncmp(buffer, "f ", 2)) {
        nF++;
        char* buf = strtok(buffer, "f ");
        while (buf != NULL && atoi(buf) > 0) {
          buf = strtok(NULL, " ");
          nL++;
        }
      }
    }
    fclose(file);
  } else {
    error = NO_SUCH_FILE;
  }
  model->numbersV = nV;
  model->numbersF = nF;
  model->numbersOfLines = 2 * nL;
  model->numbersOfVertices = 3 * model->numbersV;
  return error;
}

void readOBJ(const char* fileName, dataModel* model) {
  model->vertices = (double*)calloc(model->numbersOfVertices, sizeof(double));
  model->initialVertices =
      (double*)calloc(model->numbersOfVertices, sizeof(double));
  model->lines = (int*)calloc(model->numbersOfLines, sizeof(int));

  char buffer[BUFF_SIZE];
  FILE* file = fopen(fileName, "r");
  if (file != NULL) {
    int i = 0, j = 0;
    while (fgets(buffer, BUFF_SIZE, file) != NULL) {
      if (!strncmp(buffer, "v ", 2)) {
        sscanf(buffer, "v %lf %lf %lf", &model->initialVertices[i],
               &model->initialVertices[i + 1], &model->initialVertices[i + 2]);
        i += 3;
      } else if (!strncmp(buffer, "f ", 2)) {
        char* buf = strtok(buffer, "f ");
        int firstNum = atoi(buf), num = 1;
        buf = strtok(NULL, " ");
        model->lines[j++] = firstNum - 1;
        while (buf != NULL && (num = atoi(buf)) > 0) {
          buf = strtok(NULL, " ");
          model->lines[j++] = num - 1;
          model->lines[j++] = num - 1;
        }
        model->lines[j] = firstNum - 1;
        if (j + 1 < model->numbersOfLines) {
          j++;
        }
      }
    }
    fclose(file);
  }
}

void freeData(dataModel* model) {
  free(model->vertices);
  free(model->initialVertices);
  free(model->lines);
  model->numbersV = 0;
  model->numbersF = 0;
  model->numbersOfVertices = 0;
  model->numbersOfLines = 0;
}
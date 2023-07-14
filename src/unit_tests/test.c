#include <check.h>

#include "../3d_viewer/3d_viewer.h"

START_TEST(test_modelLoading_1) {
  dataModel model;
  const char *buffer = "unit_tests/cube.obj";
  ck_assert_int_eq(OK, getNumbers(buffer, &model));
}
END_TEST

START_TEST(test_modelLoading_2) {
  dataModel model;
  const char *buffer = "unit_tests/no_such_file.obj";
  ck_assert_int_eq(NO_SUCH_FILE, getNumbers(buffer, &model));
}
END_TEST

START_TEST(test_modelLoading_3) {
  dataModel model;
  const char *buffer = "unit_tests/cube.obj";
  ck_assert_int_eq(OK, getNumbers(buffer, &model));
  ck_assert_int_eq(8, model.numbersV);
  ck_assert_int_eq(24, model.numbersOfVertices);
}
END_TEST

START_TEST(test_modelLoading_4) {
  dataModel model;
  const char *buffer = "unit_tests/cube.obj";
  ck_assert_int_eq(OK, getNumbers(buffer, &model));
  ck_assert_int_eq(6, model.numbersF);
  ck_assert_int_eq(48, model.numbersOfLines);
}
END_TEST

START_TEST(test_modelLoading_5) {
  dataModel model;
  const char *buffer = "unit_tests/cube.obj";
  ck_assert_int_eq(OK, getNumbers(buffer, &model));
  ck_assert_int_eq(8, model.numbersOfVertices / 3);
  ck_assert_int_eq(24, model.numbersOfLines / 2);
  readOBJ(buffer, &model);
  double resultV[24] = {1.000000,  1.000000,  -1.000000, 1.000000,  -1.000000,
                        -1.000000, 1.000000,  1.000000,  1.000000,  1.000000,
                        -1.000000, 1.000000,  -1.000000, 1.000000,  -1.000000,
                        -1.000000, -1.000000, -1.000000, -1.000000, 1.000000,
                        1.000000,  -1.000000, -1.000000, 1.000000};
  for (int i = 0; i < model.numbersOfVertices; i++) {
    ck_assert_double_eq(resultV[i], model.initialVertices[i]);
  }
  double resultL[48] = {0, 4, 4, 6, 6, 2, 2, 0, 3, 2, 2, 6, 6, 7, 7, 3,
                        7, 6, 6, 4, 4, 5, 5, 7, 5, 1, 1, 3, 3, 7, 7, 5,
                        1, 0, 0, 2, 2, 3, 3, 1, 5, 4, 4, 0, 0, 1, 1, 5};
  for (int i = 0; i < model.numbersOfLines; i++) {
    ck_assert_int_eq(resultL[i], model.lines[i]);
  }
  freeData(&model);
}
END_TEST

Suite *modelLoading(void) {
  Suite *s = suite_create("\033[0;1;36m3D Viewer v1.0: Model loading\033[0m");
  TCase *tc = tcase_create("viewer");
  tcase_add_test(tc, test_modelLoading_1);
  tcase_add_test(tc, test_modelLoading_2);
  tcase_add_test(tc, test_modelLoading_3);
  tcase_add_test(tc, test_modelLoading_4);
  tcase_add_test(tc, test_modelLoading_5);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(test_affineTransformation_1) {
  dataModel model;
  const char *buffer = "unit_tests/cube.obj";
  getNumbers(buffer, &model);
  readOBJ(buffer, &model);
  double rotation[3] = {10, 20, 30};
  double translation[3] = {1, 2, 3};
  double scale = 2;
  affineTransformation(&model, scale, translation, rotation);
  double result[24] = {3.098476,  7.210523, 5.302940, -0.524084, 5.765366,
                       4.414919,  4.775873, 3.847426, 3.933300,  1.153313,
                       2.402269,  3.045279, 2.846687, 5.597731,  8.954721,
                       -0.775873, 4.152574, 8.066700, 4.524084,  2.234634,
                       7.585081,  0.901524, 0.789477, 6.697060};
  for (int i = 0; i < model.numbersOfVertices; i++) {
    int resultEq = (fabs(model.vertices[i] - result[i]) < 1e-6 ? 1 : 0);
    ck_assert_int_eq(1, resultEq);
  }
  freeData(&model);
}
END_TEST

START_TEST(test_affineTransformation_2) {
  dataModel model;
  const char *buffer = "unit_tests/cube.obj";
  getNumbers(buffer, &model);
  readOBJ(buffer, &model);
  double rotation[3] = {0, 0, 0};
  double translation[3] = {0, 0, 0};
  double scale = 1;
  affineTransformation(&model, scale, translation, rotation);
  double result[24] = {1.000000,  1.000000,  -1.000000, 1.000000,  -1.000000,
                       -1.000000, 1.000000,  1.000000,  1.000000,  1.000000,
                       -1.000000, 1.000000,  -1.000000, 1.000000,  -1.000000,
                       -1.000000, -1.000000, -1.000000, -1.000000, 1.000000,
                       1.000000,  -1.000000, -1.000000, 1.000000};
  for (int i = 0; i < model.numbersOfVertices; i++) {
    int resultEq = (fabs(model.vertices[i] - result[i]) < 1e-6 ? 1 : 0);
    ck_assert_int_eq(1, resultEq);
  }
  freeData(&model);
}
END_TEST

Suite *affineTransform(void) {
  Suite *s =
      suite_create("\033[0;1;36m3D Viewer v1.0: Affine trasformation\033[0m");
  TCase *tc = tcase_create("viewer");
  tcase_add_test(tc, test_affineTransformation_1);
  tcase_add_test(tc, test_affineTransformation_2);
  suite_add_tcase(s, tc);
  return s;
}

int main() {
  int failed = 0;
  Suite *suites_list[] = {modelLoading(), affineTransform(), NULL};
  for (int i = 0; suites_list[i] != NULL; i++) {
    SRunner *sr = srunner_create(suites_list[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    printf("\n");
  }
  printf("\033[0;1;31mFAILED: %d\033[0m\n", failed);
  return failed == 0 ? 0 : 1;
}

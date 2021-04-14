#ifndef GTESTLEARN_FUNC_H
#define GTESTLEARN_FUNC_H

struct test_t {
    int a;
    int b;
    int (*p_func)(struct test_t *test);
};

int add(int a, int b);
int multi(int a, int b);
int add_struct(struct test_t *test);
int test_struct_func(struct test_t *test);
int test_stub_func();

#endif //GTESTLEARN_FUNC_H
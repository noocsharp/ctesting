#include <string.h>
#include <stdio.h>
#include <stdint.h>

char test[100];
char subtest[100];
int t_failed = 0;
int t_total = 0;
int s_failed = 0;
int s_total = 0;

int has_failed = 0;

int start_test(char* name) {
    strcpy(test, name);
    s_failed = 0;
    s_total = 0;
    printf("=== STARTING TEST %s ===\n", test);
}

int end_test() {
    printf("=== %d/%d SUBTESTS SUCCEEDED ===\n", s_total - s_failed, s_total);
    printf("=== ENDED TEST %s\n", test);
    if (s_failed > 0) ++t_failed;
    ++t_total;
}

void get_test_status() {
    printf("=== %d/%d TESTS PASSED ===", t_total - t_failed, t_total);
}

void start_subtest(char* name) {
    strcpy(subtest, name);
}

void end_subtest() {
    if (has_failed == 0) {
        printf("SUBTEST %s SUCCEEDED\n", subtest);
    } else { 
        printf("SUBTEST %s FAILED\n", subtest);
        s_failed += 1;
    }
    s_total += 1;
}

void assert_true(int b) {
    if (b == 0) {
        has_failed += 1;
    }
}

void assert_false(int b) {
    if (b != 0) {
        has_failed += 1;
    }
}

void assert_equals(void* to_check, void* source, int bytes) {
    for (int i = 0; i < bytes; i++) {
        if (*(uint8_t *) (to_check + i) != *(uint8_t*)(source + i)) {
            has_failed += 1;
        }
    }
}

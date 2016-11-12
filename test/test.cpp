#include <stdio.h>
#include "smprintf.h"

int main() {
    char buf[100];
    smprintf(buf, sizeof(buf), "%d %ld", '1', 2);
    return 0;
}

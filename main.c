#include "read.h"
#include "write.h"
#include "process.h"
#include "order.h"

#include <stdio.h>


int main(int argc, char *argv[]) {
    int n = readFiles(argv[1], argv[2]);
    printf("%d\n", n);
    return 0;
}
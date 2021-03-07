#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "list.h"

static bool list_is_ordered(node_t *list)
{
    bool first = true;
    int value;
    while (list) {
        if (first) {
            value = list->value;
            first = false;
        } else {
            if (list->value < value)
                return false;
            value = list->value;
        }
        list = list->next;
    }
    return true;
}

static void list_display(node_t *list)
{
    printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

long long current_timestamp()
{
    struct timeval tv;
    // get current time
    gettimeofday(&tv, NULL);
    // calculate microseconds
    long long microseconds = tv.tv_sec * 1000000 + tv.tv_usec;
    return microseconds;
}

int main(int argc, char **argv)
{
    size_t count = 20;
    node_t *list = NULL;
    srand(current_timestamp());
    while (count--)
        list = list_make_node_t(list, rand() % 1024);

    list_display(list);
    quicksort(&list);
    list_display(list);

    if (!list_is_ordered(list))
        return EXIT_FAILURE;

    list_free(&list);
    return EXIT_SUCCESS;
}
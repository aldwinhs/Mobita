#include <stdio.h>
#include "../to_do_list.h"

int main() {
    Tas s;
    Queue q;
    int wktSkrg = 5;

    CreateTas(&s);
    CreateQueue(&q);

    item a = {'A', 'B', 'H', 1, -1, 100, false, false};
    item b = {'B', 'C', 'N', 10, -1, 200, false, false};
    item c = {'D', 'G', 'P', 5, 20, 400, false, false};
    addToTas(&s, a);
    addToTas(&s, b);
    addToTas(&s, c);
    enqueue(&q, a);
    enqueue(&q, b);
    enqueue(&q, c);

    displayInProgr(s);
    displayToDo(q, wktSkrg);
}
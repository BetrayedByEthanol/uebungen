#include <stdio.h>
#include <time.h>

int time_h=0, morning_t=0, evening_t=0;

int sleep(int i) {
    int t = clock(), t2 = t;
    while (t2 - t < i * 1000) t2 = clock();
}

int run_time() {
    if (time_h < 23) time_h++;
    else time_h = 0;
    return 1;
}

int main() {
    puts("Wann soll die Jalousie morgens hochfahren bzw. abends runterfahren?\n(Stunde Stunde)");
    scanf("%i %i", &morning_t, &evening_t);
    while (1) {
        run_time();
        printf("%i:00\n", time_h);
        if (time_h == morning_t) puts("Jalousie fährt hoch!");
        if (time_h == evening_t) puts("Jalousie fährt runter!");
        sleep(1);
    }
    return 1;
}
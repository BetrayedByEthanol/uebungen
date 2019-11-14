#include <stdio.h>
#include <time.h>

int time_h=0, morning_t=0, evening_t=0, sun=0, strahlung=3, ja=0;

int sleep(float i) {
    int t = clock(), t2 = t;
    while (t2 - t < i * 1000) t2 = clock();
}

int run_time(int h) {
    if (h < 23) h++;
    else h = 0;
    return h;
}

int check_strahlung() {
    if (time_h > morning_t && time_h < evening_t) {
        int rnum = rand() % 2;
        if (rnum == 0) strahlung--;
        else strahlung++;
        if (strahlung >= 5 && ja == 0) {
            printf("Sonne strahlt. Jalousie wird auf %i%% gefahren!\n", sun);
            ja = 1;
        }
        else if (strahlung < 5 && ja == 1) {
            printf("Sonne strahltnicht mehr. Jalousie wird hochgefahren!\n");
            ja = 0;
        }
    }
    else {
        ja = 0;
        strahlung = 3;
    }
    return 1;
}

int main() {
    puts("Wann soll die Jalousie morgens hochfahren bzw. abends runterfahren?\n(Stunde Stunde)");
    scanf("%i %i", &morning_t, &evening_t);
    puts("Wie weit soll die Jalousie runterfahren wenn die Sonne strahlt?\n(0-100)");
    scanf("%i", &sun);
    while (1) {
        time_h = run_time(time_h);
        printf("%i:00\n", time_h);
        if (time_h == morning_t) puts("Jalousie fährt hoch!");
        if (time_h == evening_t) puts("Jalousie fährt runter!");
        check_strahlung();
        sleep(1);
    }
    return 1;
}
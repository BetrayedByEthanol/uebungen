#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    printf("Enter Time: ");

    int hours, minutes;
    scanf("%2d:%2d", &hours, &minutes);
    printf("\n");
    // printf("hours: %d minutes: %d\n", hours, minutes);
    if(hours < 0 || hours > 24) {
        printf("incorrect hour value: %d\n", hours);
        return 1;
    }
    if(minutes < 0 || minutes > 60) {
        printf("incorrect minute value: %d\n", minutes);
        return 1;
    }

    int timeInMinutes = (hours * 60 + minutes) % (60 * 12);
    // printf("timeInMinutes: %d\n", timeInMinutes);

    int angleHours = timeInMinutes * 360 / (60*12);
    int angleMinute = minutes * 360 / 60;

    // printf("angle hour: %d minute: %d\n", angleHours, angleMinute);

    int diff1 = angleHours - angleMinute;
    if(diff1 < 0) diff1 += 360;
    int diff2 = angleMinute - angleHours;
    if(diff2 < 0) diff2 += 360;
    int angleDiffMin = min(diff1, diff2);
    int angleDiffMax = max(diff1, diff2);
    printf("angle: %d %d", angleDiffMin, angleDiffMax);

    return 0;
}
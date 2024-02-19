//-----------------------------------------------------------------------------
//	Love-Divine Onwulata	Spring 2024
//
//	Code to simulate the action and process of a Process Scheduler
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define topLeft 201
#define topRight 187
#define bottomLeft 200
#define bottomRight 188
#define whitespace 32
#define horizontal 205
#define vertical 186
#define leftConnector 204
#define rightConnector 185
#define maxHorizontal 63
#define maxVertical 28

struct Process{
    int duration;
    int priority;
    char processName;
};
struct Queue{
    int length;
    struct Process queue[10];
};
const struct Process A = {10, 2, 'A'};
const struct Process B = {8, 4, 'B'};
const struct Process C = {14, 3, 'C'};
const struct Process D = {13, 5, 'D'};
void gotoxy(short x, short y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void durationInsertToQueue(struct Queue *processQueue, struct Process process){
    //puts the process in the order that is the shortest

    if(processQueue->length > 0 && processQueue->length < 10) {

        int index = 1;
        while ((index < processQueue->length) && (process.duration > processQueue->queue[index].duration)) {
            index++;
        }
        processQueue->length++;
        char tempProcess;
        switch(process.processName){
            case 'A':
                tempProcess = 'A';
                break;
            case 'B':
                tempProcess = 'B';
                break;
            case 'C':
                tempProcess = 'C';
                break;
            case 'D':
                tempProcess = 'D';
                break;
            default:
                break;
        }
        for(int x = index; x < processQueue->length-1; x++){
            char holder;
            switch(processQueue->queue[x].processName){
                case 'A':
                    holder = 'A';
                    break;
                case 'B':
                    holder = 'B';
                    break;
                case 'C':
                    holder = 'C';
                    break;
                case 'D':
                    holder = 'D';
                    break;
                default:
                    break;
            }
            switch(tempProcess){
                case 'A':
                    processQueue->queue[x] = A;
                    break;
                case 'B':
                    processQueue->queue[x] = B;
                    break;
                case 'C':
                    processQueue->queue[x] = C;
                    break;
                case 'D':
                    processQueue->queue[x] = D;
                    break;
                default:
                    break;
            }
            tempProcess = holder;
        }
        switch(tempProcess){
            case 'A':
                processQueue->queue[processQueue->length-1] = A;
                break;
            case 'B':
                processQueue->queue[processQueue->length-1] = B;
                break;
            case 'C':
                processQueue->queue[processQueue->length-1] = C;
                break;
            case 'D':
                processQueue->queue[processQueue->length-1] = D;
                break;
            default:
                break;
        }
    }else if(processQueue->length == 0){
        processQueue->length++;
        processQueue->queue[0] = process;
    }
    //gotoxy(0, 23);
    //printf("%c", process.processName);

}
void priorityInsertToQueue(struct Queue *processQueue, struct Process process){
    //puts the process in the order that is the shortest

    if(processQueue->length > 0 && processQueue->length < 10) {

        int index = 1;
        while ((index < processQueue->length) && (process.priority > processQueue->queue[index].priority)) {
            index++;
        }
        processQueue->length++;
        char tempProcess;
        switch(process.processName){
            case 'A':
                tempProcess = 'A';
                break;
            case 'B':
                tempProcess = 'B';
                break;
            case 'C':
                tempProcess = 'C';
                break;
            case 'D':
                tempProcess = 'D';
                break;
            default:
                break;
        }
        for(int x = index; x < processQueue->length-1; x++){
            char holder;
            switch(processQueue->queue[x].processName){
                case 'A':
                    holder = 'A';
                    break;
                case 'B':
                    holder = 'B';
                    break;
                case 'C':
                    holder = 'C';
                    break;
                case 'D':
                    holder = 'D';
                    break;
                default:
                    break;
            }
            switch(tempProcess){
                case 'A':
                    processQueue->queue[x] = A;
                    break;
                case 'B':
                    processQueue->queue[x] = B;
                    break;
                case 'C':
                    processQueue->queue[x] = C;
                    break;
                case 'D':
                    processQueue->queue[x] = D;
                    break;
                default:
                    break;
            }
            tempProcess = holder;
        }
        switch(tempProcess){
            case 'A':
                processQueue->queue[processQueue->length-1] = A;
                break;
            case 'B':
                processQueue->queue[processQueue->length-1] = B;
                break;
            case 'C':
                processQueue->queue[processQueue->length-1] = C;
                break;
            case 'D':
                processQueue->queue[processQueue->length-1] = D;
                break;
            default:
                break;
        }
    }else if(processQueue->length == 0){
        processQueue->length++;
        processQueue->queue[0] = process;
    }
}
struct Process popQueue(struct Queue *processQueue){
    if(processQueue->length > 0){
        processQueue->length--;
        struct Process poppedProcess = processQueue->queue[0];
        for(int x = 0; x < processQueue->length; x++){
            processQueue->queue[x] =  processQueue->queue[x+1];
        }
        return poppedProcess;
    }else{
        struct Process error = {-1};
        return error;
    }
}

void promptParams(int* x, int* y, int* rows, int* cols){
    printf("Enter Starting X Point: ");
    scanf("%d", x);
    system("cls");
    printf("Enter Starting Y Point: ");
    scanf("%d", y);
    system("cls");
    printf("Enter Number of Rows: ");
    scanf("%d", rows);
    system("cls");
    printf("Enter Number of Columns: ");
    scanf("%d", cols);
    system("cls");
}
void printRow(int length, short x, short y, int leftChar, int rightChar, int filler, bool hasFiller){
    //buffer
    /*
    for(int b = 0; b < bufferNum; b++){
        printf("%c", whitespace);
    }*/
    //first row
    gotoxy(x, y);
    printf("%c", leftChar);
    if(hasFiller){
        for(int c = 0; c < length; c++){
            gotoxy(x+c+1, y);
            printf("%c", filler);
        }
    }

    gotoxy(x+length, y);
    printf("%c", rightChar);
    printf("\n");
}
bool makeBox(int x, int y, int rows, int cols){
    bool canMake = false;
    if(x >= 0 && y >= 0 && x+cols < maxHorizontal-2 && (y+((2*rows)-1)) <= maxVertical-2){
        for(int b = 0; b < y; b++){
            printf("\n");
        }
        //top row
        printRow(cols, x, y, topLeft, topRight, horizontal, true);
        //rows
        for(int r = 0; r < rows-1; r++){
            printRow(cols, x, y+((2*r)+1), vertical, vertical, whitespace, true);
            printRow(cols, x, y+((2*r)+2), leftConnector, rightConnector, horizontal, true);
            //getchar();
        }

        //lastrow
        printRow(cols, x, y+((2*rows)-1), vertical, vertical, whitespace, true);
        printRow(cols, x, y+(2*rows),bottomLeft, bottomRight, horizontal, true);
        //getchar();

        canMake = true;
    }
    return canMake;
}
void populateBoxes(int x, int y, int rows, int cols, int sideColDist, int timeLeft, struct Queue processQueue, bool usingPriority ){

    for(int r = 0; r < processQueue.length; r++){
        gotoxy((x+(int)(cols/2)), (y+(2*r)+1));
        printf("%c", processQueue.queue[r].processName);

        int info;
        if(usingPriority){
            info = processQueue.queue[r].priority;
            gotoxy((x+(int)(cols/2))+sideColDist+1+4+3, (y+(2*r)+1));
            printf("%d", info);
        }else{
            info = processQueue.queue[r].duration;
            gotoxy((x+(int)(cols/2))+sideColDist+1+4, (y+(2*r)+1));
            printf("%d secs", info);
        }
        if(r == 0){
            gotoxy((x+(int)(cols/2))+(sideColDist*2)+1+4+8+1, (y+(2*r)+1));
            printf("%c", processQueue.queue[r].processName);
        }

    }
}
void clearBoxes(int x, int y, int rows, int cols){

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols-1; c++){
            gotoxy((x+1+c), (y+(2*r)+1));
            printf("%c", whitespace);
        }
    }
}
void runScheduler(struct Queue *processQueue, bool usingPriority)
{
    float seconds;
    int c1 = 0, c2, cntr = 0;
    clock_t t1 = 0, t2 = 0, processCounter = 0;
    bool timeElapsed = false;

    //-- Function gets # of MS since the program started.
    t1 = clock();
    clock_t timerToPass = 10000; // Milliseconds I want to delay.
    bool inProcess = false;
    struct Process currentProcess;
    //printf ("\nGoing to delay for [%.2f] seconds.\n\n", (float)timerToPass/1000);

    //-- This while loop demo's how to "delay" and still be able to execute code.
    while ((!timeElapsed) && (c1 != 27))
    {
        //-- All of this code inside the WHILE loop is executed
        //-- as long as the time has not elapsed.

        /*
         * check if something is being worked on
         * if yes check to see if time is up for that process
         * if not check if something is in queue;
         * if yes start working on next item
         * */



        if(inProcess){
            t2 = clock();
            gotoxy(40, 20);
            printf("%d secs ",(currentProcess.duration*1000 - (t2-processCounter))/1000);
            //printf("%d",((t2-processCounter) > (currentProcess.duration*1000)));
            if((t2-processCounter) > currentProcess.duration*1000){

                //stop process
                inProcess = false;
                //pop queue
                popQueue(processQueue);
                //redraw!!!!!
                clearBoxes(20,5,10,7);
                clearBoxes(28,5,10,8);
                clearBoxes(37,5,1,5);
                populateBoxes(20, 5, 10, 7, 1, 12, *processQueue, usingPriority);
                //printf("HI");
                //getchar();
                //gotoxy(0,0);
                //printf("%d",processQueue->length);
                //getchar();
            }else{
                //code for timer if needed
            }
        }else{
            //not currently in a process
            if(processQueue->length > 0){ //if more in queue -> requeue up

                inProcess = true;
                timerToPass += processQueue->queue[0].duration*1000;
                currentProcess = processQueue->queue[0];
                //populateBoxes(20, 5, 10, 7, 1, 12, *processQueue, false);
                processCounter = clock();
            }
        }
        if (_kbhit()){			// was a key hit?{
            cntr = 0;
            c1 = _getch();		// get the key code.
            c2 = 0;
            if (c1 == 0){		// get the secondary key code.
                c2 = _getch();

            }

            if(c1 == 27){
                timeElapsed = true;
            }
            switch (c1) {
                case 41:
                case 97: //A
                    if(usingPriority){
                        priorityInsertToQueue(processQueue, A);
                    }else{
                        durationInsertToQueue(processQueue, A);
                    }
                    populateBoxes(20, 5, 10, 7, 1, 12, *processQueue, usingPriority);
                    break;
                case 42:
                case 98: //B
                    if(usingPriority){
                        priorityInsertToQueue(processQueue, B);
                    }else{
                        durationInsertToQueue(processQueue, B);
                    }
                    populateBoxes(20, 5, 10, 7, 1, 12, *processQueue, usingPriority);
                    break;
                case 43:
                case 99: //C
                    if(usingPriority){
                        priorityInsertToQueue(processQueue, C);
                    }else{
                        durationInsertToQueue(processQueue, C);
                    }
                    populateBoxes(20, 5, 10, 7, 1, 12, *processQueue, usingPriority);
                    break;
                case 44:
                case 100: //D
                    if(usingPriority){
                        priorityInsertToQueue(processQueue, D);
                    }else{
                        durationInsertToQueue(processQueue, D);
                    }
                    populateBoxes(20, 5, 10, 7, 1, 12, *processQueue, usingPriority);
                    break;

                default:
                    break;
            }

            /*
             * A - 41   a - 97
             * B - 42   b - 98
             * C - 43   c - 99
             * D - 44   d - 100
             * */
        }else{
            cntr++;
            if ((cntr % 8000) == 0)	{	// this is to slow down num of lines of data being displayed.

                cntr = 0;
                t2 = clock();
                float countdown = (timerToPass/1000.0)-((t2-t1)/1000.0);
                //seconds = (t2 - t1) / 1000.0;
                //printf ("[%.2f] seconds remaining\n", countdown);

            }
        }

        t2 = clock();
        if(!timeElapsed){
            timeElapsed = (t2 > (t1 + timerToPass));
        }

    }

    //getchar();
}
int main() {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 480, 500, TRUE);
    /*
    int x, y, rows, cols;
    promptParams(&x,&y,&rows, &cols);
    if(!makeBox(x,y,rows,cols)){
        printf("Invalid Box");
    }
     */
    int yPos = 5;
    ///*


    struct Queue processQueue = {0,{}};
    //durationInsertToQueue(&processQueue, D);
    //durationInsertToQueue(&processQueue, A);
    //durationInsertToQueue(&processQueue, B);
    gotoxy(0,0);
    printf("Process Scheduler Commands\n");
    printf("'A' to run process A\n");
    printf("'B' to run process B\n");
    printf("'C' to run process C\n");
    printf("'D' to run process D\n");
    printf("'ESC' to quit\n\n\n");
    printf("Hit 'Enter' to Continue\n");
    getchar();
    system("cls");

    printf("Use a priority based scheduler? (y/n)\n");
    int response = getchar();
    system("cls");
    char type[10];
    bool usingPriority;
    if((char)response == 'y'){
        snprintf(type, sizeof(type), "Priority");
        usingPriority = true;
    }else{
        snprintf(type, sizeof(type), "SJF");
        usingPriority = false;
    }
    gotoxy(0,4);
    printf("%s Process Scheduler\n", type);
    makeBox(20,yPos,10,7);
    makeBox(28,yPos,10,8);
    makeBox(37,yPos,1,5);
    makeBox(39,19,1,9);
    runScheduler(&processQueue, usingPriority);

    //populateBoxes(20, yPos, 10, 7, 1, 12, processQueue, true);
    //clearBoxes(20,yPos, 10,7);

    //*/
    //printf("I'm Done!");



    //getchar();
    //getchar();
    return 0;
}

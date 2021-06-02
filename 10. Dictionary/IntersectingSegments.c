#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

typedef struct
{
    int num;  
    float s, e;   // 선분의 시작과 끝점
}Segment;

typedef struct 
{
    float coor;      // 좌표
    char code;       // 이벤트 코드(시작과 끝점)
    int id;          // 선분 ID
}Event;

// 교차선분 저장 공간 구조체로 따로 선언
typedef struct
{
    int id1, id2;
}interSegment;

// 좌표값 기준으로 정렬하기 (배열의 사이즈 갯수 n)
void insertion_sort(Event ev[], int n)
{
    int i,j;
    Event item;
    for (i=1; i<n; i++)
    {
        item = ev[i];
        for (j=i-1; j>=0 && ev[j].coor > item.coor; j--)
            ev[j+1] = ev[j];
        ev[j+1] = item;
    }
}

void findIntersectingSegment(Event ev[])
{
    int openSegments[SIZE];
    interSegment is[SIZE* 2];
    int oCnt = 0;           // OpenSegments 갯수 counting
    int iCnt = 0;           // InterSegments 갯수 counting

    for(int i=0; i<SIZE*2; i++)
    {
        if(ev[i].code == 'S')
        {
            for(int j=0; j<oCnt; j++)
                if(openSegments[j] != 0)
                {
                    is[iCnt].id1 = openSegments[j];
                    is[iCnt].id2 = ev[i].id;
                    iCnt++;
                    // count 를 증가하여 교차선분 배열의 증가된 index 에 
                    // 새로운 선분 ID 넣기 
                }
            // openSegments 에 아무것도 없다면
            // openSegments[0] 에 선분ID 집어넣고 count 1 증가
            openSegments[oCnt++] = ev[i].id;
        }
        else
        {
            // 'E' 일 때는 OpenSegments 에서 해당 선분 id 찾아서
            // 그 위치값을 0으로 해주기
            for(int j=0; j < oCnt; j++)
                if(openSegments[j] == ev[i].id)
                    openSegments[j] = 0;
        }
    }
    for (int i=0; i<iCnt; i++)
        printf("(%d, %d) ", is[i].id1, is[i].id2);
    printf("\n");
}

int main()
{
    Segment lines[] = { {1, 1.0, 3.2}, {2, 0.8, 3.0}, {3, 0.6, 2.8}, {4, 1.1, 2.0}, {5, 5.4, 7.0}, {6, 2.9, 5.0}};
    Event ev[SIZE * 2];

    // Line 출력
    for (int i=0; i < SIZE; i++)
        printf("%d. (%.1f ~ %.1f)\n", lines[i].num, lines[i].s, lines[i].e);
    printf("\n");
    getchar();

    for(int i=0, j=0; i<SIZE*2; i++, j++)
    {
        // Start Event
        ev[i].coor = lines[j].s;
        ev[i].code = 'S';
        ev[i].id = lines[j].num;
        // End Event
        ev[i+1].coor = lines[j].e;
        ev[i+1].code = 'E';
        ev[++i].id = lines[j].num;
    }

    // event 배열 출력
    for (int i=0; i < SIZE * 2; i++)
        printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
    printf("\n");
    getchar();

    insertion_sort(ev, SIZE*2);
    for(int i=0; i<SIZE*2; i++)
        printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
    printf("\n");

    findIntersectingSegment(ev);
}

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>
#include <time.h>
#include <cstring>

clock_t start, end;
double result = 0;


#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_SOLDIER 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_SOLDIER 6

#define MAX 100001

struct Soldier {
	int mID;
    int mTeam;
    int mScore;
    Soldier* next = nullptr;
    Soldier* prev = nullptr;
};

Soldier arrSol[MAX];
Soldier *head[6];
int notUpdate[MAX];
int flag[6];
int addCnt[6];

Soldier* getSoldier(int mID, int mTeam, int mScore) {
    arrSol[mID].mID = mID;
    arrSol[mID].mTeam = mTeam;
    arrSol[mID].mScore = mScore;
    arrSol[mID].next = nullptr;
    arrSol[mID].prev = nullptr;
    return &arrSol[mID];
}

void init()
{
    for(int i = 1; i <= 5; i++) {
        head[i] = new Soldier;
    }
    memset(notUpdate, 0, MAX);
    memset(flag, 0, 6);
    memset(addCnt, 0, 6);
}

void hire(int mID, int mTeam, int mScore)
{
    Soldier* sol = getSoldier(mID, mTeam, mScore);
    
    if(head[mTeam]->next) {
    	Soldier* prevHead = head[mTeam]->next;
        sol->next = prevHead;
        prevHead->prev = sol;
        head[mTeam]->next = sol;
    }
    else {
    	head[mTeam]->next = sol;
    }
    notUpdate[mID] = 1;
    addCnt[mTeam]++;
}

void fire(int mID)
{
    Soldier* prev = arrSol[mID].prev;
    Soldier* next = arrSol[mID].next;
    
    if(prev && next) {
    	prev->next = next;
    	next->prev = prev;
    }
    else if(prev || next){
    	if(next) {
        	next->prev = nullptr;
            head[next->mTeam]->next = next;
        }
        else if(prev) {
        	prev->next = nullptr;
        }
    }
    else {
    	head[arrSol[mID].mTeam]->next = nullptr;
    }

    if(notUpdate[mID] == 1) {
        notUpdate[mID] = 0;
        addCnt[arrSol[mID].mTeam]--;
    }
}

void updateSoldier(int mID, int mScore)
{
    arrSol[mID].mScore = mScore;
    notUpdate[mID] = 1;
}

void updateTeam(int mTeam, int mChangeScore)
{
    start = clock();
    
    int f = flag[mTeam];
    if(mChangeScore == 4 || mChangeScore == -4) flag[mTeam] = mChangeScore;
    else {
        if(mChangeScore != 0) {
            Soldier* cur = head[mTeam];
            if(f == 0) {
                while(cur->next) {
                    cur = cur->next;
                    if(cur->mScore + mChangeScore < 1) cur->mScore = 1;
                    else if(cur->mScore + mChangeScore > 5) cur->mScore = 5;
                    else cur->mScore += mChangeScore;
                }
            }
            else {
                while(cur->next) {
                    cur = cur->next;
                    if(notUpdate[cur->mID] == 1) {
                        if(cur->mScore + mChangeScore < 1) cur->mScore = 1;
                        else if(cur->mScore + mChangeScore > 5) cur->mScore = 5;
                        else cur->mScore += mChangeScore;
                    }
                    else {
                        if(f == 4) cur->mScore = 5;
                        else cur->mScore = 1;
                    }
                }
            }
        }
        flag[mTeam] = 0;
    }
    memset(notUpdate, 0, MAX);
    addCnt[mTeam] = 0;

    end = clock();
    result += (end - start);
}

int bestSoldier(int mTeam)
{
    int f = flag[mTeam];
    Soldier* cur = head[mTeam]->next;
    Soldier* best = cur;
    if(f == 4 || f == -4) {
        while(cur->next) {
            cur = cur->next;
            if(addCnt[mTeam] != 0) {
                if(cur->mScore >= best->mScore) {
                    best = cur->mScore == best->mScore ? (cur->mID > best->mID ? cur : best ) : cur;
                }
            }
            else    best = cur->mID > best->mID ? cur : best;
        }
    }
    else {
        while(cur->next) {
            cur = cur->next;
            if(cur->mScore >= best->mScore) {
                best = cur->mScore == best->mScore ? (cur->mID > best->mID ? cur : best ) : cur;
            }
        }
    }
    
    return best->mID;
}

void print() {
    for(int i = 1; i <= 5; i++) {
        printf("team[%d]\t%d\n", i, flag[i]);
        Soldier* cur = head[i];
        while(cur->next) {
            cur = cur->next;
            printf("ID : %d\tScore : %d\n", cur->mID, cur->mScore);
        }
        printf("\n");
    }
    printf("\n");
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
    int numQuery;

    int mID, mTeam, mScore, mChangeScore;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_HIRE:
            scanf("%d %d %d", &mID, &mTeam, &mScore);
            hire(mID, mTeam, mScore);
            break;
        case CMD_FIRE:
            scanf("%d", &mID);
            fire(mID);
            break;
        case CMD_UPDATE_SOLDIER:
            scanf("%d %d", &mID, &mScore);
            updateSoldier(mID, mScore);
            break;
        case CMD_UPDATE_TEAM:
            scanf("%d %d", &mTeam, &mChangeScore);
            updateTeam(mTeam, mChangeScore);
            break;
        case CMD_BEST_SOLDIER:
            scanf("%d", &mTeam);
            userAns = bestSoldier(mTeam);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("13072.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        result = 0;
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
        printf("time : %dms\n", (int)result);
    }

    return 0;
}
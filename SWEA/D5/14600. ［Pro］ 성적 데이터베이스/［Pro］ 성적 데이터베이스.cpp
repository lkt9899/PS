#define N_MAX 100000
#define T_MAX 5

static int nodeCnt;
struct Student
{
    int mID;
    int mTeam;
    Student *next, *prev;
} __student[N_MAX + 25];

static inline Student *alloc(int mID, int mTeam)
{
    __student[nodeCnt].mID = mID;
    __student[nodeCnt].mTeam = mTeam;
    __student[nodeCnt].next = &__student[nodeCnt];
    __student[nodeCnt].prev = &__student[nodeCnt];

    return &__student[nodeCnt++];
}

static inline Student *append(Student *head, Student *s)
{
    s->prev = head;
    s->next = head->next;
    s->next->prev = s;
    s->prev->next = s;

    return s;
}

static inline void remove(Student *s)
{
    s->next->prev = s->prev;
    s->prev->next = s->next;
}

static inline Student *get_tail(Student *head)
{
    return head->prev;
}

static inline int calcScore(int ori, int change)
{
    return ori += change, ori <= 5 ? ori >= 1 ? ori : 1 : 5;
}

Student *heads[T_MAX][T_MAX];
Student *members[N_MAX];

void init()
{
    nodeCnt = 0;
    for (int i = 0; i < T_MAX; i++)
    {
        for (int j = 0; j < T_MAX; j++)
        {
            heads[i][j] = alloc(0, 0);
        }
    }
}

void hire(int mID, int mTeam, int mScore)
{
    members[mID - 1] = append(heads[mTeam - 1][mScore - 1], alloc(mID, mTeam));
}

void fire(int mID)
{
    remove(members[mID - 1]);
}

void updateStudent(int mID, int mScore)
{
    remove(members[mID - 1]);
    append(heads[members[mID - 1]->mTeam - 1][mScore - 1], members[mID - 1]);
}

void updateTeam(int mTeam, int mChangeScore)
{
    if (mChangeScore > 0)
    {
        for (int ori = 5; ori >= 1; ori--)
        {
            int newScore = calcScore(ori, mChangeScore);
            if (newScore == ori)
                continue;

            Student *lcur = heads[mTeam - 1][ori - 1];
            Student *lnext = heads[mTeam - 1][newScore - 1];
            Student *ntail = get_tail(lnext);
            if (lcur->next != lcur)
            {
                ntail->next = lcur->next;
                lcur->next->prev = ntail;
                lnext->prev = lcur->prev;
                lcur->prev->next = lnext;
                lcur->prev = lcur;
                lcur->next = lcur;
            }
        }
    }

    else if (mChangeScore < 0)
    {
        for (int ori = 1; ori <= 5; ori++)
        {
            int newScore = calcScore(ori, mChangeScore);
            if (newScore == ori)
                continue;

            Student *lcur = heads[mTeam - 1][ori - 1];
            Student *lnext = heads[mTeam - 1][newScore - 1];
            Student *ntail = get_tail(lnext);

            if (lcur->next != lcur)
            {
                ntail->next = lcur->next;
                lcur->next->prev = ntail;
                lnext->prev = lcur->prev;
                lcur->prev->next = lnext;
                lcur->prev = lcur;
                lcur->next = lcur;
            }
        }
    }
}

int bestStudent(int mTeam)
{
    Student *it;
    int mID, mScore;
    int best = 0;
    for (mScore = 5; mScore >= 1 && !best; mScore--)
    {
        Student *head = heads[mTeam - 1][mScore - 1];
        for (it = head->next; it != head; it = it->next)
        {
            mID = it->mID;
            if (mID > best)
                best = mID;
        }
    }

    return best;
}
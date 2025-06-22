#define QUEUE_SIZE 5
int queue_table[QUEUE_SIZE] = { 0 };
int queue_back = 0;
int queue_front = 0;

int isQueueEmpty(void)
{
    return (queue_back == queue_front) ? 1 : 0;
}

int isQueueFull(void)
{
    return (queue_back == (QUEUE_SIZE)) ? 1 : 0;
}

int usun(void)
{
    if (!isQueueEmpty())
    {
        return queue_table[queue_front++];
    }

    return queue_table[0];
}

int pierwszy(void)
{
    if (!isQueueEmpty())
    {
        return queue_table[queue_front];
    }

    return queue_table[0];
}

void wstaw(int val)
{
    if (!isQueueFull())
    {
        queue_table[queue_back] = val;
        queue_back++;
    }
}
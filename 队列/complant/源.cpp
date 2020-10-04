#define MAXLEN 100
struct SeqQueue
{
	int front, rear;
	int data[MAXLEN];
};

void InitQueue(SeqQueue &q) {
	q.front = 0;
	q.rear = 0;
}

bool IsEmpty(SeqQueue &q) {
	return q.rear == q.front;
}

bool IsFull(SeqQueue &q) {
	return (q.rear+1)%MAXLEN == q.front ;
}

bool Push(SeqQueue &q, int dt) {
	if (IsFull(q)) return false;
	q.data[q.rear] = dt;
	q.rear = (q.rear + 1) % MAXLEN;
	return true;
}

bool Pop(SeqQueue &q) {
	if (IsEmpty(q)) return false;
	q.front = (q.front + 1) % MAXLEN;
	return true;
}

bool Getfront(SeqQueue &q, int dt) {
	if (IsEmpty(q)) return false;
	dt = q.data[q.front];
	return true;
}


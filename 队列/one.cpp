#define MAXLEN 1000
struct SeqQueue {
	int front, rear;
	int data[MAXLEN];
};

//��ʼ��
void InitQueue(Queue &q) {
	q.front = 0;
	q.rear = 0;
}

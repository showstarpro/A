void update(int arr[], int curr) {
	int maxIndex = curr;
	if (2 * curr<currSize && arr[2 * curr]>arr[maxIndex]) {
		maxIndex = 2 * curr;
	}
	if (2 * curr + 1 < cusrrSize && arr[2 * curr + 1] > arr[maxIndex]) {
		maxIndex = 2 * curr + 1;
	}
	if (maxIndex != curr) {
		swap(arr[curr], arr[maxIndex]);
		update(arr, maxIndex);
	}
	return;
}            //堆的维护


//查询并删除堆顶元素
int heapDelete(int arr[]) {
	int val = arr[1];
	arr[1] = arr[currSize--];
	update(arr, 1);
	return val;
}


//向堆中插入元素
void insert(int arr[], int val) {
	arr[++currSize] = val;
	int temp = currSize;
	while (temp > 1) {
		if (arr[temp] > arr[temp / 2]) {
			swap(arr[temp], arr[temp / 2]);
			temp = temp / 2;
		}
		else {
			break;
		}
	}
	return;
}


//建堆
void CreatHeap(int a[], int len) {
	int i, j, k, tmp;
	for (i = len / 2; i > 0; i--) {
		tmp = a[i];
		k = i;
		for (j = i * 2; j <= len; j = j * 2) {
			if (j < len && a[j] < a[j + 1]) {
				j++;
			}
			if (tmp > a[j]) break;
			a[k] = a[j];
			k = j;
		}
		a[k] = tmp;
	}
}


class minHeap {
    int size;
    int* arr;
    public:
    minHeap(int s, int* arr) {
        this->size = s;
        this->arr = arr;
        this->buildHeap();
    }
    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }
    void heapify(int i) {
        if (i >= size / 2)
            return;
        int smallest;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        smallest = this->arr[left] < this->arr[i] ? left : i;
        if (right < size)
            smallest = this->arr[right] < this->arr[smallest] ? right : smallest;
        if (smallest != i) {
            int temp = this->arr[i];
            this->arr[i] = arr[smallest];
            arr[smallest] = temp;
            heapify(smallest);
        }
    }
};

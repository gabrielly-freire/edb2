import { defaultCompare } from '../util';
export class MinHeap {
    constructor(compareFn = defaultCompare) {
        this.compareFn = compareFn;
        this.heap = [];
    }

    getLeftIndex(index) {
        return 2 * index + 1;
    }

    getRightIndex(index) {
        return 2 * index + 2;
    }

    getParentIndex(index) {
        if (index === 0) {
            return undefined;

        }
        return Math.floor((index - 1) / 2);
    }

    insert(value) {
        if (value != null) {
            this.heap.push(value); // {1}
            this.siftUp(this.heap.length - 1); // {2}
            return true;
        }
        return false;
    }

    siftUp(index) {
        let parent = this.getParentIndex(index); // {1}
        while (
            index > 0 &&
            this.compareFn(this.heap[parent], this.heap[index]) > Compare.BIGGER_THAN

        ) { // {2}
            swap(this.heap, parent, index); // {3}
            index = parent;
            parent = this.getParentIndex(index); // {4}
        }
    }

    swap(array, a, b) {
        const temp = array[a]; // {5}
        array[a] = array[b]; // {6}
        array[b] = temp; // {7}
    }

    size() {
        return this.heap.length;
    }

    isEmpty() {
        return this.size() === 0;
    }
    findMinimum() {
        return this.isEmpty() ? undefined : this.heap[0]; // {1}
    }
}
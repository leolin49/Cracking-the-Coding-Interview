package main

// @solution-sync:begin
type TripleInOne struct {
	arr 	[]int
	curIdx 	[]int
	size	int
}


func Constructor(stackSize int) TripleInOne {
	t := TripleInOne{
		arr: 	make([]int, stackSize * 3),
		curIdx: make([]int, 3),
		size:   stackSize,
	}
	for i := range t.curIdx {
		t.curIdx[i] = i * stackSize
	}
	return t
}


func (this *TripleInOne) Push(stackNum int, value int)  {
	idx := this.curIdx[stackNum]
	next := (stackNum + 1) * this.size
	if idx < next {
		this.arr[idx] = value
		this.curIdx[stackNum]++
	}
}


func (this *TripleInOne) Pop(stackNum int) int {
	idx := this.curIdx[stackNum]
	begin := stackNum * this.size
	if idx - 1 >= begin {
		this.curIdx[stackNum]--
		return this.arr[idx - 1]
	}
	return -1
}


func (this *TripleInOne) Peek(stackNum int) int {
	idx := this.curIdx[stackNum]
	if this.IsEmpty(stackNum) {
		return -1
	}
	return this.arr[idx - 1]
}


func (this *TripleInOne) IsEmpty(stackNum int) bool {
	return this.curIdx[stackNum] == stackNum * this.size
}


/**
 * Your TripleInOne object will be instantiated and called as such:
 * obj := Constructor(stackSize);
 * obj.Push(stackNum,value);
 * param_2 := obj.Pop(stackNum);
 * param_3 := obj.Peek(stackNum);
 * param_4 := obj.IsEmpty(stackNum);
 */
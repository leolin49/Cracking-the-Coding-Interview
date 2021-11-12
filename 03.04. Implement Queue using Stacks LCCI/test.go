package main

// @solution-sync:begin
type MyQueue struct {
	Stack1	[]int
	Stack2	[]int
}


/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{}
}


/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
	this.Stack1 = append(this.Stack1, x)
}


/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	if len(this.Stack2) == 0 {
		for len(this.Stack1) != 0 {
			val := this.Stack1[len(this.Stack1) - 1]
			this.Stack2 = append(this.Stack2, val)
			this.Stack1 = this.Stack1[:len(this.Stack1) - 1]
		}
	}
	x := this.Stack2[len(this.Stack2) - 1]
	this.Stack2 = this.Stack2[:len(this.Stack2) - 1]
	return x
}


/** Get the front element. */
func (this *MyQueue) Peek() int {
	if len(this.Stack2) != 0 {
		return this.Stack2[len(this.Stack2) - 1]
	}
	return this.Stack1[0]
}


/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return len(this.Stack1) == 0 && len(this.Stack2) == 0
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
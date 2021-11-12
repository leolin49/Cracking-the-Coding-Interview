package main

// @solution-sync:begin
type MinStack struct {
	Stack 	[]int
	Helper	[]int
}


/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}


func (this *MinStack) Push(x int)  {
	this.Stack = append(this.Stack, x)
	if l := len(this.Helper); l == 0 || x <= this.Helper[l - 1] {
		this.Helper = append(this.Helper, x)
	}
}


func (this *MinStack) Pop()  {
	val := this.Stack[len(this.Stack) - 1]
	if val == this.Helper[len(this.Helper) - 1] {
		this.Helper = this.Helper[:len(this.Helper) - 1]
	}
	this.Stack = this.Stack[:len(this.Stack) - 1]
}


func (this *MinStack) Top() int {
	return this.Stack[len(this.Stack) - 1]
}


func (this *MinStack) GetMin() int {
	return this.Helper[len(this.Helper) - 1]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
// url: https://leetcode.com/problems/top-k-frequent-elements/
package main

import (
	"container/heap"
	//"fmt"
)

type Item struct {
	Key   int
	Value uint32
}

type PriorityQueue []Item

func (pq PriorityQueue) Len() int           { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i].Value > pq[j].Value }
func (pq PriorityQueue) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x any) {
	*pq = append(*pq, x.(Item))
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}
func topKFrequent(nums []int, k int) []int {
	var result []int
	frequencyMap := make(map[int]uint32)
	for _, value := range nums {
		frequencyMap[value]++
	}
	pq := make(PriorityQueue, 0, len(frequencyMap))
	heap.Init(&pq)

	for key, value := range frequencyMap {
		heap.Push(&pq, Item{key, value})
	}
	for k != 0 {
		var item Item = heap.Pop(&pq).(Item)
		result = append(result, int(item.Key))
		//fmt.Printf("%d= %d\n", item.Key, item.Value)
		k--

	}
	return result
}

// func main() {
// 	testCases := [][]int{
// 		{1, 1, 1, 2, 2, 3},
// 		{1},
// 		{1, 2, 1, 2, 1, 2, 3, 1, 3, 2}}

// 	testCases2 := []int{2, 1, 2}

// 	for i, testCase := range testCases {
// 		fmt.Println(topKFrequent(testCase, testCases2[i]))
// 	}

// }

package main

//url: https://leetcode.com/problems/product-of-array-except-self/

// import "fmt"

func productExceptSelf(nums []int) []int {

	result := make([]int, len(nums))
	prefix := 1
	postfix := 1
	for i := 0; i < len(nums); i++ {
		result[i] = prefix
		prefix = prefix * nums[i]
	}

	for i := (len(nums) - 1); i >= 0; i-- {
		result[i] = result[i] * postfix
		postfix = postfix * nums[i]
	}
	return result
}

// func main() {
// 	fmt.Println(productExceptSelf([]int{1, 2, 3, 4}))

// }

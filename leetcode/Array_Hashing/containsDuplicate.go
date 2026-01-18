// problem: https://leetcode.com/problems/contains-duplicate
package main

func containsDuplicate(nums []int) bool {

	theMap := make(map[int]bool, len(nums))
	for _, iValue := range nums {
		_, exist := theMap[iValue]
		if exist {
			return true
		} else {
			theMap[iValue] = true
		}
	}
	return false
}

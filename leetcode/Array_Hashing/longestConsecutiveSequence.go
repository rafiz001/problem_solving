// problem: https://leetcode.com/problems/longest-consecutive-sequence
package main

func longestConsecutive(nums []int) int {
	maxLength := 0
	currentLength := 0
	theMap := make(map[int]bool, len(nums))
	for _, value := range nums {
		theMap[value] = true
	}

	for key, val := range theMap {
		if !val {
			continue
		}
		_, preOk := theMap[key-1]
		theMap[key] = false
		if !preOk {
			i := key + 1
			currentLength = 0
			for {
				currentLength += 1
				if currentLength > maxLength {
					maxLength = currentLength
				}
				_, postOk := theMap[i]
				if !postOk {
					break
				}
				i += 1

			}

		}
	}
	return maxLength
}

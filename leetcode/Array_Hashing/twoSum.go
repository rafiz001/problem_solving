package main

func twoSum(nums []int, target int) []int {
	theMap := map[int]int{}
	for index, value := range nums {
		j := target - value
		mapValue, ok := theMap[j]
		if ok {
			return []int{index, mapValue}
		}

		theMap[value] = index

	}
	return []int{}
}

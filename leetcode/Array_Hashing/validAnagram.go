package main

import "fmt"

// problem: https://leetcode.com/problems/valid-anagram
func isAnagram(s string, t string) bool {
	theMap := map[int]int{}

	for _, value := range s {
		count, ok := theMap[int(value)]
		if ok {
			theMap[int(value)] = count + 1
		} else {
			theMap[int(value)] = 1
		}

	}

	for _, value := range t {
		count, ok := theMap[int(value)]
		if ok {
			theMap[int(value)] = count - 1
		} else {
			theMap[int(value)] = -1
		}

	}

	for _, value := range theMap {
		if value != 0 {
			return false
		}
	}
	return true

}

func main() {
	fmt.Print(isAnagram("rrrafiz", "zirfrar"))
}

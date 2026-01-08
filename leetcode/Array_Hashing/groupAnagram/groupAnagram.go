package main

import "fmt"

// problem: https://leetcode.com/problems/group-anagrams/
/*
//brute-force way:
func isValidAnagram(s string, t string) bool {

	theMap := map[rune]int{}

	for _, value := range s {
		theMap[value]++
	}

	for _, value := range t {
		theMap[value]--
	}

	for _, value := range theMap {
		if value != 0 {
			return false
		}
	}

	return true

}

func groupAnagrams(strs []string) [][]string {
	var result [][]string
	removed := make([]bool, len(strs))
	for i := range strs {
		removed[i] = false
	}

	for i, iValue := range strs {
		var tempResult []string
		if removed[i] {
			continue
		}
		tempResult = append(tempResult, iValue)
		removed[i] = true
		for j, jValue := range strs {

			if (!removed[j]) && isValidAnagram(iValue, jValue) {
				tempResult = append(tempResult, jValue)
				removed[j] = true
			}
		}
		result = append(result, tempResult)
	}
	return result
}
*/

func groupAnagrams(strs []string) [][]string {
	resultMap := make(map[[26]byte][]string)

	for _, str := range strs {
		var counter [26]byte
		for _, char := range str {
			counter[char-'a']++
		}
		resultMap[counter] = append(resultMap[counter], str)
	}

	var finalResult [][]string

	for _, element := range resultMap {
		finalResult = append(finalResult, element)
	}
	return finalResult

}
func main() {
	testCases := [][]string{
		{"eat", "tea", "tan", "ate", "nat", "bat"},
		{""},
		{"a"}}
	for _, testCase := range testCases {
		fmt.Println(groupAnagrams(testCase))
	}
}

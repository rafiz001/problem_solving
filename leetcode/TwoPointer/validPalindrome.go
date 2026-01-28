package main

// problem: https://leetcode.com/problems/valid-palindrome/description/
import (
	"strings"
)

func isPalindrome(s string) bool {
	// filtering
	// only letters and numbers
	var letNNum strings.Builder
	for _, v := range s {
		if (v <= 'Z' && v >= 'A') || (v <= 'z' && v >= 'a') || (v <= '9' && v >= '0') {
			if v <= 'Z' && v >= 'A' {
				letNNum.WriteString(string(v + ('a' - 'A')))
			} else {
				letNNum.WriteString(string(v))
			}
		}
	}
	length := letNNum.Len()
	if length == 0 {
		return true
	}
	halfLength := length / 2
	input := letNNum.String()
	result := true
	for i := 0; i <= halfLength; i++ {
		if input[i] != input[length-1-i] {
			result = false
			break
		}
	}

	return result
}

func main() {
	println(isPalindrome("mooma"))
}

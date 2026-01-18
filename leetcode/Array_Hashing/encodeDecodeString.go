// problem: https://neetcode.io/problems/string-encode-and-decode/
package main

import (
	"fmt"
	"strconv"
)

type Solution struct{}

func (s *Solution) Encode(strs []string) string {
	finalString := ""
	for _, value := range strs {
		finalString += strconv.Itoa(len(value)) + ")" + value
	}
	return finalString
}

func (s *Solution) Decode(encoded string) []string {
	var result []string
	var lastLength = ""
	var lastString = ""
	var charNum = -1
	for i, char := range encoded {
		if charNum == -1 {

			if char != ')' {
				lastLength += string(char)
			} else {
				n, _ := strconv.Atoi(lastLength)
				charNum = n + i
				if n == 0 {
					result = append(result, "")
					lastLength = ""
					charNum = -1
				}
			}
		} else {
			lastString += string(char)
			if i == charNum {
				result = append(result, lastString)
				lastString = ""
				lastLength = ""
				charNum = -1
			}

		}
	}
	return result
}
func main() {

	fiz := Solution{}
	encoded := fiz.Encode([]string{"rafiz", "sahi)l", "", "", "uddin", "fiz"})
	decoded := fiz.Decode(encoded)
	fmt.Println(encoded)
	fmt.Println(len(decoded))
	fmt.Println(decoded)

}

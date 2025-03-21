package main

import "fmt"

func check() bool {
	s := "rafizq"
	t := "fizra"
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
	/*
		var fullName int
		fmt.Print("Enter your full name: ")
		fmt.Scanln(&fullName) // Reads until space (stops at first word)
		fmt.Println("Your name:", fullName+30)
	*/
	fmt.Print(check())
}

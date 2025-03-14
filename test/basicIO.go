package main

import "fmt"

func main() {
	var fullName int
	fmt.Print("Enter your full name: ")
	fmt.Scanln(&fullName) // Reads until space (stops at first word)
	fmt.Println("Your name:", fullName+30)
}

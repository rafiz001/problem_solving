// problem: https://leetcode.com/problems/valid-sudoku/
package main

func isValidSudoku(board [][]byte) bool {
	// each row
	for i := 0; i < 9; i++ {
		a := [10]bool{false, false, false, false, false, false, false, false, false, false}
		for j := 0; j < 9; j++ {
			if board[i][j] != '.' {
				index := board[i][j] - '0'
				if a[index] == true {
					return false
				} else {
					a[index] = true
				}

			}
		}
	}
	// each col
	for i := 0; i < 9; i++ {
		a := [10]bool{false, false, false, false, false, false, false, false, false, false}
		for j := 0; j < 9; j++ {
			if board[j][i] != '.' {
				index := board[j][i] - '0'
				if a[index] == true {
					return false
				} else {
					a[index] = true
				}

			}
		}
	}
	// each sub-boxes
	sub := [][][]int{
		{{0, 0}, {2, 2}},
		{{0, 3}, {2, 5}},
		{{0, 6}, {2, 8}},

		{{3, 0}, {5, 2}},
		{{3, 3}, {5, 5}},
		{{3, 6}, {5, 8}},

		{{6, 0}, {8, 2}},
		{{6, 3}, {8, 5}},
		{{6, 6}, {8, 8}},
	}
	for k := 0; k < 9; k++ {
		a := [10]bool{false, false, false, false, false, false, false, false, false, false}
		for i := sub[k][0][0]; i <= sub[k][1][0]; i++ {
			for j := sub[k][0][1]; j <= sub[k][1][1]; j++ {
				if board[j][i] != '.' {
					index := board[j][i] - '0'
					if a[index] == true {
						return false
					} else {
						a[index] = true
					}

				}
			}
		}
	}
	return true
}

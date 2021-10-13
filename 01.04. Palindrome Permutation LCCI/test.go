func canPermutePalindrome(s string) bool {
	m := make(map[rune]int)
	for _, c := range s {
		m[c]++
	}
	x := 0
	for _, v := range m {
		if v&1 != 0 {
			if x++; x >= 2 {
				return false
			}
		}
	}
	return true
}
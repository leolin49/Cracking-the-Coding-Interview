func CheckPermutation(s1 string, s2 string) bool {
	cnt := make(map[byte]int)
	if len(s1) != len(s2) {
		return false
	}
	for i := 0; i < len(s1); i++ {
		cnt[s1[i]]++
		cnt[s2[i]]--
	}
	for _, v := range cnt {
		if v != 0 {
			return false
		}
	}
	return true
}
func compressString(S string) string {
	slen := len(S)
	res := make([]byte,0,slen)
	for i := 0; i < slen; i++ {
		cnt := 1
		for i + 1 < slen && S[i] == S[i + 1] {
			cnt++
			i++
		}
		res = append(res, S[i])
		res = append(res, []byte(strconv.Itoa(cnt))...)
		if len(res) >= slen {
			return S
		}
	}
	return string(res)
}
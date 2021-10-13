func isFlipedString(s1 string, s2 string) bool {
    if len(s1) != len(s2) || !strings.Contains(s2 + s2, s1) {
        return false
    }
    return true
}
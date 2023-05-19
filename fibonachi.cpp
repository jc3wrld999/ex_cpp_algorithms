int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int prev = 0;
    int current = 1;
    int result;

    for (int i = 2; i <= n; ++i) {
        result = prev + current;
        prev = current;
        current = result;
    }

    return result;
}
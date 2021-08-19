void print_subsets(string input, string output) {
    if (input.length() == 0) {
        cout << output << endl;
        return;
    }
    string op_1 = output;
    string op_2 = output;
    op_2.push_back(input[0]);
    input.erase(input.begin() + 0);
    print_subsets(input, op_1);
    print_subsets(input, op_2);
    return;
}

int solve() {
    print_subsets("ab", "");

    return 0;
}

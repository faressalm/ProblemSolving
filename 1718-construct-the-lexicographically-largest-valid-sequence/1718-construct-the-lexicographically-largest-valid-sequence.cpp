class Solution {
  private:
    vector < int > sol;
  public:

    void helper(int size, int index, vector < int > & output, vector < bool > & used) {
      if (sol.size() != 0) return;
      if (size == 0) {
        sol = output;
        return;
      }
      while (index < output.size() && output[index] != 0)
        index++;
      if (index == output.size())
        return;
      for (int i = used.size() - 1; i > 1; i--) {
        if (!used[i] && index + i < output.size() && output[index + i] == 0) {
          used[i] = true;
          output[index] = i;
          output[index + i] = i;

          helper(size - 1, index + 1, output, used);

          output[index] = 0;
          output[index + i] = 0;
          used[i] = false;
        }

      }

      if (!used[1]) {
        used[1] = true;
        output[index] = 1;
        helper(size - 1, index + 1, output, used);
        used[1] = false;
        output[index] = 0;
      }

    }

  vector < int > constructDistancedSequence(int n) {

    vector < int > output(2 * n - 1, 0);
    vector < bool > used(n + 1, false);
    helper(n, 0, output, used);
    return sol;
  }
};
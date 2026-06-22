class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;

    var sortedArr = Arrays.stream(nums)
            .sorted()
            .toArray();

    int sum = 0;
    int left = 0;
    int right = left + 1;
    List<Integer> sequences = new ArrayList<>();

    while (right < sortedArr.length) {
        if (Math.abs(sortedArr[left] - sortedArr[right]) == 1) {
            sum += 1;
        } else if (Math.abs(sortedArr[left] - sortedArr[right]) > 1) {
            sequences.add(sum);
            sum = 0;
        }
        left++;
        right++;
    }

    sequences.add(sum);
    int max = sequences.stream()
            .mapToInt(Integer::intValue)
            .max()
            .orElse(1);
    return max + 1;
    }
}

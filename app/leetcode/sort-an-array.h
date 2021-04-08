// https://leetcode.com/problems/sort-an-array/

// Selection sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (auto iter = begin(nums); iter != end(nums); ++iter) {
            iter_swap(iter, min_element(iter, end(nums)));
        }
        return nums;
    }
};

// Quick sort
class Solution {
public:
    template< class IterT >
    void quick_sort(IterT first, IterT last) {
        if (first == last)
            return;

        // Partitioning. Lomuto’s partition scheme
        const auto pivot = *(last - 1); // pivot element is a last element
        auto bound = std::partition(first, last, [&pivot](const auto& i) { return i < pivot; });
        std::iter_swap(bound, last - 1);

        quick_sort(first, bound);
        quick_sort(bound + 1, last);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(std::begin(nums), std::end(nums));
        return nums;
    }
};

class Solution {
public:
    template< class IterT >
    void quick_sort(IterT first, IterT last) {
        if (first == last)
            return;

        // Partitioning. Hoare partition scheme
        const auto pivot = *(first + (std::distance(first, last) / 2));
        auto bound1 = std::partition(first, last, [&pivot](const auto& i) { return i < pivot; });
        auto bound2 = std::partition(bound1, last, [&pivot](const auto& i) { return !(i > pivot); });

        quick_sort(first, bound1);
        quick_sort(bound2, last);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(std::begin(nums), std::end(nums));
        return nums;
    }
};
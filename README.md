# LeetCode — C++ Solutions

solutions organized by topic, built and tested with [Bazel](https://bazel.build/).

## Build & Test

```sh
# Build everything
./build.sh

# Build a category library (debug)
bazelisk build -c dbg //workspace/src/complicated/dynamic_programming:dynamic_programming

# Run all tests
bazelisk test //workspace/tests/...

# Run tests for one category
bazelisk test //workspace/tests/complicated/dynamic_programming:dp_test
```

## Structure

```
workspace/
  src/        # Solution implementations (.cpp)
  tests/      # Catch2 test files
```

## Topics

### 1. Data Structure

| Category | Files |
|---|---|
| Array & String | `two_sum`, `three_sum`, `product_except_self`, `spiral_order`, `rotate_image`, `set_zeroes`, `median_of_arrays`, `contains_duplicate`, `four_sum_count`, `my_pow`, `my_sqrt`, `count_primes`, `trailing_zeroes`, `fraction_to_decimal`, `roman_to_int`, `title_to_number`, `plus_one`, `fizz_buzz`, `is_happy`, `is_power_of_three`, `is_valid_sudoku`, `rotate`, `shuffle_array`, `intersect`, `increasing_triplet`, `max_sum_of_three_subarrays`, `num_pairs_divisible_by60`, `longest_alternating_subarray`, `row_and_maximum_ones`, `maximize_sum`, `max_count`, `similar_pairs`, `solution_802` + utilities |
| Linked List | `reverse_list`, `has_cycle`, `merge_two_lists`, `remove_nth_from_end`, `add_two_numbers`, `delete_node`, `is_palindrome`, `copy_list_with_random_pointer` (LC 138) |
| Stack & Queue | `is_valid`, `min_stack`, `eval_rpn` |
| Hash Map/Set | `group_anagrams`, `randomized_set`, `lru_cache` (LC 146), `longest_consecutive_sequence` (LC 128), `design_hashset` (LC 705) |
| Heap | `find_kth_largest`, `top_k_frequent`, `least_interval` |
| Trie | `trie` |
| Union Find | `union_find` |
| Tree | `max_depth`, `is_symmetric`, `level_order`, `inorder_traversal`, `is_valid_bst`, `sorted_array_to_bst`, `serialize_and_deserialize` |
| Graph | `graph`, `minimize_malware_spread` (LC 924) |

### 2. Skills

| Category | Files |
|---|---|
| Two Pointers | `move_zeros`, `remove_duplicates`, `three_sum`, `four_sum` (LC 18) |
| Sliding Window | `length_of_longest_substring`, `sliding_window_1052` |
| Binary Search | `search`, `search_range`, `search_matrix`, `find_peak_element`, `first_bad_version` |
| Prefix Sum | `prefix_sum` |
| String Algorithm | `reverse_string`, `longest_palindrome`, `longest_substring` |
| Bit Manipulation | `single_number`, `single_number_ii` (LC 137), `hamming_weight`, `hamming_distance`, `reverse_bits`, `missing_number`, `get_sum` |

### 3. Search

| Category | Files |
|---|---|
| BFS | `bfs` |
| DFS | `dfs` |
| Backtracking | `subsets`, `permute`, `generate_parenthesis`, `letter_combinations`, `exist`, `n_queens`, `subset_sum`, `sudoku_solver` (LC 37) |
| Tree Traversal | `tree_traversal` |
| Shortest Path | `shortest_path`, `design_graph_with_shortest_path_calculator` (LC 2642) |
| Interval | `merge`, `merge_intervals` (LC 56), `count_ways_to_group_overlapping_ranges` (LC 2580) |

### 4. Complicated

| Category | Files |
|---|---|
| Dynamic Programming | `climb_stairs`, `unique_paths`, `max_sub_array`, `max_profit`, `rob`, `coin_change`, `coin_change_322`, `combination_sum_iv` (LC 377), `length_of_lis`, `longest_common_subsequence` (LC 1143), `can_jump`, `generate`, `subset_sum` |
| Greedy | `greedy` |
| Divide and Conquer | `divide_and_conquer` |
| Monotonic Stack | `monotonic_stack` |
| Topological Sort | `topological_sort` |
| Sort | `sort`, `sort_colors`, `majority_element` |

## Conventions

- One problem per `.cpp` file, flat under the category directory
- File names: `lc_<id>_<slug>.cpp` for numbered LeetCode problems, `<slug>.cpp` otherwise
- Each file uses a unique `namespace ns_<category>_<slug>`
- Tests use [Catch2](https://github.com/catchorg/Catch2) and live under `workspace/tests/` mirroring `workspace/src/`

/*# Aggressive Cows (Binary Search)
## Problem Statement
Given the positions of `N` stalls and `C` cows, place the cows in the stalls such that the **minimum distance between any two cows is as large as possible**.

## Approach

### Step 1: Sort the Stalls

Sort the stall positions in ascending order.

```cpp
sort(arr.begin(), arr.end());
```

This ensures that cows are placed from left to right.

---

### Step 2: Binary Search on the Answer

Instead of searching for the positions directly, we binary search on the **minimum distance** between cows.

- **Start (`st`)** = 1
- **End (`end`)** = Maximum possible distance

```cpp
st = 1;
end = arr[N - 1] - arr[0];
```

---

### Step 3: Check Feasibility

For every middle value (`mid`), check whether it is possible to place all cows while maintaining at least `mid` distance between every pair of cows.

Algorithm:

1. Place the first cow in the first stall.
2. Traverse the remaining stalls.
3. If the distance from the last placed cow is at least `mid`, place another cow.
4. If all cows are placed successfully, return `true`; otherwise, return `false`.

---

### Step 4: Binary Search Decisions

- If placing all cows is **possible**, save the answer and search for a **larger minimum distance**.

```cpp
ans = mid;
st = mid + 1;
```

- Otherwise, search for a **smaller minimum distance**.

```cpp
end = mid - 1;
```

Continue until `st > end`.

---

## Example

### Input

```text
Stalls = [1, 2, 8, 4, 9]
Cows = 3
```

After sorting:

```text
[1, 2, 4, 8, 9]
```

### Binary Search

| st | end | mid | Possible? | Answer |
|----|-----|-----|-----------|--------|
| 1 | 8 | 4 | ❌ No | - |
| 1 | 3 | 2 | ✅ Yes | 2 |
| 3 | 3 | 3 | ✅ Yes | 3 |

Final Answer:

```text
3
```

One optimal placement is:

```text
Cow 1 → 1
Cow 2 → 4
Cow 3 → 8
```

Minimum distance:

```text
min(4-1, 8-4) = 3
```

---

## Time Complexity

- Sorting: **O(N log N)**
- Binary Search: **O(log D)**
- Feasibility Check: **O(N)**

Overall Complexity:

```text
O(N log N + N log D)
```

where

- `N` = Number of stalls
- `D` = Maximum possible distance (`maxPosition - minPosition`)

---

## Space Complexity

```text
O(1)
```

(Excluding the input array.)

---

## Key Idea

Instead of searching for the correct stall positions, binary search is performed on the **answer (minimum distance)**.

- If a distance is possible, try a larger one.
- If it is not possible, try a smaller one.

This "Binary Search on Answer" technique efficiently finds the maximum possible minimum distance.*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ispossible(vector<int> &arr, int N, int C, int minAD) {
    int cows = 1;
    int stalls = arr[0];

    for (int i = 1; i < N; i++) {
        if (arr[i] - stalls >= minAD) {
            cows++;
            stalls = arr[i];
        }

        if (cows == C)
            return true;
    }

    return false;
}

int mindistance(vector<int> &arr, int N, int C) {
    sort(arr.begin(), arr.end());

    int ans = -1;
    int st = 1;
    int end = arr[N - 1] - arr[0];

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (ispossible(arr, N, C, mid)) {
            ans = mid;
            st = mid + 1;      // Search for a larger minimum distance
        } else {
            end = mid - 1;     // Search for a smaller minimum distance
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 8, 4, 9};
    int N = 5;
    int C = 3;

    cout << mindistance(arr, N, C) << endl;

    return 0;
}
